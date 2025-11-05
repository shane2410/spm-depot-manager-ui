#include "../backend_headers/NguoiDung.h"

NguoiDung::NguoiDung() : tenDangNhap(""), matKhau(""), hoTen(""), vaiTro("") {}
NguoiDung::NguoiDung(const string &tenDN, const string &mk, const string &ten,
                     const string &vt)
    : tenDangNhap(tenDN), matKhau(mk), hoTen(ten), vaiTro(vt) {}
string NguoiDung::getTenDangNhap() const { return tenDangNhap; }
string NguoiDung::getMatKhau() const { return matKhau; }
string NguoiDung::getHoTen() const { return hoTen; }
string NguoiDung::getVaiTro() const { return vaiTro; }
string NguoiDung::getKey() const { return this->tenDangNhap; }
bool NguoiDung::operator==(const NguoiDung &other) const {
    return this->tenDangNhap == other.tenDangNhap;
}
void NguoiDung::setTenDN(const string &tenDN) { this->tenDangNhap = tenDN; }
void NguoiDung::setMatKhau(const string &mk) { this->matKhau = mk; }
void NguoiDung::setHoTen(const string &ten) { this->hoTen = ten; }
void NguoiDung::setVaitro(const string &vt) { this->vaiTro = vt; }