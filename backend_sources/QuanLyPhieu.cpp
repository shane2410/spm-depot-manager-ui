#include "../backend_headers/QuanLyPhieu.h"

QuanLyPhieu::QuanLyPhieu() {}
QuanLyPhieu::~QuanLyPhieu() {}
void QuanLyPhieu::themPhieuNhap(const PhieuNhap &pn) {
    dsPhieuNhap.addLast(pn);
}
void QuanLyPhieu::themPhieuXuat(const PhieuXuat &px) {
    dsPhieuXuat.addLast(px);
}
bool QuanLyPhieu::taoPhieuNhap(const PhieuNhap &pn, QuanLyHangHoa &qlhh) {
    if (timPhieuNhap(pn.getMaPhieuNhap()) != nullptr) {
        return false;
    }

    const LinkedList<ChitietPhieuNhap> &chiTiet = pn.getDsCTPN();
    Node<ChitietPhieuNhap> *ct_node_kiemtra = chiTiet.getHead();
    while (ct_node_kiemtra != nullptr) {
        if (qlhh.layHangHoaTheoMa(ct_node_kiemtra->data.maHH) == nullptr) {
            return false;
        }
        ct_node_kiemtra = ct_node_kiemtra->pNext;
    }

    Node<ChitietPhieuNhap> *ct_node_capnhat = chiTiet.getHead();
    while (ct_node_capnhat != nullptr) {
        HangHoa *hh_ptr = qlhh.layHangHoaTheoMa(ct_node_capnhat->data.maHH);
        int soLuongHienTai = hh_ptr->getSoLuongTon();
        hh_ptr->setSoLuongTon(soLuongHienTai + ct_node_capnhat->data.soLuong);
        ct_node_capnhat = ct_node_capnhat->pNext;
    }

    this->themPhieuNhap(pn);
    return true;
}
bool QuanLyPhieu::taoPhieuXuat(const PhieuXuat &px, QuanLyHangHoa &qlhh) {
    if (timPhieuXuat(px.getMaPhieuXuat()) != nullptr) {
        return false;
    }

    const LinkedList<ChitietPhieuXuat> &chiTiet = px.getDsCTPX();
    Node<ChitietPhieuXuat> *ct_node_kiemtra = chiTiet.getHead();
    while (ct_node_kiemtra != nullptr) {
        HangHoa *hh_ptr = qlhh.layHangHoaTheoMa(ct_node_kiemtra->data.maHH);
        if (hh_ptr == nullptr ||
            hh_ptr->getSoLuongTon() < ct_node_kiemtra->data.soLuong) {
            return false;
        }
        ct_node_kiemtra = ct_node_kiemtra->pNext;
    }

    Node<ChitietPhieuXuat> *ct_node_capnhat = chiTiet.getHead();
    while (ct_node_capnhat != nullptr) {
        HangHoa *hh_ptr = qlhh.layHangHoaTheoMa(ct_node_capnhat->data.maHH);
        int soLuongHienTai = hh_ptr->getSoLuongTon();
        hh_ptr->setSoLuongTon(soLuongHienTai - ct_node_capnhat->data.soLuong);
        ct_node_capnhat = ct_node_capnhat->pNext;
    }

    this->themPhieuXuat(px);
    return true;
}
PhieuNhap *QuanLyPhieu::timPhieuNhap(const string &maPhieu) {
    PhieuNhap temp;
    temp.setMaPhieuNhap(maPhieu);
    return dsPhieuNhap.find(temp);
}
PhieuXuat *QuanLyPhieu::timPhieuXuat(const string &maPhieu) {
    PhieuXuat temp;
    temp.setMaPhieuXuat(maPhieu);
    return dsPhieuXuat.find(temp);
}
void QuanLyPhieu::tinhTongTien() {
    Node<PhieuNhap> *pn_node = dsPhieuNhap.getHead();
    while (pn_node != nullptr) {
        pn_node->data.tinhThanhtien();
        pn_node = pn_node->pNext;
    }

    Node<PhieuXuat> *px_node = dsPhieuXuat.getHead();
    while (px_node != nullptr) {
        px_node->data.tinhThanhtien();
        px_node = px_node->pNext;
    }
}

const LinkedList<PhieuNhap> &QuanLyPhieu::getDanhSachPhieuNhap() const {
    return dsPhieuNhap;
}
const LinkedList<PhieuXuat> &QuanLyPhieu::getDanhSachPhieuXuat() const {
    return dsPhieuXuat;
}

double QuanLyPhieu::thongKeDoanhThu(const Date &tuNgay,
                                    const Date &denNgay) const {
    double totalRevenue = 0.0;
    Node<PhieuXuat> *current = dsPhieuXuat.getHead();
    while (current != nullptr) {
        Date ngayXuat = current->data.getNgayXuat();
        if (ngayXuat >= tuNgay && ngayXuat <= denNgay) {
            totalRevenue += current->data.getThanhTien();
        }
        current = current->pNext;
    }
    return totalRevenue;
}
