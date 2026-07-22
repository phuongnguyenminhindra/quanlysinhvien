#include<iostream>
using namespace std;
struct packet{
    int id;
    int data[4];
    int checksum;
};
void taoPacket(packet &p){
    cout << "Nhập ID: ";
    cin >> p.id;
    cout << "Nhập dữ liệu (4 số nguyên): ";
    for(int i = 0; i < 4; i++){
        cin >> p.data[i];
    }
    p.checksum = 0;
    for(int i = 0; i < 4; i++){
        p.checksum += p.data[i];
    }
}
bool kiemTraGoiTin(const packet &p){
    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum += p.data[i];
    }
    return sum == p.checksum;
}
void hienThi(packet ds[], int n){
    for(int i = 0; i < n; i++){
        bool valid = kiemTraGoiTin(ds[i]);
        if(valid){
            cout << "Packet ID: " << ds[i].id << " is valid." << endl;
        } else {
            cout << "Packet ID: " << ds[i].id << " is invalid." << endl;
        }
        
    }
}
int main(){
    int n;
    cout << "Nhập số lượng packet: ";
    cin >> n;
    packet *ds = new packet[n];
    for(int i = 0; i < n; i++){
        taoPacket(ds[i]);
    }
    
    cout << "Chỉnh sửa dữ liệu để test hàm hienThi: " << endl;
    ds[1].data[1] = 999; // Thay đổi một giá trị để tạo ra packet không hợp lệ
    ds[3].data[2] = 888; // Thay đổi một giá trị khác để tạo ra packet không hợp lệ
    hienThi(ds, n);

    delete[] ds; // Giải phóng bộ nhớ đã cấp phát
}
