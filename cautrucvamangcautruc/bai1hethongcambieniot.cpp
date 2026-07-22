#include<iostream>
#include<string>
using namespace std;
struct camBien{
    string maCB;
    string viTri;
    float nhietDo;
    float doAm;
};

int main(){
    camBien cB1;
    cout << "Nhập thông tin cho cảm biến " << endl;
    getline(cin, cB1.maCB);
    getline(cin,cB1.viTri);
  // chỉ dùng cin.ignore(); sau cin và trước getline;
    cin >> cB1.nhietDo;
    cin >> cB1.doAm;
    if((cB1.nhietDo > 35.0) || (cB1.doAm > 80.0)){
        cout <<"[ALARM] Môi trường tại " << cB1.viTri <<  " không đạt chuẩn!" << endl;
    }else{
        cout << "[OK] Hệ thống ổn định." << endl;
    }
}