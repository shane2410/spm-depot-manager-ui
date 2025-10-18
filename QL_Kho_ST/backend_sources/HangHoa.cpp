#include "../backend_headers/HangHoa.h"
#include "../backend_headers/Date.h"

HangHoa::HangHoa() {
    this->maHH = "";
    this->tenHH = "";
    this->donViTinh = "";
    this->giaNhap = 0.0;
    this->giaBan = 0.0;
    this->soLuongTon = 0;
    this->maNCC = "";
}
HangHoa::~HangHoa() {}
string HangHoa::getMaHH() const { return this->maHH; }
string HangHoa::getTenHH() const { return this->tenHH; }
string HangHoa::getDonViTinh() const { return this->donViTinh; }
string HangHoa::getMaNCC() const { return this->maNCC; }
double HangHoa::getGiaNhap() const { return this->giaNhap; }
double HangHoa::getGiaBan() const { return this->giaBan; }
int HangHoa::getSoLuongTon() const { return this->soLuongTon; }
Date HangHoa::getNgaySanXuat() const { return this->ngaySanXuat; }
Date HangHoa::getHanSuDung() const { return this->hanSuDung; }
// set
void HangHoa::setMaHH(string maHH) { this->maHH = maHH; }
void HangHoa::setTenHH(string tenHH) { this->tenHH = tenHH; }
void HangHoa::setDonViTinh(string donViTinh) { this->donViTinh = donViTinh; }
void HangHoa::setMaNCC(string maNCC) { this->maNCC = maNCC; }
void HangHoa::setGiaNhap(double giaNhap) { this->giaNhap = giaNhap; }
void HangHoa::setGiaBan(double giaBan) { this->giaBan = giaBan; }
void HangHoa::setSoLuongTon(int soLuongTon) { this->soLuongTon = soLuongTon; }
void HangHoa::setNgaySanXuat(Date ngaySanXuat) {
    this->ngaySanXuat = ngaySanXuat;
}
void HangHoa::setHanSuDung(Date hanSuDung) { this->hanSuDung = hanSuDung; }
HangHoa::HangHoa(string maHH, string tenHH, string donViTinh, double giaNhap,
                 double giaBan, int soLuongTon, string maNCC, Date ngaySanXuat,
                 Date hanSuDung) {
    this->maHH = maHH;
    this->tenHH = tenHH;
    this->donViTinh = donViTinh;
    this->giaNhap = giaNhap;
    this->giaBan = giaBan;
    this->soLuongTon = soLuongTon;
    this->maNCC = maNCC;
    this->ngaySanXuat = ngaySanXuat;
    this->hanSuDung = hanSuDung;
}
//

void HangHoa::capNhatSoLuong(int soLuongThayDoi) {
    int soLuongMoi = this->soLuongTon + soLuongThayDoi;
    if (soLuongMoi < 0) {
        cout << "Lỗi: Số lượng mới không hợp lệ. " << endl;
        this->soLuongTon = 0;
    } else {
        this->soLuongTon = soLuongMoi;
    }
}

string HangHoa::printWrappedString(ostream &os, const string &str,
                                   size_t maxwidth) const {
    stringstream textStream(str);
    string word;
    string line_to_print;
    string remaining_text;
    bool isFirstWord = true;

    while (textStream >> word) {
        if (line_to_print.length() + word.length() + (isFirstWord ? 0 : 1) <=
            maxwidth) {
            if (!isFirstWord) {
                line_to_print += " ";
            }
            line_to_print += word;
            isFirstWord = false;
        } else {
            remaining_text = word;
            break;
        }
    }

    os << left << setw(maxwidth) << line_to_print;

    while (textStream >> word) {
        if (!remaining_text.empty()) {
            remaining_text += " ";
        }
        remaining_text += word;
    }

    return remaining_text;
}

ostream &operator<<(ostream &os, const HangHoa &hh) {
    // mahh, tenhh, donvitinh, gianhap, giaban, soluongton, mancc, ngaysanxuat,
    // hansudung
    int getw[] = {8, 20, 8, 12, 12, 8, 12, 12, 12};

    const int TOTAL_WIDTH = getw[0] + getw[1] + getw[2] + getw[3] + getw[4] +
                            getw[5] + getw[6] + getw[7] + getw[8] + 28;

    os << string(TOTAL_WIDTH, '-') << endl;

    os << "| " << left << setw(getw[0]) << hh.getMaHH() << " | ";

    string remainingText = hh.printWrappedString(os, hh.getTenHH(), getw[1]);

    os << " | " << left << setw(getw[2]) << hh.getDonViTinh() << " | " << right
       << setw(getw[3]) << hh.getGiaNhap() << " | " << right << setw(getw[4])
       << hh.getGiaBan() << " | " << right << setw(getw[5])
       << hh.getSoLuongTon() << " | " << left << setw(getw[6]) << hh.getMaNCC()
       << " | " << right << setw(getw[7]) << hh.getNgaySanXuat().toString()
       << " | " << right << setw(getw[8]) << hh.getHanSuDung().toString()
       << " |" << endl;

    while (!remainingText.empty()) {
        os << "| " << string(getw[0], ' ') << " | ";

        remainingText = hh.printWrappedString(os, remainingText, getw[1]);

        os << " | " << string(getw[2], ' ') << " | " << string(getw[3], ' ')
           << " | " << string(getw[4], ' ') << " | " << string(getw[5], ' ')
           << " | " << string(getw[6], ' ') << " | " << string(getw[7], ' ')
           << " | " << string(getw[8], ' ') << " |" << endl;
    }
    os << string(TOTAL_WIDTH, '-') << endl;

    return os;
}

string HangHoa::getKey() const { return this->maHH; }
