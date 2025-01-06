#include <iostream>
#include <conio.h>
using namespace std;

void nhapmang(int*& a, int& n) {
    do {
        cout << "Nhap so phan tu (n > 0): ";
        cin >> n;
    } while (n <= 0);
    
    // cap phat dong mang
    a = new int[n];
    
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void inMang(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void timLCS(int* a, int n, int* b, int m) {
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[m + 1]{0};
    }
    
    // Xây d?ng b?ng dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    // Truy v?t
    int* lcs = new int[min(n, m)];
    int len = 0;
    int i = n, j = m;
    
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[len++] = a[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    
    // In k?t qu?
    cout << "\nDo dai day con chung: " << len << endl;
    cout << "Day con chung dai nhat la: ";
    for (i = len - 1; i >= 0; i--)
        cout << lcs[i] << " ";
    
    // Gi?i phóng b? nh?
    delete[] lcs;
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
}

int main() {
    int* a = nullptr;
    int* b = nullptr;
    int n, m;
    
    cout << "Nhap day so thu nhat:\n";
    nhapmang(a, n);
    
    cout << "\nNhap day so thu hai:\n";
    nhapmang(b, m);
    
    cout << "\nDay thu nhat: ";
    inMang(a, n);
    cout << "Day thu hai: ";
    inMang(b, m);
    
    timLCS(a, n, b, m);
    
    // Gi?i phóng b? nh?
    delete[] a;
    delete[] b;
    
    getch();
    return 0;
}

