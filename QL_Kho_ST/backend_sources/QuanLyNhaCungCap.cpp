#include "../backend_headers/QuanLyNhaCungCap.h"

QuanLyNhaCungCap::QuanLyNhaCungCap() {}
QuanLyNhaCungCap::~QuanLyNhaCungCap() {}

bool QuanLyNhaCungCap::themNhaCungCap(const NhaCungCap &ncc) {
    if (timKiemNhaCungCap(ncc.getMaNCC()) != nullptr)
        return false;
    dsNhaCungCap.addLast(ncc);
    return true;
}

bool QuanLyNhaCungCap::capNhatNhaCungCap(const NhaCungCap &ncc) {
    NhaCungCap *nccToUpdate = timKiemNhaCungCap((ncc.getMaNCC()));
    if (nccToUpdate) {
        *nccToUpdate = ncc;
        return true;
    }
    return false;
}

bool QuanLyNhaCungCap::xoaNhaCungCap(const string &maNCC) {
    NhaCungCap temp;
    temp.setMaNCC(maNCC);
    return dsNhaCungCap.remove(temp);
}
NhaCungCap *QuanLyNhaCungCap::timKiemNhaCungCap(const string &maNCC) {
    NhaCungCap temp;
    temp.setMaNCC(maNCC);
    return dsNhaCungCap.find(temp);
}

const LinkedList<NhaCungCap> &QuanLyNhaCungCap::getDanhSach() const {
    return dsNhaCungCap;
}
