#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
struct GPSinfo{
    int TrangThai;
    string time;
    double ViDo;
    double KinhDo;

};
int readGPSData(GPSinfo data[], int max_size){
    ifstream in("serial_rx.txt");
    int count =0;
    if(in.is_open()){
        string line;
        while(getline(in,line) && count < max_size){
            if(line.empty()) continue;
            if(line.find("CGNSINF:") != string::npos){
                //Nếu dòng hiện tại có chứa CGNSINF: thì bắt đầu cắt chuỗi
            
            stringstream ss(line);// Tách dòng thành các phần tử
            string waste, statusStr, timeStr, latStr, lonStr;
            getline(ss, waste, ','); // Bỏ qua phần tử đầu tiên
            getline(ss, statusStr, ',');// Đọc trạng thái
            getline(ss, timeStr, ','); // Đọc thời gian
            getline(ss, latStr, ',');// Đọc vĩ độ
            getline(ss, lonStr, ',');// Đọc kinh độ
            data[count].TrangThai = stoi(statusStr);// Chuyển đổi chuỗi trạng thái sang số nguyên
            data[count].time = timeStr;
            data[count].ViDo = stod(latStr);// Chuyển đổi chuỗi vĩ độ sang số thực
            data[count].KinhDo = stod(lonStr);// Chuyển đổi chuỗi kinh độ sang số thực
            count++;
            }
        }
        in.close();
        
    }else{
        cout<<"Khong the mo file!"<<endl;
    }
    return count;
}
int main(){
    GPSinfo data[100];
    int validCount = readGPSData(data, 100);
    ofstream out("valid_coords.txt");
    if(out.is_open()){
        for(int i=0;i<validCount;i++){//Tránh in ra những giá trị rác do đã có validCount
            if(data[i].TrangThai == 1){
                out<<"Time: "<<data[i].time<<", Latitude: "<<data[i].ViDo<<", Longitude: "<<data[i].KinhDo<<endl;
            }
        }
        out.close();
        cout<<"Valid coordinates saved to valid_coords.txt"<<endl;
    }else{
        cout<<"Khong the mo file de ghi!"<<endl;
    }
}