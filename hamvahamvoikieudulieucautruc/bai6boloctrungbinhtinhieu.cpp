#include<iostream>
using namespace std;
struct Signal{
    float rawSample[5];
    float filteredValue;
};
void filterSignal(Signal &s){
    float sum = 0;
    for(int i = 0; i < 5; i++){
        sum += s.rawSample[i];
    }
    s.filteredValue = sum / 5.0; // Lọc bằng cách lấy trung bình cộng
}
void addSample(Signal &s, float newSample){
    for(int i = 0; i < 4; i++){
        s.rawSample[i] = s.rawSample[i + 1]; // Dịch chuyển mẫu cũ sang trái
    }
    s.rawSample[4] = newSample; // Thêm mẫu mới vào cuối mảng
}
int main(){
    Signal s;
    s.rawSample[0] = 10;
    s.rawSample[1] = 10;
    s.rawSample[2] = 10;
    s.rawSample[3] = 10;
    s.rawSample[4] = 10; // Khởi tạo mẫu ban đầu
    filterSignal(s);
    cout << "Giá trị đã lọc(lần 1): " << s.filteredValue << endl;
    addSample(s, 12); // Thêm mẫu mới
    filterSignal(s);
    cout << "Giá trị đã lọc(lần 2): " << s.filteredValue << endl;
    addSample(s,99); // Thêm mẫu mới
    filterSignal(s);
    cout << "Giá trị đã lọc(lần 3): " << s.filteredValue << endl;
    addSample(s, 11); // Thêm mẫu mới
    filterSignal(s);
    cout << "Giá trị đã lọc(lần 4): " << s.filteredValue << endl;
    return 0;
}
