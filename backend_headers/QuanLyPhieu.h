// backend_headers/QuanLyPhieu.h
#ifndef QUANLYPHIEU_H
#define QUANLYPHIEU_H

#include "Date.h"
#include "LinkedList.h"
#include "Phieu.h"
#include "QuanLyHangHoa.h"
#include <string>

class QuanLyPhieu : public PhieuNhap, public PhieuXuat {
  private:
    LinkedList<PhieuNhap> dsPhieuNhap;
    LinkedList<PhieuXuat> dsPhieuXuat;

  public:
    QuanLyPhieu();
    ~QuanLyPhieu();
    void themPhieuNhap(const PhieuNhap &pn);
    void themPhieuXuat(const PhieuXuat &px);
    bool taoPhieuNhap(const PhieuNhap &pn, QuanLyHangHoa &qlhh);
    bool taoPhieuXuat(const PhieuXuat &px, QuanLyHangHoa &qlhh);
    PhieuNhap *timPhieuNhap(const string &maPhieu);
    PhieuXuat *timPhieuXuat(const string &maPhieu);
    void tinhTongTien();

    const LinkedList<PhieuNhap> &getDanhSachPhieuNhap() const;
    const LinkedList<PhieuXuat> &getDanhSachPhieuXuat() const;

    double thongKeDoanhThu(const Date &tuNgay, const Date &denNgay) const;


};

#endif // QUANLYPHIEU_H
