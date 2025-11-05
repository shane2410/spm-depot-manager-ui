#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Date.h"
#include <QDir>
#include "QuanLyHangHoa.h"
#include "QuanLyNguoiDung.h"
#include "QuanLyNhaCungCap.h"
#include "QuanLyPhieu.h"
#include <string>
using namespace std;

class FileManager {
  private:
    string getDataPath() {
        return QDir(PROJECT_SOURCE_DIR).filePath("Data").toStdString();
    }
    const string hangHoaFile = getDataPath()+"/hanghoa";
    const string nccFile = getDataPath()+"/nhacungcap";
    const string phieuNhapFile = getDataPath()+"/phieunhap";
    const string phieuXuatFile = getDataPath()+"/phieuxuat";
    const string nguoiDungFile = getDataPath()+"/nguoidung";
    const string CTPNFile = getDataPath()+"/chitietphieunhap";
    const string CTPXFile = getDataPath()+"/chitietphieuxuat";
    static void initFirstRun();

  public:
    static bool isFirstRun();
    bool docHangHoa(QuanLyHangHoa &qlhh);
    bool docNhaCungCap(QuanLyNhaCungCap &qlncc);
    bool docCTPhieuNhap(QuanLyPhieu &qlpn);
    bool docCTPhieuXuat(QuanLyPhieu &qlpx);
    bool docPhieuNhap(QuanLyPhieu &qlpn);
    bool docPhieuXuat(QuanLyPhieu &qlpx);
    bool docNguoiDung(QuanLyNguoiDung &qlnd);

    void ghiHangHoa(const QuanLyHangHoa &qlhh);
    void ghiNhaCungCap(const QuanLyNhaCungCap &qlncc);
    void ghiPhieuNhap(const QuanLyPhieu &qlpn);
    void ghiPhieuXuat(const QuanLyPhieu &qlpx);
    void ghiNguoiDung(const QuanLyNguoiDung &qlnd);

    void docTatCaDuLieu(QuanLyHangHoa &qlhh, QuanLyNhaCungCap &qlncc,
                        QuanLyPhieu &qlpn, QuanLyNguoiDung &qlnd);

    void ghiTatCaDuLieu(const QuanLyHangHoa &qlhh,
                        const QuanLyNhaCungCap &qlncc, const QuanLyPhieu &qlp,
                        const QuanLyNguoiDung &qlnd);
    friend const string STATIC_NGUOIDUNG_FILE(const FileManager& fm);
};

#endif
