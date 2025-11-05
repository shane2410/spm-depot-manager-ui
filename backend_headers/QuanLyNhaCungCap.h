// backend_headers/QuanLyNhaCungCap.h
#ifndef QUANLYNHACUNGCAP_H
#define QUANLYNHACUNGCAP_H

#include "LinkedList.h"
#include "NhaCungCap.h"
#include <string>

class QuanLyNhaCungCap {
  private:
    LinkedList<NhaCungCap> dsNhaCungCap;

  public:
    QuanLyNhaCungCap();
    ~QuanLyNhaCungCap();

    bool themNhaCungCap(const NhaCungCap &ncc);

    bool capNhatNhaCungCap(const NhaCungCap &ncc);

    bool xoaNhaCungCap(const string &maNCC);
    NhaCungCap *timKiemNhaCungCap(const string &maNCC);

    const LinkedList<NhaCungCap> &getDanhSach() const;

};

#endif // QUANLYNHACUNGCAP_H
