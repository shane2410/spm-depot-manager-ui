#ifndef QuanLyNguoiDung_h
#define QuanLyNguoiDung_h
#include "LinkedList.h"
#include "NguoiDung.h"
using namespace std;
class QuanLyNguoiDung {
    LinkedList<NguoiDung> dsnguoidung;

  public:
    QuanLyNguoiDung();
    ~QuanLyNguoiDung();
    void themnguoidung(const NguoiDung &nd);
    QuanLyNguoiDung(const QuanLyNguoiDung &) = delete;
    QuanLyNguoiDung &operator=(const QuanLyNguoiDung &) = delete;
    const NguoiDung *kiemtradangnhap(const string &tenDN,
                                     const string &mk) const;
    const LinkedList<NguoiDung> &laydanhsachnguoidung() const;
};
#endif
