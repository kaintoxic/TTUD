#include <iostream>
#include <algorithm>
using namespace std;

// C?u tr�c d? luu th�ng tin v? cu?c h?p
struct Meeting {
    int start, finish, index;
};

// H�m so s�nh d? s?p x?p c�c cu?c h?p theo th?i gian k?t th�c
bool compare(Meeting a, Meeting b) {
    return a.finish < b.finish;
}

// H�m tr? v? danh s�ch c�c cu?c h?p t?i da c� th? ch?n
void maxMeetings(int start[], int finish[], int n) {
    // T?o m?ng c�c cu?c h?p
    Meeting meetings[n];
    
    // T?o c�c cu?c h?p
    for(int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].finish = finish[i];
        meetings[i].index = i;
    }
    
    // S?p x?p c�c cu?c h?p theo th?i gian k?t th�c
    sort(meetings, meetings + n, compare);
    
    // In ra c�c cu?c h?p d� ch?n
    cout << "\nDanh sach cac cuoc hop duoc chon: ";
    int lastFinish = meetings[0].finish;
    cout << meetings[0].index + 1 << " ";
    
    // Ch?n c�c cu?c h?p t?i da
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
    
    // Nh?p th?i gian b?t d?u v� k?t th�c cho t?ng cu?c h?p
    for(int i = 0; i < n; i++) {
        cout << "Cuoc hop " << i+1 << " (batdau ketthuc): ";
        cin >> start[i] >> finish[i];
    }
    
    // G?i h�m d? t�m danh s�ch c�c cu?c h?p t?i da
    maxMeetings(start, finish, n);
    
    return 0;
}

