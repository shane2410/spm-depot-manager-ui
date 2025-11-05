#ifndef Date_h
#define Date_h
#include <iostream>
#include <sstream>
using namespace std;
class Date {
  private:
    int ngay, thang, nam;
    bool namNhuan(int nam) {
        return (nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0;
    }
    bool hopLe(int ngay, int thang, int nam) {
        if (ngay < 1 || thang < 1 || thang > 12 || nam < 1)
            return false;
        int soNgay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (namNhuan(nam)) {
            soNgay[2] = 29;
        }
        if (ngay > soNgay[thang])
            return false;
        return true;
    }

  public:
    Date() : ngay(1), thang(1), nam(1900) {}
    ~Date() {}
    Date(int ngay, int thang, int nam) {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    friend istream &operator>>(istream &is, Date &d);
    friend ostream &operator<<(ostream &os, Date d);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    string toString();
    static Date strtoDate(const string &dateStr);
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;
};
#endif
