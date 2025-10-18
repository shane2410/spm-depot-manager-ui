// backend_headers/QuanLyHangHoa.h
#ifndef QUANLYHANGHOA_H
#define QUANLYHANGHOA_H

#include "HangHoa.h"
#include "LinkedList.h"
#include <string>

class QuanLyHangHoa {
private:
    LinkedList<HangHoa> dsHangHoa;

public:
    QuanLyHangHoa();
    ~QuanLyHangHoa();

    bool themHangHoa(const HangHoa &hh);

    bool capNhatHangHoa(const HangHoa &hh);

    bool xoaHangHoa(const string &maHH);
    HangHoa *layHangHoaTheoMa(const string &maHH);

    const LinkedList<HangHoa> &getDanhSach() const;

    void baocaotonkho();
    void baocaosaphethang();

    bool khoiTaoDuLieu(const string &tenFile);
};

#endif // QUANLYHANGHOA_H
