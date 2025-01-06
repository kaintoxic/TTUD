#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    
    vector<int> selected;
    int i = n, w = W;
    while(i > 0 && w > 0) {
        if(dp[i][w] != dp[i-1][w]) {
            selected.push_back(i-1);
            w -= weights[i-1];
        }
        i--;
    }
    
    return make_pair(dp[n][W], selected); // Su dung make_pair thay vi auto
}

int main() {
    int n, W;
    cout << "Nhap so do vat: ";
    cin >> n;
    
    vector<int> weights(n), values(n);
    cout << "Nhap trong luong va gia tri cua tung do vat:\n";
    for(int i = 0; i < n; i++) {
        cout << "Do vat " << i+1 << " (weight value): ";
        cin >> weights[i] >> values[i];
    }
    
    cout << "Nhap trong luong toi da cua ba lo: ";
    cin >> W;
    
    // Goi ham knapsack va lay gia tri tra ve
    pair<int, vector<int>> result = knapsack(weights, values, W);
    
    // In ra ket qua
    cout << "\nGia tri tong lon nhat: " << result.first;
    cout << "\nCac do vat duoc chon: ";
    for(int i : result.second) cout << i+1 << " ";
    cout << endl;
    
    return 0;
}

