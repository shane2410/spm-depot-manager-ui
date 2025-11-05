#ifndef phieu_h
#define phieu_h
#include "Date.h"
#include "LinkedList.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct ChitietPhieuNhap {
    string maHH;
    int soLuong;
    double donGiaNhap;
    ChitietPhieuNhap(string ma = "", int sl = 0, double gia = 0)
        : maHH(ma), soLuong(sl), donGiaNhap(gia) {}
    bool operator==(const ChitietPhieuNhap& other) const {
        return this->maHH == other.maHH;
    }

    bool operator!=(const ChitietPhieuNhap& other) const {
        return !(*this == other);
    }
};

struct ChitietPhieuXuat {
    string maHH;
    int soLuong;
    double donGiaBan;
    ChitietPhieuXuat(string ma = "", int sl = 0, double gia = 0)
        : maHH(ma), soLuong(sl), donGiaBan(gia) {}
    bool operator==(const ChitietPhieuXuat& other) const {
        return this->maHH == other.maHH;
    }

    bool operator!=(const ChitietPhieuXuat& other) const {
        return !(*this == other);
    }
};

class PhieuNhap {
  private:
    string maPhieuNhap;
    Date ngayNhap;
    string maNCC;
    LinkedList<ChitietPhieuNhap> dsCTPN;
    double thanhTien;

  public:
    PhieuNhap();
    ~PhieuNhap();
    PhieuNhap(const string &maPhieuNhap, const Date &ngayNhap,
              const string &maNCC);
    string getMaPhieuNhap() const;
    Date getNgayNhap() const;
    string getMaNCC() const;
    double getThanhTien() const;
    void setMaPhieuNhap(const string &mapn);
    void setNgayNhap(const Date &ngay);
    void setMaNCC(const string &mancc);
    void setDSHangNhap(const LinkedList<ChitietPhieuNhap>& ds);
    const LinkedList<ChitietPhieuNhap> &getDsCTPN() const;
    void tinhThanhtien();
    friend ostream &operator<<(ostream &os, const PhieuNhap pn);
    string getKey() const;
    void themChiTiet(const ChitietPhieuNhap &ctpn);
    bool operator==(const PhieuNhap& other) const;
    bool operator!=(const PhieuNhap& other) const;
};

class PhieuXuat {
  private:
    string maPhieuXuat;
    Date ngayXuat;
    string TenKH;
    LinkedList<ChitietPhieuXuat> dsCTPX;
    double thanhTien;

  public:
    PhieuXuat();
    ~PhieuXuat();
    PhieuXuat(const string &maPhieu, const Date &ngay, const string &TenKH);
    string getMaPhieuXuat() const;
    Date getNgayXuat() const;
    string getTenKH() const;
    double getThanhTien() const;
    void setMaPhieuXuat(const string &mapx);
    void setNgayXuat(const Date &ngay);
    void setTenKH(const string &ten);
    void setDSHangXuat(const LinkedList<ChitietPhieuXuat>& ds);
    const LinkedList<ChitietPhieuXuat> &getDsCTPX() const;
    void tinhThanhtien();
    friend ostream &operator<<(ostream &os, const PhieuXuat px);
    string getKey() const;
    void themChiTiet(const ChitietPhieuXuat &ctpx);
    bool operator==(const PhieuXuat& other) const ;
    bool operator!=(const PhieuXuat& other) const;
};

#endif
