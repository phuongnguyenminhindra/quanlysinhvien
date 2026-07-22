#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct fiber {
    string MaCap;
    double ChieuDai_km;
    double HeSoSuyHao_db_km;
};

// Truyền luồng outFile và biến count bằng tham chiếu (&) để giữ nguyên giá trị qua các lần gọi
void test(fiber &f, ofstream &outFile, int &count) {
    //ofstream &outFile: Tham chiếu đến luồng ghi file, tránh việc mở/đóng file nhiều lần để ghi vào file mà không xóa dư liệu cũ
    bool isFaulty = false;
    string reason = "";

    // Dùng 2 lệnh if độc lập để bắt được kịch bản "Lỗi kép"
    if (f.HeSoSuyHao_db_km > 0.25) {
        isFaulty = true;
        reason += "He so suy hao vuot muc 0.25 dB/km. ";
    }

    if (f.ChieuDai_km * f.HeSoSuyHao_db_km > 5.0) {
        isFaulty = true;
        // Ghi chú chuẩn xác theo thiết kế kỹ thuật
        reason += "Tong suy hao vuot 5.0 dB (Cham den han che chuc nang vat ly cua san pham).";
    }

    // Nếu cáp có ít nhất 1 lỗi, tiến hành ghi file và tăng biến đếm tổng
    if (isFaulty) {
        count++;
        outFile << "Ma Cap: " << f.MaCap << endl;
        outFile << "Chieu Dai (km): " << f.ChieuDai_km << endl;
        outFile << "He So Suy Hao (dB/km): " << f.HeSoSuyHao_db_km << endl;
        outFile << "Ly do loi: " << reason << "\n" << endl; // Thêm \n để cách dòng cho dễ nhìn
    }
}

int main() {
    fiber f1;
    int count = 0; // Đếm tổng số cáp lỗi của toàn bộ mạng lưới

    ifstream inFile("fiber_test.dat");
    ofstream outFile("faulty_cables_log.txt"); // Mở file 1 lần duy nhất ở đây

    if (inFile.is_open() && outFile.is_open()) {
        outFile << "--- DANH SACH CAP QUANG LOI ---" << endl;

        // Đọc liên tục 3 giá trị phân cách bằng khoảng trắng cho đến khi hết file
        while (inFile >> f1.MaCap >> f1.ChieuDai_km >> f1.HeSoSuyHao_db_km) {
            test(f1, outFile, count); // Gọi hàm kiểm tra
        }

        // Sau khi quét xong toàn bộ mảng, in ra tổng số cáp lỗi
        outFile << "--------------------------------" << endl;
        outFile << "Tong so cap loi phat hien duoc: " << count << endl;

        inFile.close();
        outFile.close();
        cout << "Da phan tich xong! Kiem tra file faulty_cables_log.txt" << endl;
    } else {
        cout << "Loi: Khong the mo file doc hoac ghi!" << endl;
    }

    return 0;
}