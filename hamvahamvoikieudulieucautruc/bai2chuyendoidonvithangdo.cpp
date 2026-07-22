#include<iostream>
#include<cmath>
using namespace std;
float watttoDBm(float watt){
    if(watt <= 0){
        return -INFINITY; // Trường hợp công suất âm vô cùng
    }
    return 10 * log10(watt * 1000); // Chuyển đổi từ watt sang mW và tính dBm
}
float DBmtoWatt(float dBm){
    return pow(10, dBm / 10) / 1000; // Chuyển đổi từ dBm sang watt
}
int main(){
    float watt, dBm;
    cout << "Nhập công suất (Watt): ";
    cin >> watt;
    cout << "Công suất tương đương là: " << watttoDBm(watt) << " dBm" << endl;

    cout << "Nhập công suất (dBm): ";
    cin >> dBm;
    cout << "Công suất tương đương là: " << DBmtoWatt(dBm) << " Watt" << endl;
}