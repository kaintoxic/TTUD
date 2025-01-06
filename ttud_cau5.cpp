#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Hàm tìm d? chênh l?ch nh? nh?t có th? khi chia m?ng
double findMinDiff(vector<double>& arr) {
    int n = arr.size();
    double totalSum = 0;
    for(double num : arr) {
        totalSum += num;
    }
    
    // S?p x?p m?ng d? t?i uu vi?c tìm ki?m
    sort(arr.begin(), arr.end(), greater<double>());
    
    vector<double> group1, group2;
    double sum1 = 0, sum2 = 0;
    
    // Phân ph?i các ph?n t? vào 2 nhóm
    for(double num : arr) {
        if(sum1 <= sum2) {
            sum1 += num;
            group1.push_back(num);
        } else {
            sum2 += num;
            group2.push_back(num);
        }
    }
    
    // In k?t qu?
    cout << "\nNhom P: ";
    for(double num : group1) {
        cout << num << " ";
    }
    cout << "\nTong nhom P = " << sum1;
    
    cout << "\nNhom Q: ";
    for(double num : group2) {
        cout << num << " ";
    }
    cout << "\nTong nhom Q = " << sum2;
    
    return abs(sum1 - sum2);
}

int main() {
    int n;
    cout << "Nhap so phan tu cua tap A: ";
    cin >> n;
    
    vector<double> arr(n);
    cout << "Nhap " << n << " so duong:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] <= 0) {
            cout << "Vui long nhap so duong!\n";
            i--;
        }
    }
    
    double minDiff = findMinDiff(arr);
    cout << "\nDo lech nho nhat giua 2 nhom: " << minDiff << endl;
    
    return 0;
}
