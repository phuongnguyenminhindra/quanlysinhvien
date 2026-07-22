#include<iostream>
#include<string>
using namespace std;
struct thueBao{
    string soDienThoai;
    string goiCuoc;
    float luuluongData;
    long long tienTaiKhoan;

};

int main(){
    cout << "Nhập số lượng thuê bao: ";
    int n;
    cin >> n;
    thueBao tb[n];
    for(int i = 0; i < n; i++){
        cout << "Nhập số điện thoại: ";
        cin >> tb[i].soDienThoai;
        cout << "Nhập gói cước: ";
        cin >> tb[i].goiCuoc;
        cout << "Nhập lưu lượng data: ";
        cin >> tb[i].luuluongData;
        cout << "Nhập tiền tài khoản: ";
        cin >> tb[i].tienTaiKhoan;
    }
    cout << "Danh sách thuê bao: " << endl;
    for(int i = 0; i < n; i++){ 
        cout << "Số điện thoại: " << tb[i].soDienThoai << endl;
        cout << "Gói cước: " << tb[i].goiCuoc << endl;
        cout << "Lưu lượng data: " << tb[i].luuluongData << endl;
        cout << "Tiền tài khoản: " << tb[i].tienTaiKhoan << endl;
    }
   
    for(int i = 0; i < n-1; i++){
       for(int j = i+1; j < n; j++){
            if(tb[i].tienTaiKhoan < tb[j].tienTaiKhoan){
                thueBao temp = tb[i];
                tb[i] = tb[j];
                tb[j] = temp;
            }
        }
    }
   

    cout << "Danh sách thuê bao sau khi sắp xếp: " << endl;
    for(int i = 0; i < n; i++){ 
        cout << "Số điện thoại: " << tb[i].soDienThoai << endl;
        cout << "Gói cước: " << tb[i].goiCuoc << endl;
        cout << "Lưu lượng data: " << tb[i].luuluongData << endl;
        cout << "Tiền tài khoản: " << tb[i].tienTaiKhoan << endl;
    }
    cout << "Danh sách thuê bao có tiền tài khoản lớn hơn 50000 và lưu lượng data bằng 0: " << endl;
    for(int i = 0; i < n; i++){
        if((tb[i].tienTaiKhoan > 50000) && (tb[i].luuluongData <= 0)){
            cout << "Số điện thoại: " << tb[i].soDienThoai << endl;
            
        }
    }
    

}   
