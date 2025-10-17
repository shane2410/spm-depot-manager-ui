
#ifndef QuanLyHangHoa_h
#define QuanLyHangHoa_h
#include "HangHoa.h"
#include "LinkedList.h"

class QuanLyHangHoa {
  private:
    LinkedList<HangHoa> listHangHoa;

  public:
    QuanLyHangHoa();
    ~QuanLyHangHoa();
    void themHangHoa(const HangHoa &hh);
    void hienThiDanhSach() const;
    void capNhatHangHoa();
    bool xoaHangHoa(const string &maHH);
    void timKiemHangHoa() const;
    Node<HangHoa> *layHangHoaTheoMa(const string &maHH) const;
    void baoCaoTonKho() const;
    void baoCaoSapHetHang() const;
    void baoCaoHangHetHan() const;
};
#endif
