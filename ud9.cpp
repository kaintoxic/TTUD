#include <iostream>
#include <algorithm>
using namespace std;

// C?u trúc d? luu thông tin v? cu?c h?p
struct Meeting {
    int start, finish, index;
};

// Hàm so sánh d? s?p x?p các cu?c h?p theo th?i gian k?t thúc
bool compare(Meeting a, Meeting b) {
    return a.finish < b.finish;
}

// Hàm tr? v? danh sách các cu?c h?p t?i da có th? ch?n
void maxMeetings(int start[], int finish[], int n) {
    // T?o m?ng các cu?c h?p
    Meeting meetings[n];
    
    // T?o các cu?c h?p
    for(int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].finish = finish[i];
        meetings[i].index = i;
    }
    
    // S?p x?p các cu?c h?p theo th?i gian k?t thúc
    sort(meetings, meetings + n, compare);
    
    // In ra các cu?c h?p dã ch?n
    cout << "\nDanh sach cac cuoc hop duoc chon: ";
    int lastFinish = meetings[0].finish;
    cout << meetings[0].index + 1 << " ";
    
    // Ch?n các cu?c h?p t?i da
    for(int i = 1; i < n; i++) {
        if(meetings[i].start >= lastFinish) {
            cout << meetings[i].index + 1 << " ";
            lastFinish = meetings[i].finish;
        }
    }
    
    cout << "\nSo cuoc hop toi da: ";
    int count = 1;
    lastFinish = meetings[0].finish;
    for(int i = 1; i < n; i++) {
        if(meetings[i].start >= lastFinish) {
            count++;
            lastFinish = meetings[i].finish;
        }
    }
    cout << count << endl;
}

int main() {
    int n;
    cout << "Nhap so cuoc hop: ";
    cin >> n;
    
    int start[n], finish[n];
    cout << "Nhap thoi gian bat dau va ket thuc cua tung cuoc hop:\n";
    
    // Nh?p th?i gian b?t d?u và k?t thúc cho t?ng cu?c h?p
    for(int i = 0; i < n; i++) {
        cout << "Cuoc hop " << i+1 << " (batdau ketthuc): ";
        cin >> start[i] >> finish[i];
    }
    
    // G?i hàm d? tìm danh sách các cu?c h?p t?i da
    maxMeetings(start, finish, n);
    
    return 0;
}

