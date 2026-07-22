#include <iostream>
#include<string.h>
using namespace std;
int getStrLen(const char* str){
    int count =0;
   while(*str != '\0'){
    if(*str >=32 && *str<=122){
        count++;
    }str++;
   }
   return count;
        
        }
int main(){
    char msg[] = "He thong tuoi cay tu dong";
    int result = getStrLen(msg);
    cout << result << endl; 
    if(result >16){
            cout << "Đa vuot qua ki tu tren 1 dong";
}
}