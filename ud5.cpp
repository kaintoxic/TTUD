#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_SIZE = 1000;

// Hàm s?p x?p m?ng gi?m d?n
void sortDesc(double arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm tìm d? chênh l?ch nh? nh?t có th? khi chia m?ng
double findMinDiff(double arr[], int n) {
    // S?p x?p m?ng gi?m d?n
    sortDesc(arr, n);
    
    double group1[MAX_SIZE], group2[MAX_SIZE];
    int size1 = 0, size2 = 0;
    double sum1 = 0, sum2 = 0;
    
    // Phân ph?i các ph?n t? vào 2 nhóm
    for(int i = 0; i < n; i++) {
        if(sum1 <= sum2) {
            group1[size1] = arr[i];
            sum1 += arr[i];
            size1++;
        } else {
            group2[size2] = arr[i];
            sum2 += arr[i];
            size2++;
        }
    }
    
    // In k?t qu?
    cout << "\nNhom P: ";
    for(int i = 0; i < size1; i++) {
        cout << group1[i] << " ";
    }
    cout << "\nTong nhom P = " << sum1;
    
    cout << "\nNhom Q: ";
    for(int i = 0; i < size2; i++) {
        cout << group2[i] << " ";
    }
    cout << "\nTong nhom Q = " << sum2;
    
    return abs(sum1 - sum2);
}

int main() {
    int n;
    double arr[MAX_SIZE];
    
    cout << "Nhap so phan tu cua tap A: ";
    cin >> n;
    
    if(n > MAX_SIZE) {
        cout << "So phan tu vuot qua gioi han!\n";
        return 1;
    }
    
    cout << "Nhap " << n << " so duong:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] <= 0) {
            cout << "Vui long nhap so duong!\n";
            i--;
        }
    }
    
    double minDiff = findMinDiff(arr, n);
    cout << "\nDo lech nho nhat giua 2 nhom: " << minDiff << endl;
    
    return 0;
}
