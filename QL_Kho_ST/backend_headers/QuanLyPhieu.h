#ifndef QuanLyPhieu_h
#define QuanLyPhieu_h
#include "Date.h"
#include "LinkedList.h"
#include "Phieu.h"
class QuanLyPhieu {
  private:
    LinkedList<ChitietPhieuNhap> dsPhieuNhap;
    LinkedList<ChitietPhieuXuat> dsPhieuXuat;

  public:
    QuanLyPhieu();
    ~QuanLyPhieu();
    void taoPhieuNhap(const PhieuNhap &pn);
    void taoPhieuXuat(const PhieuXuat &px);
    void hienThiDshPhieuNhap() const;
    void hienThiDsPhieuXuat() const;
    void timPhieuNhap() const;
    void timPhieuXuat() const;
    void thongKeDoanhThu(const Date &from, const Date &to) const;
};
#endif