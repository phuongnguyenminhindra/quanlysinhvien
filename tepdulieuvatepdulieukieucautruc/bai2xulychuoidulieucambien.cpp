#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
struct SensorData{
    string time;
    double temperature;
    double humidity;
};
int readSensorData(SensorData data[], int max_size){
    ifstream in("sensor_log.csv");
    int count =0;
    if(in.is_open()){
        string line;
        while(getline(in,line) && count < max_size){
            if(line.empty()) continue; // Bỏ qua dòng trống
            stringstream ss(line);// Tách dòng thành các phần tử
            string timeStr, tempStr, humStr;
            getline(ss, timeStr, ',');// Đọc thời gian
            getline(ss, tempStr, ','); // Đọc nhiệt độ
            getline(ss, humStr, ',');// Đọc độ ẩm
            data[count].time = timeStr;
            data[count].temperature = stod(tempStr);// Chuyển đổi chuỗi nhiệt độ sang số thực
            data[count].humidity = stod(humStr);// Chuyển đổi chuỗi độ ẩm sang số thực
            count++;
        }
        in.close();
        
    }else{
        cout<<"Khong the mo file!"<<endl;
    }
    return count;
}
int main(){
    SensorData data[100];
    int count = readSensorData(data, 100);
    if(count == 0){
        cout<<"Khong co du lieu de xu ly!"<<endl;
        return 1;// Dừng chương trình nếu không có dữ liệu để xử lý
    }
    double averagetemperature=0;
    double totaltemperature=0;
    double averagehumidity=0;
    double totalhumidity=0;
    

    for(int i=0;i<100;i++){
        totaltemperature+=data[i].temperature;
        totalhumidity+=data[i].humidity;
         
    }
    averagetemperature=totaltemperature/count;
    averagehumidity=totalhumidity/count;        
    ofstream out("report.txt");

    if(out.is_open()){
        out<<"Average Temperature: "<<averagetemperature<<endl;
        out<<"Average Humidity: "<<averagehumidity<<endl;
        out.close();
        cout <<"Report generated successfully!"<<endl;
    }

}
