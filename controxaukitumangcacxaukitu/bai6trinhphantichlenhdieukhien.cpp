#include <iostream>
using namespace std;

char** parseATCommands(const char* buffer, char delimiter, int out_count){
    char** commandArray = new char*[out_count];// cấp phát mảng 2 chiều
    int index =0;
    const char* start = buffer;
    const char* end = buffer;
    while(*end != '\0'){
        if(*end == delimiter){
            int len = end -start;
            commandArray[index] = new char[len+1];
            char *dest = commandArray[index];
            while(start < end){
            *dest= *start;
            start++;
            dest++;
            }
            *dest = '\0';
            start = end+1;
            index++;

        }
        end++;
    }
    return commandArray;
}
int main(){
    const char* rx_buffer = "AT+OK;+CMTI:\"SM\",1;RING;";
    cout << "He thong phan tich lenh " << endl;
    
    const char* temp = rx_buffer;
    int count = 0;
    while(*temp != '\0'){
        if(*temp == ';'){
            count++;
        }
       temp++;
    }
    cout << "Tim thay " << count << " lenh " << endl;
    char **payload = parseATCommands(rx_buffer,';', count);
    for(int i = 0; i < count; i++){
        cout << "[" << i + 1 << "] " << payload[i] << endl;
    }
    for(int i = 0; i < count; i++){
        delete[] payload[i]; // xóa các mảng con
        
    }
    delete [] payload; // xóa mảng chính

}