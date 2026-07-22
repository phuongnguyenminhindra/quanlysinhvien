#include<iostream>
using namespace std;
float tinhNoiTiep(float r1, float r2){
    return r1 + r2;
}
float tinhSongSong(float r1, float r2){
    if(r1 == 0 || r2 == 0){
        return 0; // Tránh chia cho 0
    }
    return (r1 * r2) / (r1 + r2);
}
int main(){
    float r1, r2;
    cout << "Nhập vào hai điện trở r1 và r2: ";
    cin >> r1 >> r2;
    cout << "Tổng của r1 và r2 là: " << tinhNoiTiep(r1, r2) << "Ohm" << endl;
    cout << "Tổng song song của r1 và r2 là: " << tinhSongSong(r1, r2) << "Ohm" << endl;
}