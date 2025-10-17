#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "QuanLyHangHoa.h"
#include "QuanLyNguoiDung.h"
#include "QuanLyNhaCungCap.h"
#include "QuanLyPhieu.h"
#include <string>
using namespace std;

class FileManager {
  private:
    const string hangHoaFile = "hanghoa.csv";
    const string nccFile = "nhacungcap.csv";
    const string phieuNhapFile = "phieunhap.csv";
    const string phieuXuatFile = "phieuxuat.csv";
    const string nguoiDungFile = "nguoidung.csv";

    void docHangHoa(QuanLyHangHoa &qlhh);
    void docNhaCungCap(QuanLyNhaCungCap &qlncc);
    void docPhieuNhap(QuanLyPhieu &qlpn);
    void docPhieuXuat(QuanLyPhieu &qlpx);
    bool docNguoiDung(QuanLyNguoiDung &qlnd, const string &filename);

    void ghiHangHoa(const QuanLyHangHoa &qlhh);
    void ghiNhaCungCap(const QuanLyNhaCungCap &qlncc);
    void ghiPhieuNhap(const QuanLyPhieu &qlpn);
    void ghiPhieuXuat(const QuanLyPhieu &qlpx);
    void ghiNguoiDung(const QuanLyNguoiDung &qlnd);

  public:
    void docTatCaDuLieu(QuanLyHangHoa &qlhh, QuanLyNhaCungCap &qlncc,
                        QuanLyPhieu &qlpn, QuanLyNguoiDung &qlnd);

    void ghiTatCaDuLieu(const QuanLyHangHoa &qlhh,
                        const QuanLyNhaCungCap &qlncc,
                        const QuanLyNguoiDung &qlnd);
    friend
};

#endif
