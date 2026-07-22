#include <iostream>
using namespace std;
char* encapsulateFrame(const char** params, int size, char separator){
    int total_length = 0;
    for(int i = 0; i< size; i++){
        
        const char* currentData = params[i];
        while(*currentData != '\0'){
            ++total_length;
             currentData++;
        }
        
    }
    int result = total_length + size-1 +1;
    char* frame = new char[result];
    char* ptr = frame;
    for(int i = 0; i< size; i++){
        
        const char* currentData = params[i];
        while(*currentData != '\0'){
        *ptr = *currentData;
        ptr++;
        currentData++;
        }
        if(i<size -1){
            *ptr = separator;
            ptr++;
        }

}
*ptr = '\0';
return frame;// trả về địa chỉ ô nhớ của frame
}
int main(){
    const char* data[] = {"NODE01", "25C", "70%", "BAT99"};
    char a =  '-';
    int total = sizeof(data)/sizeof(data[0]);
    char* payload = encapsulateFrame(data, total, a);// payload tính nhưng trỏ đến vùng được cấp phát động
    if(payload != nullptr){
        cout << payload << endl;
        delete[] payload ;
    }

}