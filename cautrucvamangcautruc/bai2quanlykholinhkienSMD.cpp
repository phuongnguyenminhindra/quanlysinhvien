#include <iostream>
#include <string>
using namespace std;
struct linhKien{
    string tenLK;
    string loai;
    int soLuong;
    int donGia;

};

int main(){
    int n;
    cout << "Nhập vào số link kiện " << endl;
    cin >> n;
    cin.ignore();// trước lệnh nhập chuỗi do ở trước nhập số
    linhKien Lk[n];
    for(int i = 0; i < n; i++){
        getline(cin, Lk[i].tenLK);
        getline(cin, Lk[i].loai);
        cin >> Lk[i].soLuong;
        cin >> Lk[i].donGia;
        cin.ignore(); // cin.ignore(); trước khi nhập chuỗi
    }
    long long cost = 0;
    int minsoLuong = Lk[0].soLuong;
    string minTen = Lk[0].tenLK;
    for(int i =0; i<n;i++){
        cost+=(long long)Lk[i].soLuong*Lk[i].donGia;
        if(Lk[i].soLuong < minsoLuong){
            minsoLuong = Lk[i].soLuong;
            minTen = Lk[i].tenLK;

            
        }


    }
    cout << "Giá của tất cả link kiện trong kho là " << cost << endl;
    cout << "Linh kiện có số lượng tồn kho ít nhât là " << minTen << endl;
    


}