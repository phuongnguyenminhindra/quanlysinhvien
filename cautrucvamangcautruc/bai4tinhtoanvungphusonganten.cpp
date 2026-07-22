#include<iostream>
#include<string>
#include<math.h>
using namespace std;
struct toaDo{
    double x;
    double y;
};
struct anTen{
    string tenTram;
    toaDo viTri;
    double banKinhPhuSong;
};

int main(){
    anTen at;
    cout << "Nhập thông tin cho trạm " << endl;
    getline(cin, at.tenTram);
    cin >> at.viTri.x;
    cin >> at.viTri.y;
    cin >> at.banKinhPhuSong;
    toaDo user;
    cout << "Nhập vào tọa độ của người dùng " << endl;
    cin >> user.x;
    cin >> user.y;
    double d;
    d = sqrt((user.x-at.viTri.x)*(user.x-at.viTri.x)+(user.y-at.viTri.y)*(user.y-at.viTri.y));
    if(d <= at.banKinhPhuSong){
        cout << "Có sóng" << endl;

    }else{
        cout << "Out of coverage" << endl;
    }



}