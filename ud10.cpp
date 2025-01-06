#include <iostream>
using namespace std;

// Ham tim gia tri lon nhat giua hai so
int giaTriLonNhat(int a, int b) {
    if (a > b) {  
        return a;  
    } else {      
        return b;  
    }
}s

// Ham giai bai toan ba lo
void baLo(int W, int trongLuong[], int giaTri[], int n) {
    int dp[n + 1][W + 1];
    
    // Khoi tao bang dong voi gia tri 0
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (trongLuong[i - 1] <= w)
                dp[i][w] = giaTriLonNhat(giaTri[i - 1] + dp[i - 1][w - trongLuong[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    
    // In ket qua
    cout << "Gia tri toi da co the dat duoc la: " << dp[n][W] << endl;
    
    // Truy vet de tim cac do vat duoc chon
    cout << "\nCac do vat duoc chon la: " << endl;
    int giaTriMax = dp[n][W];
    int w = W;
    
    for (int i = n; i > 0 && giaTriMax > 0; i--) {
        if (giaTriMax != dp[i - 1][w]) {
            cout << "Do vat " << i << " (Trong luong: " << trongLuong[i - 1] 
                 << ", Gia tri: " << giaTri[i - 1] << ")" << endl;
            giaTriMax = giaTriMax - giaTri[i - 1];
            w = w - trongLuong[i - 1];
        }
    }
}

int main() {
    int n, W;
    
    cout << "Nhap so luong do vat: ";
    cin >> n;
    
    int trongLuong[n]; // Mang trong luong
    int giaTri[n]; // Mang gia tri
    
    cout << "Nhap trong luong va gia tri cua tung do vat:\n";
    for(int i = 0; i < n; i++) {
        cout << "Do vat " << i + 1 << ":\n";
        cout << "Trong luong: ";
        cin >> trongLuong[i];
        cout << "Gia tri: ";
        cin >> giaTri[i];
    }
    
    cout << "\nNhap trong luong toi da cua ba lo: ";
    cin >> W;
    
    baLo(W, trongLuong, giaTri, n);
    
    return 0;
}

