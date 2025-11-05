#include "../backend_headers/FileManager.h"
#include <fstream>
#include <iostream>
#include <sys/stat.h>

const string STATIC_NGUOIDUNG_FILE(const FileManager& fm){
    return fm.nguoiDungFile;
}

bool FileManager::isFirstRun() {
    struct stat buffer;
    if (stat("Data", &buffer) != 0) {
#if defined(_WIN32)
        _mkdir("Data");
#else
        mkdir("Data", 0777);
#endif
    }
    FileManager fm;
    std::ifstream userFile(STATIC_NGUOIDUNG_FILE(fm));
    if (userFile.good()) {
        userFile.close();
        return false;
    }
    userFile.close();
    initFirstRun();
    return true;
}

void FileManager::initFirstRun() {
    FileManager fm;
    QuanLyNguoiDung qlnd;
    NguoiDung admin("admin", "admin", "Quản Trị Viên", "quanly");
    qlnd.themnguoidung(admin);
    fm.ghiNguoiDung(qlnd);

    std::ofstream(fm.hangHoaFile, std::ios::binary).close();
    std::ofstream(fm.nccFile, std::ios::binary).close();
    std::ofstream(fm.phieuNhapFile, std::ios::binary).close();
    std::ofstream(fm.phieuXuatFile, std::ios::binary).close();

    std::cout << "Da khoi tao du lieu mac dinh cho lan chay dau tien." << std::endl;
}

void writeString(std::ofstream &file, const std::string &str) {
    size_t len = str.length();
    file.write(reinterpret_cast<const char *>(&len), sizeof(len));
    if (len > 0) {
        file.write(str.c_str(), len);
    }
}

std::string readString(std::ifstream &file) {
    size_t len = 0;
    file.read(reinterpret_cast<char *>(&len), sizeof(len));
    if (!file || len == 0) {
        return "";
    }
    std::string result(len, '\0');
    file.read(&result[0], len);
    if (!file) {
        return "";
    }
    return result;
}

bool FileManager::docHangHoa(QuanLyHangHoa &qlhh) {
    std::ifstream file(hangHoaFile, std::ios::binary);
    if (!file.is_open()) return false;

    while (file.peek() != EOF) {
        std::string maHH = readString(file);
        if (!file || maHH.empty()) break;
        std::string tenHH = readString(file);
        std::string donViTinh = readString(file);
        std::string maNCC = readString(file);
        if (!file) return false;

        double giaNhap, giaBan;
        int soLuongTon;
        Date ngaySanXuat, hanSuDung;

        file.read(reinterpret_cast<char *>(&giaNhap), sizeof(giaNhap));
        file.read(reinterpret_cast<char *>(&giaBan), sizeof(giaBan));
        file.read(reinterpret_cast<char *>(&soLuongTon), sizeof(soLuongTon));
        file.read(reinterpret_cast<char *>(&ngaySanXuat), sizeof(ngaySanXuat));
        file.read(reinterpret_cast<char *>(&hanSuDung), sizeof(hanSuDung));
        if (!file) return false;

        HangHoa hh(maHH, tenHH, donViTinh, giaNhap, giaBan, soLuongTon, maNCC,
                   ngaySanXuat, hanSuDung);
        qlhh.themHangHoa(hh);
    }
    file.close();
    return true;
}

bool FileManager::docNhaCungCap(QuanLyNhaCungCap &qlncc) {
    std::ifstream file(nccFile, std::ios::binary);
    if (!file.is_open()) return false;

    while (file.peek() != EOF) {
        std::string maNCC = readString(file);
        if (!file || maNCC.empty()) break;
        std::string tenNCC = readString(file);
        std::string diaChi = readString(file);
        std::string sdt = readString(file);
        if (!file) return false;

        NhaCungCap ncc(maNCC, tenNCC, diaChi, sdt);
        qlncc.themNhaCungCap(ncc);
    }
    file.close();
    return true;
}

bool FileManager::docPhieuNhap(QuanLyPhieu &qlpn) {
    std::ifstream file(phieuNhapFile, std::ios::binary);
    if (!file.is_open()) return false;

    while (file.peek() != EOF) {
        std::string maPhieu = readString(file);
        if (!file || maPhieu.empty()) break;

        Date ngayNhap;
        file.read(reinterpret_cast<char *>(&ngayNhap), sizeof(ngayNhap));
        if (!file) return false;

        std::string maNCC = readString(file);
        if (!file) return false;

        PhieuNhap pn;
        pn.setMaPhieuNhap(maPhieu);
        pn.setNgayNhap(ngayNhap);
        pn.setMaNCC(maNCC);

        size_t soLuongCT;
        file.read(reinterpret_cast<char *>(&soLuongCT), sizeof(soLuongCT));
        if (!file) return false;

        for (size_t i = 0; i < soLuongCT; ++i) {
            ChitietPhieuNhap ctpn;
            ctpn.maHH = readString(file);
            if (!file) return false;
            file.read(reinterpret_cast<char *>(&ctpn.soLuong), sizeof(ctpn.soLuong));
            file.read(reinterpret_cast<char *>(&ctpn.donGiaNhap), sizeof(ctpn.donGiaNhap));
            if (!file) return false;
            pn.themChiTiet(ctpn);
        }
        qlpn.themPhieuNhap(pn);
    }
    file.close();
    return true;
}

bool FileManager::docPhieuXuat(QuanLyPhieu &qlpx) {
    std::ifstream file(phieuXuatFile, std::ios::binary);
    if (!file.is_open()) return false;

    while (file.peek() != EOF) {
        std::string maPhieu = readString(file);
        if (!file || maPhieu.empty()) break;

        Date ngayXuat;
        file.read(reinterpret_cast<char *>(&ngayXuat), sizeof(ngayXuat));
        if (!file) return false;

        std::string tenKH = readString(file);
        if (!file) return false;

        PhieuXuat px;
        px.setMaPhieuXuat(maPhieu);
        px.setNgayXuat(ngayXuat);
        px.setTenKH(tenKH);

        size_t soLuongCT;
        file.read(reinterpret_cast<char *>(&soLuongCT), sizeof(soLuongCT));
        if (!file) return false;

        for (size_t i = 0; i < soLuongCT; ++i) {
            ChitietPhieuXuat ctpx;
            ctpx.maHH = readString(file);
            if (!file) return false;
            file.read(reinterpret_cast<char *>(&ctpx.soLuong), sizeof(ctpx.soLuong));
            file.read(reinterpret_cast<char *>(&ctpx.donGiaBan), sizeof(ctpx.donGiaBan));
            if (!file) return false;
            px.themChiTiet(ctpx);
        }
        qlpx.themPhieuXuat(px);
    }
    file.close();
    return true;
}

bool FileManager::docNguoiDung(QuanLyNguoiDung &qlnd) {
    std::ifstream file(nguoiDungFile, std::ios::binary);
    if (!file.is_open()) return false;

    while (file.peek() != EOF) {
        std::string tenDN = readString(file);
        if (!file || tenDN.empty()) break;
        std::string mk = readString(file);
        std::string ten = readString(file);
        std::string vt = readString(file);
        if (!file) return false;

        NguoiDung nd(tenDN, mk, ten, vt);
        qlnd.themnguoidung(nd);
    }
    file.close();
    return true;
}

void FileManager::ghiHangHoa(const QuanLyHangHoa &qlhh) {
    std::ofstream file(hangHoaFile, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) return;

    const LinkedList<HangHoa> &ds = qlhh.getDanhSach();
    Node<HangHoa> *current = ds.getHead();
    while (current != nullptr) {
        const HangHoa &hh = current->data;
        writeString(file, hh.getMaHH());
        writeString(file, hh.getTenHH());
        writeString(file, hh.getDonViTinh());
        writeString(file, hh.getMaNCC());
        double giaNhap = hh.getGiaNhap();
        double giaBan = hh.getGiaBan();
        int soLuongTon = hh.getSoLuongTon();
        Date nsx = hh.getNgaySanXuat();
        Date hsd = hh.getHanSuDung();
        file.write(reinterpret_cast<const char *>(&giaNhap), sizeof(giaNhap));
        file.write(reinterpret_cast<const char *>(&giaBan), sizeof(giaBan));
        file.write(reinterpret_cast<const char *>(&soLuongTon), sizeof(soLuongTon));
        file.write(reinterpret_cast<const char *>(&nsx), sizeof(nsx));
        file.write(reinterpret_cast<const char *>(&hsd), sizeof(hsd));
        current = current->pNext;
    }
    file.close();
}

void FileManager::ghiNhaCungCap(const QuanLyNhaCungCap &qlncc) {
    std::ofstream file(nccFile, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) return;

    const LinkedList<NhaCungCap> &ds = qlncc.getDanhSach();
    Node<NhaCungCap> *current = ds.getHead();
    while (current != nullptr) {
        const NhaCungCap &ncc = current->data;
        writeString(file, ncc.getMaNCC());
        writeString(file, ncc.getTenNCC());
        writeString(file, ncc.getDiaChi());
        writeString(file, ncc.getSoDienThoai());
        current = current->pNext;
    }
    file.close();
}

void FileManager::ghiPhieuNhap(const QuanLyPhieu &qlpn) {
    std::ofstream filePN(phieuNhapFile, std::ios::binary | std::ios::trunc);
    if (!filePN.is_open()) return;

    const LinkedList<PhieuNhap> &dsPN = qlpn.getDanhSachPhieuNhap();
    Node<PhieuNhap> *nodePN = dsPN.getHead();
    while (nodePN != nullptr) {
        const PhieuNhap &pn = nodePN->data;
        writeString(filePN, pn.getMaPhieuNhap());
        Date ngayNhap = pn.getNgayNhap();
        filePN.write(reinterpret_cast<const char *>(&ngayNhap), sizeof(ngayNhap));
        writeString(filePN, pn.getMaNCC());

        const LinkedList<ChitietPhieuNhap> &dsCTPN = pn.getDsCTPN();
        size_t soLuongCT = dsCTPN.getSize();
        filePN.write(reinterpret_cast<const char *>(&soLuongCT), sizeof(soLuongCT));

        Node<ChitietPhieuNhap> *nodeCTPN = dsCTPN.getHead();
        while (nodeCTPN != nullptr) {
            const ChitietPhieuNhap &ctpn = nodeCTPN->data;
            writeString(filePN, ctpn.maHH);
            filePN.write(reinterpret_cast<const char *>(&ctpn.soLuong), sizeof(ctpn.soLuong));
            filePN.write(reinterpret_cast<const char *>(&ctpn.donGiaNhap), sizeof(ctpn.donGiaNhap));
            nodeCTPN = nodeCTPN->pNext;
        }
        nodePN = nodePN->pNext;
    }
    filePN.close();
}

void FileManager::ghiPhieuXuat(const QuanLyPhieu &qlpx) {
    std::ofstream filePX(phieuXuatFile, std::ios::binary | std::ios::trunc);
    if (!filePX.is_open()) return;

    const LinkedList<PhieuXuat> &dsPX = qlpx.getDanhSachPhieuXuat();
    Node<PhieuXuat> *nodePX = dsPX.getHead();
    while (nodePX != nullptr) {
        const PhieuXuat &px = nodePX->data;
        writeString(filePX, px.getMaPhieuXuat());
        Date ngayXuat = px.getNgayXuat();
        filePX.write(reinterpret_cast<const char *>(&ngayXuat), sizeof(ngayXuat));
        writeString(filePX, px.getTenKH());

        const LinkedList<ChitietPhieuXuat> &dsCTPX = px.getDsCTPX();
        size_t soLuongCT = dsCTPX.getSize();
        filePX.write(reinterpret_cast<const char *>(&soLuongCT), sizeof(soLuongCT));

        Node<ChitietPhieuXuat> *nodeCTPX = dsCTPX.getHead();
        while (nodeCTPX != nullptr) {
            const ChitietPhieuXuat &ctpx = nodeCTPX->data;
            writeString(filePX, ctpx.maHH);
            filePX.write(reinterpret_cast<const char *>(&ctpx.soLuong), sizeof(ctpx.soLuong));
            filePX.write(reinterpret_cast<const char *>(&ctpx.donGiaBan), sizeof(ctpx.donGiaBan));
            nodeCTPX = nodeCTPX->pNext;
        }
        nodePX = nodePX->pNext;
    }
    filePX.close();
}

void FileManager::ghiNguoiDung(const QuanLyNguoiDung &qlnd) {
    std::ofstream file(nguoiDungFile, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) return;

    const LinkedList<NguoiDung> &ds = qlnd.laydanhsachnguoidung();
    Node<NguoiDung> *current = ds.getHead();
    while (current != nullptr) {
        const NguoiDung &nd = current->data;
        writeString(file, nd.getTenDangNhap());
        writeString(file, nd.getMatKhau());
        writeString(file, nd.getHoTen());
        writeString(file, nd.getVaiTro());
        current = current->pNext;
    }
    file.close();
}

void FileManager::docTatCaDuLieu(QuanLyHangHoa &qlhh, QuanLyNhaCungCap &qlncc,
                                 QuanLyPhieu &qlp, QuanLyNguoiDung &qlnd) {
    docNguoiDung(qlnd);
    docNhaCungCap(qlncc);
    docHangHoa(qlhh);
    docPhieuNhap(qlp);
    docPhieuXuat(qlp);
    qlp.tinhTongTien();
}

void FileManager::ghiTatCaDuLieu(const QuanLyHangHoa &qlhh,
                                 const QuanLyNhaCungCap &qlncc,
                                 const QuanLyPhieu &qlp,
                                 const QuanLyNguoiDung &qlnd) {
    ghiNguoiDung(qlnd);
    ghiHangHoa(qlhh);
    ghiNhaCungCap(qlncc);
    ghiPhieuNhap(qlp);
    ghiPhieuXuat(qlp);
}
/*v


bool FileManager::docHangHoa(QuanLyHangHoa &qlhh) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maHH, tenHH, donViTinh, giaNhapStr, giaBanStr,
soLuongTonStr, maNCC, ngaySanXuatStr, hanSuDungStr;

        std::getline(ss, maHH, ',');
        std::getline(ss, tenHH, ',');
        std::getline(ss, donViTinh, ',');
        std::getline(ss, giaNhapStr, ',');
        std::getline(ss, giaBanStr, ',');
        std::getline(ss, soLuongTonStr, ',');
        std::getline(ss, maNCC, ',');
        std::getline(ss, ngaySanXuatStr, ',');
        std::getline(ss, hanSuDungStr, '\r');

        try {
            double giaNhap = std::stod(giaNhapStr);
            double giaBan = std::stod(giaBanStr);
            int soLuongTon = std::stoi(soLuongTonStr);
            Date ngaySanXuat = Date::strtoDate(ngaySanXuatStr);
            Date hanSuDung = Date::strtoDate(hanSuDungStr);

            HangHoa hh(maHH, tenHH, donViTinh, giaNhap, giaBan, soLuongTon,
maNCC, ngaySanXuat, hanSuDung); qlhh.themHangHoa(hh); } catch (const
std::exception &e) { std::cerr << "Loi xu ly dong hang hoa: " << line << " |
Error: " << e.what() << std::endl;
        }
    }
    file.close();
    return true;
}

bool FileManager::docNhaCungCap(QuanLyNhaCungCap &qlncc, const std::string
&filename) { std::ifstream file(filename); if (!file.is_open()) { std::cerr <<
"Error: Khong the mo file " << filename << std::endl; return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maNCC, tenNCC, diaChi, soDienThoai;
        std::getline(ss, maNCC, ',');
        std::getline(ss, tenNCC, ',');
        std::getline(ss, diaChi, ',');
        std::getline(ss, soDienThoai, '\r');

        NhaCungCap ncc(maNCC, tenNCC, diaChi, soDienThoai);
        qlncc.themNhaCungCap(ncc);
    }
    file.close();
    return true;
}

bool FileManager::docCTPhieuNhap(QuanLyPhieu &qlpn)
{ std::ifstream file(filename); if (!file.is_open()) { std::cerr << "Error:
Khong the mo file " << filename << std::endl; return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maPhieuNhap, maHH, soLuongStr, donGiaNhapStr;
        std::getline(ss, maPhieuNhap, ',');
        std::getline(ss, maHH, ',');
        std::getline(ss, soLuongStr, ',');
        std::getline(ss, donGiaNhapStr, '\r');

        try {
            int soLuong = std::stoi(soLuongStr);
            double donGiaNhap = std::stod(donGiaNhapStr);

            ChitietPhieuNhap ctpn;
            ctpn.maHH = maHH;
            ctpn.soLuong = soLuong;
            ctpn.donGiaNhap = donGiaNhap;

            PhieuNhap *pn = qlpn.timPhieuNhap(maPhieuNhap);
            if (pn) {
                pn->themChiTiet(ctpn);
            }
        } catch (const std::exception &e) {
            std::cerr << "Loi xu ly dong ctpn: " << line << " | Error: " <<
e.what() << std::endl;
        }
    }
    file.close();
    return true;
}

bool FileManager::docCTPhieuXuat(QuanLyPhieu &qlpx)
{ std::ifstream file(filename); if (!file.is_open()) { std::cerr << "Error:
Khong the mo file " << filename << std::endl; return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maPhieuXuat, maHH, soLuongStr, donGiaBanStr;
        std::getline(ss, maPhieuXuat, ',');
        std::getline(ss, maHH, ',');
        std::getline(ss, soLuongStr, ',');
        std::getline(ss, donGiaBanStr, '\r');

        try {
            int soLuong = std::stoi(soLuongStr);
            double donGiaBan = std::stod(donGiaBanStr);

            ChitietPhieuXuat ctpx;
            ctpx.maHH = maHH;
            ctpx.soLuong = soLuong;
            ctpx.donGiaBan = donGiaBan;

            PhieuXuat *px = qlpx.timPhieuXuat(maPhieuXuat);
            if (px) {
                px->themChiTiet(ctpx);
            }
        } catch (const std::exception &e) {
            std::cerr << "Loi xu ly dong ctpx: " << line << " | Error: " <<
e.what() << std::endl;
        }
    }
    file.close();
    return true;
}

bool FileManager::docPhieuNhap(QuanLyPhieu &qlpn) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << filename << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maPhieu, ngayNhap, maNCC;
        std::getline(ss, maPhieu, ',');
        std::getline(ss, ngayNhap, ',');
        std::getline(ss, maNCC, '\r');

        PhieuNhap pn;
        pn.setMaPhieuNhap(maPhieu);
        pn.setNgayNhap(Date::strtoDate(ngayNhap));
        pn.setMaNCC(maNCC);
        qlpn.themPhieuNhap(pn);
    }
    file.close();
    return docCTPhieuNhap(qlpn, "Data/ChitietPhieuNhap.csv");
}

bool FileManager::docPhieuXuat(QuanLyPhieu &qlpx) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << filename << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maPhieu, ngayXuat, tenKH;
        std::getline(ss, maPhieu, ',');
        std::getline(ss, ngayXuat, ',');
        std::getline(ss, tenKH, '\r');

        PhieuXuat px;
        px.setMaPhieuXuat(maPhieu);
        px.setNgayXuat(Date::strtoDate(ngayXuat));
        px.setTenKH(tenKH);
        qlpx.themPhieuXuat(px);
    }
    file.close();
    return docCTPhieuXuat(qlpx, "Data/ChitietPhieuXuat.csv");
}

bool FileManager::docNguoiDung(QuanLyNguoiDung &qlnd, const std::string
&filename) { std::ifstream file(filename); if (!file.is_open()) { std::cerr <<
"Error: Khong the mo file " << filename << std::endl; return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string tenDN, mk, ten, vt;

        std::getline(ss, tenDN, ',');
        std::getline(ss, mk, ',');
        std::getline(ss, ten, ',');
        std::getline(ss, vt, '\r');

        NguoiDung nd(tenDN, mk, ten, vt);
        qlnd.themnguoidung(nd);
    }
    file.close();
    return true;
}

void FileManager::ghiHangHoa(const QuanLyHangHoa &qlhh) {
    std::ofstream file(hangHoaFile, ios::app);
    if (!file.is_open()) return;

    const LinkedList<HangHoa>& ds = qlhh.getDanhSach();
    Node<HangHoa>* current = ds.getHead();
    while (current != nullptr) {
        const HangHoa& hh = current->data;
        file << hh.getMaHH() << "," << hh.getTenHH() << "," << hh.getDonViTinh()
<< ","
             << hh.getGiaNhap() << "," << hh.getGiaBan() << "," <<
hh.getSoLuongTon() << ","
             << hh.getMaNCC() << "," << hh.getNgaySanXuat().toString() << "," <<
hh.getHanSuDung().toString() << "\n"; current = current->ppNext;
    }
    file.close();
}

void FileManager::ghiNhaCungCap(const QuanLyNhaCungCap &qlncc) {
    std::ofstream file(nccFile);
    if (!file.is_open()) return;
    const LinkedList<NhaCungCap>& ds = qlncc.getDanhSach();
    Node<NhaCungCap>* current = ds.getHead();
    while (current != nullptr) {
        const NhaCungCap& ncc = current->data;
        file << ncc.getMaNCC() << "," << ncc.getTenNCC() << "," <<
ncc.getDiaChi() << "," << ncc.getSoDienThoai() << "\n"; current =
current->ppNext;
    }
    file.close();
}

void FileManager::ghiPhieuNhap(const QuanLyPhieu &qlpn) {
    std::ofstream filePN(phieuNhapFile);
    std::ofstream fileCTPN("Data/ChitietPhieuNhap.csv");
    if (!filePN.is_open() || !fileCTPN.is_open()) return;

    const LinkedList<PhieuNhap>& dsPN = qlpn.getDanhSachPhieuNhap();
    Node<PhieuNhap>* nodePN = dsPN.getHead();
    while (nodePN != nullptr) {
        const PhieuNhap& pn = nodePN->data;
        filePN << pn.getMaPhieuNhap() << "," << pn.getNgayNhap().toString() <<
"," << pn.getMaNCC() << "\n";

        const LinkedList<ChitietPhieuNhap>& dsCTPN = pn.getDsCTPN();
        Node<ChitietPhieuNhap>* nodeCTPN = dsCTPN.getHead();
        while (nodeCTPN != nullptr) {
            const ChitietPhieuNhap& ctpn = nodeCTPN->data;
            fileCTPN << pn.getMaPhieuNhap() << "," << ctpn.maHH << "," <<
ctpn.soLuong << "," << ctpn.donGiaNhap << "\n"; nodeCTPN = nodeCTPN->ppNext;
        }
        nodePN = nodePN->ppNext;
    }
    filePN.close();
    fileCTPN.close();
}

void FileManager::ghiPhieuXuat(const QuanLyPhieu &qlpx) {
    std::ofstream filePX(phieuXuatFile,ios::app);
    std::ofstream fileCTPX("Data/chitietpieuxuat.csv");
    if (!filePX.is_open() || !fileCTPX.is_open()) return;

    const LinkedList<PhieuXuat>& dsPX = qlpx.getDanhSachPhieuXuat();
    Node<PhieuXuat>* nodePX = dsPX.getHead();
    while (nodePX != nullptr) {
        const PhieuXuat& px = nodePX->data;
        filePX << px.getMaPhieuXuat() << "," << px.getNgayXuat().toString() <<
"," << px.getTenKH() << "\n";

        const LinkedList<ChitietPhieuXuat>& dsCTPX = px.getDsCTPX();
        Node<ChitietPhieuXuat>* nodeCTPX = dsCTPX.getHead();
        while (nodeCTPX != nullptr) {
            const ChitietPhieuXuat& ctpx = nodeCTPX->data;
            fileCTPX << px.getMaPhieuXuat() << "," << ctpx.maHH << "," <<
ctpx.soLuong << "," << ctpx.donGiaBan << "\n"; nodeCTPX = nodeCTPX->ppNext;
        }
        nodePX = nodePX->ppNext;
    }
    filePX.close();
    fileCTPX.close();
}

void FileManager::ghiNguoiDung(const QuanLyNguoiDung &qlnd) {
    std::ofstream file(nguoiDungFile, ios::app);
    if (!file.is_open()) return;

    const LinkedList<NguoiDung>& ds = qlnd.laydanhsachnguoidung();
    Node<NguoiDung>* current = ds.getHead();
    while (current != nullptr) {
        const NguoiDung& nd = current->data;
        file << nd.getTenDangNhap() << "," << nd.getMatKhau() << "," <<
nd.getHoTen() << "," << nd.getVaiTro() << "\n"; current = current->ppNext;
    }
    file.close();
}

void FileManager::docTatCaDuLieu(QuanLyHangHoa &qlhh, QuanLyNhaCungCap &qlncc,
QuanLyPhieu &qlpn, QuanLyNguoiDung &qlnd) { docDataNguoiDung(qlnd);
    docDataHangHoa(qlhh);
    docDataNhaCungCap(qlncc);
    docDataPhieuNhap(qlpn);
    docDataPhieuXuat(qlpn);
    qlpn.tinhTongTien();
}

void FileManager::ghiTatCaDuLieu(const QuanLyHangHoa &qlhh, const
QuanLyNhaCungCap &qlncc, const QuanLyNguoiDung &qlnd) { ghiHangHoa(qlhh);
    ghiNhaCungCap(qlncc);
    ghiNguoiDung(qlnd);
}

bool FileManager::docDataNguoiDung(QuanLyNguoiDung &qlnd) {
    return docNguoiDung(qlnd, "Data/nguoidung.csv");
}

bool FileManager::docDataHangHoa(QuanLyHangHoa &qlhh) {
    return docHangHoa(qlhh, "Data/hanghoa.csv");
}

bool FileManager::docDataNhaCungCap(QuanLyNhaCungCap &qlncc) {
    return docNhaCungCap(qlncc, "Data/nhacungcap.csv");
}

bool FileManager::docDataPhieuNhap(QuanLyPhieu &qlpn) {
    return docPhieuNhap(qlpn, "Data/phieunhap.csv");
}

bool FileManager::docDataPhieuXuat(QuanLyPhieu &qlpx) {
    return docPhieuXuat(qlpx, "Data/phieuxuat.csv");
}
*/
