#include <iostream>
using namespace std;
class forUser {
  public:
    void Menu0() {
        system("cls");
        cout << "Nhóm 11: " << endl
             << "Thành viên: Phạm Quang Khiêm   (102240033" << endl
             << "            Trần Huy Thịnh     (1022400xx" << endl
             << "\nPBL2 - Quản Lý Hàng Hóa Trong Kho Siêu Thị " << endl
             << "    ---------- MENU QUẢN LÝ ---------" << endl
             << "    1. Quản lý Hàng hóa." << endl
             << "    2. Quản lý Nhà cung cấp" << endl
             << "    3. Quản lý Nhập/Xuất kho." << endl
             << "    4. Báo cáo và Thống kê." << endl
             << "    5. Thoát. " << endl
             << "    ---------------------------------" << endl;
    }
    void Menu1_1() {
        system("cls");
        cout << "    ------- QUẢN LÝ HÀNG HÓA -------" << endl
             << "    1. Thêm hàng hóa mới." << endl
             << "    2. Hiển thị danh sách hàng hóa." << endl
             << "    3. Cập nhật thông tin hàng hóa." << endl
             << "    4. Xóa hàng hóa." << endl
             << "    5. Tìm kiếm hàng hóa." << endl
             << "    6. Báo cáo tồn kho." << endl
             << "    7. Báo cáo sắp hết hàng." << endl
             << "    8. Báo cáo hàng hết hạn." << endl
             << "    0. Quay lại menu chính." << endl
             << "    ---------------------------------" << endl;
    }
    void Menu1_2() {
        system("cls");
        cout << "    ---- QUẢN LÝ NHÀ CUNG CẤP ----" << endl
             << "    1. Thêm nhà cung cấp mới." << endl
             << "    2. Hiển thị danh sách nhà cung cấp." << endl
             << "    3. Cập nhật thông tin nhà cung cấp." << endl
             << "    4. Tìm kiếm nhà cung cấp." << endl
             << "    0. Quay lại menu chính." << endl
             << "    ---------------------------------" << endl;
    }
    void Menu1_3_1() {
        system("cls");
        cout << "    ------- QUẢN LÝ NHẬP KHO -------" << endl
             << "    1. Tạo phiếu nhập kho." << endl
             << "    3. Hiển thị danh sách phiếu nhập kho." << endl
             << "    5. Tìm kiếm phiếu nhập kho." << endl
             << "    0. Quay lại menu chính." << endl
             << "    -------------------------------------" << endl;
    }
    void Menu1_3_2() {
        system("cls");
        cout << "    ------- QUẢN LÝ XUẤT KHO -------" << endl
             << "    2. Tạo phiếu xuất kho." << endl
             << "    4. Hiển thị danh sách phiếu xuất kho." << endl
             << "    6. Tìm kiếm phiếu xuất kho." << endl
             << "    0. Quay lại menu chính." << endl
             << "    -------------------------------------" << endl;
    }
    void Menu1_4() {
        system("cls");
        cout << "    ------- BÁO CÁO VÀ THỐNG KÊ -------" << endl
             << "    1. Thống kê doanh thu trong khoảng thời gian." << endl
             << "    0. Quay lại menu chính." << endl
             << "    -------------------------------------" << endl;
    }

    void clear_input_buffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
};