#include "../backend_headers/FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool FileManager::docHangHoa(QuanLyHangHoa &qlhh, const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maHH, tenHH, donViTinh, giaNhapStr, giaBanStr, soLuongTonStr, maNCC, ngaySanXuatStr, hanSuDungStr;

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

            HangHoa hh(maHH, tenHH, donViTinh, giaNhap, giaBan, soLuongTon, maNCC, ngaySanXuat, hanSuDung);
            qlhh.themHangHoa(hh);
        } catch (const std::exception &e) {
            std::cerr << "Loi xu ly dong hang hoa: " << line << " | Error: " << e.what() << std::endl;
        }
    }
    file.close();
    return true;
}

bool FileManager::docNhaCungCap(QuanLyNhaCungCap &qlncc, const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << filename << std::endl;
        return false;
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

bool FileManager::docCTPhieuNhap(QuanLyPhieu &qlpn, const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << filename << std::endl;
        return false;
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
            std::cerr << "Loi xu ly dong ctpn: " << line << " | Error: " << e.what() << std::endl;
        }
    }
    file.close();
    return true;
}

bool FileManager::docCTPhieuXuat(QuanLyPhieu &qlpx, const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << filename << std::endl;
        return false;
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
            std::cerr << "Loi xu ly dong ctpx: " << line << " | Error: " << e.what() << std::endl;
        }
    }
    file.close();
    return true;
}

bool FileManager::docPhieuNhap(QuanLyPhieu &qlpn, const std::string &filename) {
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
    return docCTPhieuNhap(qlpn, "Data/ChiietPhieuNhap.csv");
}

bool FileManager::docPhieuXuat(QuanLyPhieu &qlpx, const std::string &filename) {
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
    return docCTPhieuXuat(qlpx, "Data/ChitietPhieu.csv");
}

bool FileManager::docNguoiDung(QuanLyNguoiDung &qlnd, const std::string &tenFile) {
    std::ifstream file(tenFile);
    if (!file.is_open()) {
        std::cerr << "Error: Khong the mo file " << tenFile << std::endl;
        return false;
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
    std::ofstream file(hangHoaFile);
    if (!file.is_open()) return;

    const LinkedList<HangHoa>& ds = qlhh.getDanhSach();
    Node<HangHoa>* current = ds.getHead();
    while (current != nullptr) {
        const HangHoa& hh = current->data;
        file << hh.getMaHH() << "," << hh.getTenHH() << "," << hh.getDonViTinh() << ","
             << hh.getGiaNhap() << "," << hh.getGiaBan() << "," << hh.getSoLuongTon() << ","
             << hh.getMaNCC() << "," << hh.getNgaySanXuat().toString() << "," << hh.getHanSuDung().toString() << "\n";
        current = current->pNext;
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
        file << ncc.getMaNCC() << "," << ncc.getTenNCC() << "," << ncc.getDiaChi() << "," << ncc.getSoDienThoai() << "\n";
        current = current->pNext;
    }
    file.close();
}

void FileManager::ghiPhieuNhap(const QuanLyPhieu &qlpn) {
    std::ofstream filePN(phieuNhapFile);
    std::ofstream fileCTPN("Data/ChiietPhieuNhap.csv");
    if (!filePN.is_open() || !fileCTPN.is_open()) return;

    const LinkedList<PhieuNhap>& dsPN = qlpn.getDanhSachPhieuNhap();
    Node<PhieuNhap>* nodePN = dsPN.getHead();
    while (nodePN != nullptr) {
        const PhieuNhap& pn = nodePN->data;
        filePN << pn.getMaPhieuNhap() << "," << pn.getNgayNhap().toString() << "," << pn.getMaNCC() << "\n";

        const LinkedList<ChitietPhieuNhap>& dsCTPN = pn.getDsCTPN();
        Node<ChitietPhieuNhap>* nodeCTPN = dsCTPN.getHead();
        while (nodeCTPN != nullptr) {
            const ChitietPhieuNhap& ctpn = nodeCTPN->data;
            fileCTPN << pn.getMaPhieuNhap() << "," << ctpn.maHH << "," << ctpn.soLuong << "," << ctpn.donGiaNhap << "\n";
            nodeCTPN = nodeCTPN->pNext;
        }
        nodePN = nodePN->pNext;
    }
    filePN.close();
    fileCTPN.close();
}

void FileManager::ghiPhieuXuat(const QuanLyPhieu &qlpx) {
    std::ofstream filePX(phieuXuatFile);
    std::ofstream fileCTPX("Data/ChitietPhieu.csv");
    if (!filePX.is_open() || !fileCTPX.is_open()) return;

    const LinkedList<PhieuXuat>& dsPX = qlpx.getDanhSachPhieuXuat();
    Node<PhieuXuat>* nodePX = dsPX.getHead();
    while (nodePX != nullptr) {
        const PhieuXuat& px = nodePX->data;
        filePX << px.getMaPhieuXuat() << "," << px.getNgayXuat().toString() << "," << px.getTenKH() << "\n";

        const LinkedList<ChitietPhieuXuat>& dsCTPX = px.getDsCTPX();
        Node<ChitietPhieuXuat>* nodeCTPX = dsCTPX.getHead();
        while (nodeCTPX != nullptr) {
            const ChitietPhieuXuat& ctpx = nodeCTPX->data;
            fileCTPX << px.getMaPhieuXuat() << "," << ctpx.maHH << "," << ctpx.soLuong << "," << ctpx.donGiaBan << "\n";
            nodeCTPX = nodeCTPX->pNext;
        }
        nodePX = nodePX->pNext;
    }
    filePX.close();
    fileCTPX.close();
}

void FileManager::ghiNguoiDung(const QuanLyNguoiDung &qlnd) {
    std::ofstream file(nguoiDungFile);
    if (!file.is_open()) return;

    const LinkedList<NguoiDung>& ds = qlnd.laydanhsachnguoidung();
    Node<NguoiDung>* current = ds.getHead();
    while (current != nullptr) {
        const NguoiDung& nd = current->data;
        file << nd.getTenDangNhap() << "," << nd.getMatKhau() << "," << nd.getHoTen() << "," << nd.getVaiTro() << "\n";
        current = current->pNext;
    }
    file.close();
}

void FileManager::docTatCaDuLieu(QuanLyHangHoa &qlhh, QuanLyNhaCungCap &qlncc, QuanLyPhieu &qlpn, QuanLyNguoiDung &qlnd) {
    docDataNguoiDung(qlnd);
    docDataHangHoa(qlhh);
    docDataNhaCungCap(qlncc);
    docDataPhieuNhap(qlpn);
    docDataPhieuXuat(qlpn);
    qlpn.tinhTongTien();
}

void FileManager::ghiTatCaDuLieu(const QuanLyHangHoa &qlhh, const QuanLyNhaCungCap &qlncc, const QuanLyNguoiDung &qlnd) {
    ghiHangHoa(qlhh);
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
