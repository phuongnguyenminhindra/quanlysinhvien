#include <iostream>
using namespace std;
void reverseSignal(char* ptr){
    char *ptr1 = ptr;// ptr mang địa chỉ của số thứ 0
if(ptr1 == nullptr || *ptr1 == '\0'){
    return;
}
    while(*ptr1 != '\0'){
        ptr1++; //ptr1 trỏ đến vị trí 1
    }// ptr1 mang địa chỉ của số thứ 9
    ptr1--;// lùi lại 1 bước do đang trỏ đến vị trí \0
    while(ptr < ptr1){ // so sánh được như vậy là do địa chỉ trong một mảng tăng dần ví dụ 0x10-0x17 chứ không phải 123456
        char temp = *ptr;
        *ptr = *ptr1;
        *ptr1 = temp;
        ptr++;
        ptr1--;

    }

}

int main(){
    char signal[] = "11001010";
    cout << "Truoc khi dao " << signal << endl;
    reverseSignal(signal);
    cout << "Sau khi dao " << signal << endl;


}