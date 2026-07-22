#include<iostream>
using namespace std;
struct senSor{
    int id;
    int adcValue;
    float Voltage;
};
void convertToVoltage(senSor &s){
    s.Voltage = (s.adcValue / 1023.0) * 5.0; // Giả sử điện áp tối đa là 5V và ADC có độ phân giải 10 bit
}
int main(){
    int n;
    cout << "Nhập số lượng cảm biến: ";
    cin >> n;
    senSor *sensors = new senSor[n];// Khai báo mảng động để lưu thông tin cảm biến
    for(int i = 0; i < n; i++){
        
        cin >> sensors[i].id;
       
        cin >> sensors[i].adcValue;
        convertToVoltage(sensors[i]);
    }
    for(int i = 0; i < n; i++){
        cout << "Cảm biến ID: " << sensors[i].id << ", Giá trị ADC: " << sensors[i].adcValue << ", Điện áp: " << sensors[i].Voltage << " V" << endl;
    }
    cout << "\nCác cảm biến có điện áp lớn hơn 4.0V:" << endl;
    for(int i = 0; i < n; i++){
        if(sensors[i].Voltage > 4.0){
            cout << "Cảm biến ID: " << sensors[i].id << " có điện áp lớn hơn 4.0V" << endl;
        }
    }
    delete[] sensors; // Giải phóng bộ nhớ đã cấp phát
}
