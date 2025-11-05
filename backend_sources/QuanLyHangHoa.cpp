#include "../backend_headers/QuanLyHangHoa.h"

QuanLyHangHoa::QuanLyHangHoa() {}
QuanLyHangHoa::~QuanLyHangHoa() {}

bool QuanLyHangHoa::themHangHoa(const HangHoa &hh) {
    if (layHangHoaTheoMa(hh.getMaHH()) != nullptr) {
        return false;
    }
    dsHangHoa.addLast(hh);
    return true;
}

bool QuanLyHangHoa::capNhatHangHoa(const HangHoa &hh) {
    HangHoa *hhToUpdate = layHangHoaTheoMa(hh.getMaHH());
    if (hhToUpdate) {
        *hhToUpdate = hh;
        return true;
    }
    return false;
}

bool QuanLyHangHoa::xoaHangHoa(const std::string &maHH) {
    HangHoa temp;
    temp.setMaHH(maHH);
    return dsHangHoa.remove(temp);
}

HangHoa *QuanLyHangHoa::layHangHoaTheoMa(const std::string &maHH) {
    HangHoa temp;
    temp.setMaHH(maHH);
    return dsHangHoa.find(temp);
}

const LinkedList<HangHoa> &QuanLyHangHoa::getDanhSach() const {
    return dsHangHoa;
}

void QuanLyHangHoa::baocaotonkho() {}
void QuanLyHangHoa::baocaosaphethang() {}
