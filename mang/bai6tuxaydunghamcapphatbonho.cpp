#include <iostream>
#include <cstdint>
using namespace std;
#define HEAP_SIZE 1024
uint8_t heapmemory[HEAP_SIZE];
struct blockRecord{
    bool isused;// trống(false) còn(true)
    uint16_t startidx;// bắt đầu ở số nào
    uint16_t size; // cần bao nhiêu chỗ
};
blockRecord ledger[100]; // có tối đa 100 lần
uint8_t totalblocks = 1; // đã đến dòng thứ bao nhiêu

void initmemorypool(){// trang 1 
    ledger[0].isused = false; //trống
    ledger[0].startidx = 0; // bắt đầu từ 0
    ledger[0].size = HEAP_SIZE; // trống 1024
}
void printledger() {
    cout << "--- SO QUAN LY BO NHO ---" << endl;
    for (uint8_t i = 0; i < totalblocks; i++) {
        cout << "Block " << (int)i << " | Trang thai: " << (ledger[i].isused ? "[DA THUE]" : "[TRONG  ]") 
             << " | Index bat dau: " << ledger[i].startidx 
             << " | Kich thuoc: " << ledger[i].size << " bytes" << endl;
    }
    cout << "-------------------------\n" << endl;
}
uint8_t* mymalloc(uint16_t requestedsize){
    for(uint8_t i = 0; i < totalblocks; i++){
        if(!ledger[i]. isused && ledger[i]. size >= requestedsize){
            ledger[i].isused = true;
            if(ledger[i].size > requestedsize){
                ledger[totalblocks].isused = false;
                ledger[totalblocks].startidx = ledger[i].startidx + requestedsize;
                ledger[totalblocks].size = ledger[i].size - requestedsize ;
        

                ledger[i].size = requestedsize;
                totalblocks++;
            }
            return &heapmemory[ledger[i].startidx];
        }

    }
    return NULL;
}
void myfree(uint8_t* ptr){
    if(ptr == NULL) return;
    uint16_t targetidx = ptr - heapmemory;
    for(uint8_t i = 0; i <totalblocks ; i++){
        if(ledger[i].startidx == targetidx && ledger[i].isused){
            ledger[i].isused = false;
            return;
        }
    }
}

int main(){
    initmemorypool();
    cout << "Ban dau" << endl;
    printledger();

    cout << "10 bytes" << endl;
    uint8_t* ptr1 = mymalloc(10);
    printledger();
    cout << "20 bytes" << endl;
    uint8_t* ptr2 = mymalloc(20);
    printledger();
    cout << "5 bytes" << endl;
    uint8_t *ptr3 = mymalloc(5);
    printledger();
}