#include <iostream>
#include<string>
using namespace std;
struct capQuang{
    string maTuyen;
    string loaiCap;
    float chieuDai;
    float suyHaoTong;
    float heSoSuyHao;

};
float tinhHeSoSuyHao(capQuang &cq){
    float result = (float)cq.suyHaoTong/cq.chieuDai;
    return result;
}
int main(){
    int n;
    
    cout << "Nhập danh sách tuyến cáp quang " << endl;
    cin >> n;
    cin.ignore();
    capQuang cq[n];
    for(int i = 0; i < n; i++){
        getline(cin, cq[i].maTuyen);
        getline(cin, cq[i].loaiCap);
        cin >> cq[i].chieuDai;
        cin >> cq[i].suyHaoTong;
        cin.ignore(); // cin.ignore(); trước khi nhập chuỗi
    }
    for(int i = 0; i<n; i++){
        cq[i].heSoSuyHao = tinhHeSoSuyHao(cq[i]);
        if(cq[i].heSoSuyHao > 0.3){
            cout << cq[i].maTuyen << " cần bảo trì " <<  endl;
   
        }
    }
}