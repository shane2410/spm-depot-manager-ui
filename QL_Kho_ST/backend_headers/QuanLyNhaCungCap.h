#ifndef QuanLyNhaCungCap_h
#define QuanLyNhaCungCap_h
#include "LinkedList.h"
#include "NhaCungCap.h"
#include <iostream>
using namespace std;
class QuanLyNhaCungCap : public NhaCungCap {
    LinkedList<NhaCungCap> dsnhacungcap;

  public:
    QuanLyNhaCungCap themnhacungcap();
    QuanLyNhaCungCap hienthinhacungcap();
    QuanLyNhaCungCap capnhatnhacungcap();
    QuanLyNhaCungCap timkiemnhacungcap();
    QuanLyNhaCungCap kiemtrancc();
};
#endif
