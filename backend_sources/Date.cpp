#include "../backend_headers/Date.h"
#include <iostream>
using namespace std;

istream &operator>>(istream &is, Date &d) {
    cout << "Nhập ngày (dd/mm/yyyy): ";
    Date temp;
    char slash;
    is >> temp.ngay;
    is >> slash;
    is >> temp.thang;
    is >> slash;
    is >> temp.nam;
    if (slash == '/' && temp.hopLe(temp.ngay, temp.thang, temp.nam)) {
        d = temp;
    } else {
        cout << "Ngày tháng năm không hợp lệ. Gán mặc định 1/1/1900" << endl;
        d.ngay = 1;
        d.thang = 1;
        d.nam = 1900;
    }
    return is;
}
ostream &operator<<(ostream &os, Date d) {
    os << d.ngay << "/" << d.thang << "/" << d.nam;
    return os;
}

string Date::toString() {
    return to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam);
}

int Date::getDay() const { return this->ngay; }
int Date::getMonth() const { return this->thang; }
int Date::getYear() const { return this->nam; }

void Date::setDay(int ngay) { this->ngay = ngay; }
void Date::setMonth(int thang) { this->thang = thang; }
void Date::setYear(int nam) { this->nam = nam; }

Date Date::strtoDate(const string &dateStr) {
    stringstream ss(dateStr);
    string day, month, year;
    getline(ss, day, '/');
    getline(ss, month, '/');
    getline(ss, year);
    try {
        return Date(stoi(day), stoi(month), stoi(year));
    } catch (const exception &e) {
        cerr << "Lỗi, vui lòng kiểm tra định dạng: " << dateStr << endl;
        return Date();
    }
}

bool Date::operator<=(const Date &other) const {
    if (this->nam < other.nam)
        return true;
    if (this->nam == other.nam && this->thang < other.thang)
        return true;
    if (this->nam == other.nam && this->thang == other.thang &&
        this->ngay <= other.ngay)
        return true;
    return false;
}

bool Date::operator>=(const Date &other) const {
    if (this->nam > other.nam)
        return true;
    if (this->nam == other.nam && this->thang > other.thang)
        return true;
    if (this->nam == other.nam && this->thang == other.thang &&
        this->ngay >= other.ngay)
        return true;
    return false;
}