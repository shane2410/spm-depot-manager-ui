#include "../backend_headers/QuanLyNguoiDung.h"

QuanLyNguoiDung::QuanLyNguoiDung() {}
QuanLyNguoiDung::~QuanLyNguoiDung() {}
void QuanLyNguoiDung::themnguoidung(const NguoiDung &nd) {
    dsnguoidung.addLast(nd);
}

const NguoiDung *QuanLyNguoiDung::kiemtradangnhap(const string &tenDN,
                                                  const string &mk) const {
    Node<NguoiDung> *current = dsnguoidung.getHead();
    while (current != nullptr) {
        if (current->data.getTenDangNhap() == tenDN &&
            current->data.getMatKhau() == mk) {
            return &current->data;
        }
        current = current->pNext;
    }
    return nullptr;
}
const LinkedList<NguoiDung> &QuanLyNguoiDung::laydanhsachnguoidung() const {
    return dsnguoidung;
}
