#include <iostream>
using namespace std;

// Hàm tìm và trích xuất giá trị số từ một bản tin
int extractSensorValue(const char* data, const char* key) {
    const char* ptr = data;
    const char* matchEnd = nullptr; // Con trỏ lưu vị trí ngay sau khi tìm thấy key

    // Bước 1: Tìm chuỗi key ("SOIL_MOISTURE:") bên trong chuỗi data
    while (*ptr != '\0') {
        if (*ptr == *key) { // Nếu thấy kí tự đầu tiên khớp nhau
            const char* tempData = ptr;
            const char* tempKey = key;
            
            // Tiếp tục so sánh các kí tự tiếp theo
            while (*tempData != '\0' && *tempKey != '\0' && *tempData == *tempKey) {
                tempData++;
                tempKey++;
            }
            
            // Nếu con trỏ tempKey đã trượt đến '\0', tức là đã khớp toàn bộ chữ "SOIL_MOISTURE:"
            if (*tempKey == '\0') {
                matchEnd = tempData; // Đặt con trỏ vào ngay sau dấu ':'
                break; // Thoát vòng lặp tìm kiếm
            }
        }
        ptr++; // Nếu không khớp, trượt tiếp con trỏ data
    }

    // Nếu duyệt hết chuỗi mà không tìm thấy key
    if (matchEnd == nullptr) {
        return -1; // Trả về -1 (mã lỗi)
    }

    // Bước 2: Dịch các kí tự số thành số nguyên (Thuật toán ASCII to Integer)
    int result = 0;
    const char* numPtr = matchEnd;
    
    // Vòng lặp chỉ chạy khi kí tự hiện tại nằm trong dải số từ '0' đến '9'
    while (*numPtr >= '0' && *numPtr <= '9') {
        // Công thức: Cập nhật hàng đơn vị, chục, trăm... và trừ đi mã ASCII của '0'
        result = result * 10 + (*numPtr - '0');
        numPtr++; // Trượt sang kí tự số tiếp theo
    }

    return result;
}

int main() {
    // Luồng dữ liệu giả lập từ cổng Serial (UART)
    char rx_data[] = "SOIL_MOISTURE:65%;STATUS:OK";
    
    cout << "Ban tin nhan duoc: " << rx_data << endl;
    
    // Trích xuất giá trị
    int moisture = extractSensorValue(rx_data, "SOIL_MOISTURE:");
    
    // Kiểm tra và in kết quả
    if (moisture != -1) {
        cout << "[XU LY] Do am dat la: " << moisture << "%" << endl;
    } else {
        cout << "[LOI] Khong tim thay du lieu SOIL_MOISTURE!" << endl;
    }

    return 0;
}