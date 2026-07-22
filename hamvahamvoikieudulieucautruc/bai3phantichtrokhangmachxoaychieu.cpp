#include<iostream>
#include<string>
using namespace std;
struct linhKien{
    string ten; 
    double giaTri;
    double tanSo;
};
double tinhTroKhang(linhKien &lk){
    double z;
    if(lk.ten == "R"){
        z = lk.giaTri;
    }
    else if(lk.ten == "L"){
        z = 2 * 3.14 * lk.tanSo * lk.giaTri;
    }
    else if(lk.ten == "C"){
        if(lk.giaTri == 0 || lk.tanSo == 0){
            return 0; // Tránh chia cho 0
        }else{
        z = 1 / (2 * 3.14159 * lk.tanSo * lk.giaTri);
        }
    }
    return z;
}
int main(){
    int n;
    cout << "Nhập số lượng linh kiện: ";
    cin >> n;
    cin.ignore();
    linhKien *lk = new linhKien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhập tên linh kiện (R, L, C): ";
        getline(cin, lk[i].ten);
        cout << "Nhập giá trị: ";
        cin >> lk[i].giaTri;
        cout << "Nhập tần số: ";
        cin >> lk[i].tanSo;
        cin.ignore(); // cin.ignore(); trước khi nhập chuỗi
    }
    for(int i = 0; i < n; i++){
        double troKhang = tinhTroKhang(lk[i]);
        cout << "Trở kháng của linh kiện " << lk[i].ten << " là: " << troKhang << " Ohm" << endl;
    }
    delete[] lk; // Giải phóng bộ nhớ đã cấp phát
}