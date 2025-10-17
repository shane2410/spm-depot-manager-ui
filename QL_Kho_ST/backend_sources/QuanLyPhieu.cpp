#ifndef QuanLyPhieu_h
#define QuanLyPhieu_h
#include "../backend_headers/Date.h"
#include "../backend_headers/LinkedList.h"
#include "../backend_headers/Phieu.h"
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
