// backend_headers/QuanLyPhieu.h
#ifndef QUANLYPHIEU_H
#define QUANLYPHIEU_H

#include "Date.h"
#include "LinkedList.h"
#include "Phieu.h"
#include "QuanLyHangHoa.h"
#include <string>

class QuanLyPhieu {
private:
    LinkedList<PhieuNhap> dsPhieuNhap;
    LinkedList<PhieuXuat> dsPhieuXuat;

public:
    QuanLyPhieu();
    ~QuanLyPhieu();

    bool taoPhieuNhap(const PhieuNhap &pn, QuanLyHangHoa &qlhh);

    bool taoPhieuXuat(const PhieuXuat &px, QuanLyHangHoa &qlhh);
    PhieuNhap *timPhieuNhap(const string &maPhieu);
    PhieuXuat *timPhieuXuat(const string &maPhieu);
    const LinkedList<PhieuNhap> &getDanhSachPhieuNhap() const;
    const LinkedList<PhieuXuat> &getDanhSachPhieuXuat() const;

    double thongKeDoanhThu(const Date &tuNgay, const Date &denNgay) const;

    bool khoiTaoDuLieu(const string &filePhieuNhap,
                       const string &filePhieuXuat);
};

#endif // QUANLYPHIEU_H
