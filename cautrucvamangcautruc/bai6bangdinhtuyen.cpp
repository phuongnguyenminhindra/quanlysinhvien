#include<iostream>
#include<string>
using namespace std;
struct route{
    string diaChiMang;
    string congXuat;
    int metric;
};
int main(){
    cout << "Nhập số lượng tuyến: ";
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character left in the buffer
    route rt[n];
    for(int i = 0; i < n; i++){
        
        getline(cin, rt[i].diaChiMang);
        getline(cin, rt[i].congXuat);
        cin >> rt[i].metric;
        cin.ignore(); // Ignore the newline character left in the buffer
    }
    cout << "Danh sách tuyến: " << endl;
    for(int i = 0; i < n; i++){ 
        cout << "Địa chỉ mạng: " << rt[i].diaChiMang << endl;
        cout << "Công xuất: " << rt[i].congXuat << endl;
        cout << "Metric: " << rt[i].metric << endl;
    }
    cout << "Nhập vào địa chỉ cần tìm: " << endl;
    string targetIP;
    getline(cin, targetIP);
    bool timThay = false;
    string congXuatMin = "";
    int min = 9999999; // Khởi  tạo min với giá trị lớn nhất có thể
    for(int i = 0; i < n; i++){
        if(rt[i].diaChiMang == targetIP){
            
            timThay = true;
           
            if(rt[i].metric < min){
                min = rt[i].metric;
                congXuatMin = rt[i].congXuat;
            
                    
                }
            }
            
        }
    
    if(timThay){
        cout << "Metric nhỏ nhất của địa chỉ " << targetIP << " là: " << min << " qua cổng " << congXuatMin << endl;
    } else {
        cout << "Không tìm thấy địa chỉ " << targetIP << endl;
    }
    
    
   
    
    
}