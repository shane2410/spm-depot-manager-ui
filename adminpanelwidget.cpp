#include "adminpanelwidget.h"
#include "ui_adminpanelwidget.h"
#include "userdialog.h"
#include <QMessageBox>

AdminPanelWidget::AdminPanelWidget(QuanLyNguoiDung &qlnd,
                                   const NguoiDung *currentUser,
                                   QWidget *parent)
    : QWidget(parent), ui(new Ui::AdminPanelWidget), m_qlnd_ref(qlnd),
      m_currentUser(currentUser) {
    ui->setupUi(this);

    ui->userTable->horizontalHeader()->setStretchLastSection(true);
    connect(ui->userTable, &QTableWidget::itemSelectionChanged, this,
            &AdminPanelWidget::updateUserActionsState);

    loadUserTable();
    updateUserActionsState();
}

AdminPanelWidget::~AdminPanelWidget() { delete ui; }

void AdminPanelWidget::loadUserTable() {
    ui->userTable->setRowCount(0);
    const LinkedList<NguoiDung> &dsnd = m_qlnd_ref.laydanhsachnguoidung();
    Node<NguoiDung> *current = dsnd.getHead();
    while (current != nullptr) {
        int row = ui->userTable->rowCount();
        ui->userTable->insertRow(row);
        ui->userTable->setItem(row, 0,
                               new QTableWidgetItem(QString::fromStdString(
                                   current->data.getTenDangNhap())));
        ui->userTable->setItem(row, 1,
                               new QTableWidgetItem(QString::fromStdString(
                                   current->data.getHoTen())));
        ui->userTable->setItem(row, 2,
                               new QTableWidgetItem(QString::fromStdString(
                                   current->data.getVaiTro())));
        current = current->pNext;
    }
}

void AdminPanelWidget::on_addUserButton_clicked() {
    UserDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        NguoiDung newUser = dialog.getUserData();
        if (m_qlnd_ref.themnguoidung(newUser)) {
            loadUserTable();
            QMessageBox::information(this, "Thành công",
                                     "Đã thêm người dùng mới.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Tên đăng nhập đã tồn tại.");
        }
    }
}

void AdminPanelWidget::on_editUserButton_clicked() {
    int currentRow = ui->userTable->currentRow();
    if (currentRow < 0)
        return;

    std::string username =
        ui->userTable->item(currentRow, 0)->text().toStdString();
    NguoiDung *userToEdit = m_qlnd_ref.timNguoiDung(username);

    if (userToEdit) {
        UserDialog dialog(*userToEdit, this);
        if (dialog.exec() == QDialog::Accepted) {
            NguoiDung updatedUser = dialog.getUserData();
            if (m_qlnd_ref.capNhatNguoiDung(updatedUser)) {
                loadUserTable();
                QMessageBox::information(this, "Thành công",
                                         "Đã cập nhật thông tin người dùng.");
            } else {
                QMessageBox::warning(this, "Thất bại",
                                     "Không thể cập nhật người dùng.");
            }
        }
    }
}

void AdminPanelWidget::on_deleteUserButton_clicked() {
    int currentRow = ui->userTable->currentRow();
    if (currentRow < 0)
        return;

    std::string username =
        ui->userTable->item(currentRow, 0)->text().toStdString();

    if (m_currentUser && m_currentUser->getTenDangNhap() == username) {
        QMessageBox::critical(this, "Lỗi",
                              "Bạn không thể xóa chính tài khoản của mình.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this, "Xác nhận xóa",
        QString("Bạn có chắc chắn muốn xóa người dùng '%1'?")
            .arg(QString::fromStdString(username)),
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (m_qlnd_ref.xoaNguoiDung(username)) {
            loadUserTable();
            QMessageBox::information(this, "Thành công", "Đã xóa người dùng.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Không thể xóa người dùng.");
        }
    }
}

void AdminPanelWidget::updateUserActionsState() {
    bool hasSelection = ui->userTable->selectionModel()->hasSelection();
    ui->editUserButton->setEnabled(hasSelection);
    ui->deleteUserButton->setEnabled(hasSelection);
}
