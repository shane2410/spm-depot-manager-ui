#include "../backend_headers/QuanLyNguoiDung.h"

QuanLyNguoiDung::QuanLyNguoiDung() {}
QuanLyNguoiDung::~QuanLyNguoiDung() {}
bool QuanLyNguoiDung::themnguoidung(const NguoiDung &nd) {
    if (timNguoiDung(nd.getTenDangNhap()))
        return false;
    dsnguoidung.addLast(nd);
    return true;
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

NguoiDung *QuanLyNguoiDung::timNguoiDung(const string &tenDN) {
    NguoiDung temp;
    temp.setTenDN(tenDN);
    return dsnguoidung.find(temp);
}

bool QuanLyNguoiDung::xoaNguoiDung(const string &tenDN) {
    return dsnguoidung.deletebyCond(
        [](const NguoiDung &nd, const string &key) {
            return nd.getTenDangNhap() == key;
        },
        tenDN);
}

bool QuanLyNguoiDung::capNhatNguoiDung(const NguoiDung &nd) {
    NguoiDung *ndToUpdate =
        dsnguoidung.find(NguoiDung(nd.getTenDangNhap(), "", "", ""));
    if (ndToUpdate) {
        *ndToUpdate = nd;
        return true;
    }
    return false;
}