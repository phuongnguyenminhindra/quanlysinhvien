#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, delta, x1, x2;
    cout << "Nhap gia tri a, b, c: " << endl;
    cin >> a >> b >> c;
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem " << endl;
            } else {
                cout << "Phuong trinh vo nghiem " << endl;
            }
        } else {
            cout << "Nghiem cua phuong trinh la x = " << -c / b << endl;
        }
    } else {
        delta = (b * b - 4 * a * c);
        
        // Sửa: Kiểm tra trực tiếp delta, bổ sung đủ 3 trường hợp
        if (delta > 0) {
            // Sửa: Đóng ngoặc (2 * a)
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a) << endl;
        } else {
            cout << "Phuong trinh vo nghiem" << endl;
        }
    }
    
    return 0;
}