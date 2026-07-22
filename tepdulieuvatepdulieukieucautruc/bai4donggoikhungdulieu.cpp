#include<iostream>
#include<fstream>
using namespace std;
#pragma pack(push, 1) // Đảm bảo không có padding
struct DataFrame{
    unsigned short  SyncWord;// 2 bytes
    unsigned char DeviceID;// 1 byte
    unsigned char PayloadLength;//  1 byte
    float Payload[4];// 4*4 = 16 bytes
    unsigned char Checksum;// 1 byte

};
#pragma pack(pop) // Trở lại cấu hình padding mặc định
int main(){
    cout << "Size of DataFrame: " << sizeof(DataFrame) << " bytes" << endl;//Kiểm tra kích thước của cấu trúc dữ liệu
    DataFrame frame;
    frame.SyncWord = 0xABCD;
    frame.DeviceID = 0x15; // ID của thiết bị (hệ thập phân là 21)
    frame.PayloadLength = 16;
    frame.Payload[0] = 25.5; // Nhiệt độ
    frame.Payload[1] = 60.2; // Độ ẩm
    frame.Payload[2] = 1.5;  // Vận tốc gió
    frame.Payload[3] = 99.8; // Áp suất
    frame.Checksum = 0xFF;   // Giả sử checksum tính ra là 0xFF
    //Ghi dữ liệu vào file nhị phân
    ofstream outBin("data_frame.bin", ios::binary);// Mở file nhị phân để ghi
    //ép kiểu con trỏ của cấu trúc dữ liệu thành char* để ghi toàn bộ dữ liệu vào file,ghi đúng 21 bytes
    //ép kiểu chỉ có tính chất tạm thời để ghi dữ liệu nhị phân vào file
    if(outBin.is_open()){
        outBin.write((char*)(&frame), sizeof(DataFrame));// Ghi toàn bộ cấu trúc dữ liệu vào file nhị phân
        outBin.close();
        cout << "Data frame written to data_frame.bin" << endl;
    }
    //Đọc file nhị phân để kiểm tra
    ifstream inBin("data_frame.bin", ios::binary);
    if(inBin.is_open()){
        inBin.read((char*)(&frame), sizeof(DataFrame));
    // đọc đúng 21 bytes từ file nhị phân và lưu vào cấu trúc dữ liệu, ép kiểu chỉ có tính chất tạm thời để đọc dữ liệu nhị phân vào cấu trúc dữ liệu      
    inBin.close();
        cout << "Data frame read from data_frame.bin" << endl;
        cout << "SyncWord: " << hex << frame.SyncWord << dec << endl;
        cout << "DeviceID: " << (int)frame.DeviceID << endl;
        cout << "Temperature: " << frame.Payload[0] << endl;
        cout << "Humidity: " << frame.Payload[1] << endl;
        cout << "WindSpeed: " << frame.Payload[2] << endl;
        cout << "Pressure: " << frame.Payload[3] << endl;
    }
}
