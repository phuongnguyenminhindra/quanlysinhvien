#include<iostream>
using namespace std;
void filterErrors(const char** packetArray, int size, const char *err_code){
    // ** là mảng các mảng
    for(int i = 0; i < size; i++ ){
        const char* currentPacket = packetArray[i];
        const char* tempPack = currentPacket;
        const char* tempErr = err_code;
        while(*tempPack != '\0' && *tempErr != '\0' && *tempPack == *tempErr){
            tempPack++;
            tempErr++;
        }
        if(*tempErr == '\0'){
            cout << "Goi tin loi " <<  packetArray[i] << endl;
        }

    }
}



int main(){
    const char* packets[] = {// char* giống như 1 mảng
    "TX_TEMP_35", 
    "ERR_NO_SIGNAL", 
    "TX_HUMID_80", 
    "ERR_CHECKSUM_FAIL", 
    "SYS_BOOT"
};
int total = sizeof(packets) / sizeof(packets[0]);
cout << "So luong goi tin " << total << endl;
filterErrors(packets, total, "ERR_");

cout << "Done " << endl;
 
}