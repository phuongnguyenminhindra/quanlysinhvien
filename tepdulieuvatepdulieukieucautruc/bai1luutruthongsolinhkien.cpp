#include<iostream>
#include<fstream>
#include<string>
#include<limits>
using namespace std;
struct Station{
    string maTram;
    double x,y,w;
};
void nhap(Station &s){
    
    getline(cin,s.maTram);
    
    cin>>s.x;

    cin>>s.y;
    
    cin>>s.w;
    cin.ignore();
    
    
}
void docFile(Station &s){
    ifstream in("tram.txt");//mo file de doc
    if(in.is_open()){
        getline(in,s.maTram);//giải quyết đọc chuỗi có dấu cách
        in>>s.x>>s.y>>s.w;
        in.close();
    }
}
int main(){
    Station s1,s2;
    ofstream out("tram.txt");//mo file de ghi
    if(out.is_open()){//mo file de ghi
        nhap(s1);//nhap thong tin tram vao s1
        out<<s1.maTram<<endl;//giải quyết đọc chuỗi có dấu cách
        out<<s1.x<<" "<<s1.y<<" "<<s1.w<<endl;//ghi vào file có dấu cách giữa các giá trị để thuận lợi cho việc đọc lại
        out.close();
    }
    docFile(s2);//doc file vao s2
    cout<<"Ma tram: "<<s2.maTram<<endl;
    cout<<"Toa do x: "<<s2.x<<endl;
    cout<<"Toa do y: "<<s2.y<<endl;
    cout<<"Trong so: "<<s2.w<<endl;

    return 0;
}
