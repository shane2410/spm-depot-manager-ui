#include "../backend_headers/FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

bool FileManager::docNguoiDung(QuanLyNguoiDung &qlnd, const string &tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cerr << "Error: Khong the mo file " << tenFile << endl;
        return false;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string tenDN, mk, ten, vt;

        getline(ss, tenDN, ',');
        getline(ss, mk, ',');
        getline(ss, ten, ',');
        getline(ss, vt, ',');

        vt.erase(vt.find_last_not_of("\r\n") + 1);

        qlnd.themnguoidung(NguoiDung(tenDN, mk, ten, vt));
    }

    file.close();
    return true;
}
