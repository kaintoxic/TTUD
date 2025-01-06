#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ham tim day con chung dai nhat giua hai day a va b
vector<int> longest_common_subsequence(vector<int>& a, vector<int>& b) {
    int m = a.size(), n = b.size();  // Lay do dai cua hai day
    // Tao bang DP de luu tru do dai LCS tai cac vi tri (i, j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Tao bang DP
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1])  // Neu phan tu tuong ung cua hai day giong nhau
                dp[i][j] = dp[i-1][j-1] + 1;  // Cap nhat gia tri LCS tai dp[i][j]
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  // Lay gia tri lon nhat giua cac kha nang
        }
    }

    // Truy vet lai de tim day con chung dai nhat
    vector<int> result;  // Mang luu ket qua LCS
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {  // Neu phan tu a[i-1] va b[j-1] giong nhau
            result.push_back(a[i-1]);  // Them phan tu vao ket qua
            i--; j--;  // Di chuyen ve phia sau trong hai day
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;  // Neu LCS ben a dai hon, di chuyen trong day a
        else j--;  // Neu LCS ben b dai hon, di chuyen trong day b
    }

    reverse(result.begin(), result.end());  // Dao nguoc ket qua de ra day con chung dúng th? t?
    return result;  // Tra ve ket qua
}

int main() {
    int m, n;
    cout << "Nhap so phan tu day thu nhat: ";
    cin >> m;  // Nhap do dai day a
    vector<int> a(m);
    cout << "Nhap day thu nhat: ";
    for(int i = 0; i < m; i++) cin >> a[i];  // Nhap day a
    
    cout << "Nhap so phan tu day thu hai: ";
    cin >> n;  // Nhap do dai day b
    vector<int> b(n);
    cout << "Nhap day thu hai: ";
    for(int i = 0; i < n; i++) cin >> b[i];  // Nhap day b
    
    // Goi ham findLCS de tim day con chung dai nhat
    vector<int> lcs = longest_common_subsequence(a, b);
    
    // In ra ket qua
    cout << "\nDay con chung dai nhat: ";
    for(int x : lcs) cout << x << " ";  // In day con chung
    cout << "\nDo dai day con chung: " << lcs.size() << endl;  // In do dai day con chung
    
    return 0;
}

