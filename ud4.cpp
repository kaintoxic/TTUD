#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

pair<vector<int>, int> maxAmplitudeSequence(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {{}, 0}; // N?u m?ng r?ng, tr? v? k?t qu? m?c d?nh
    
    vector<int> dp(n, 1);  // dp[i] là d? dài c?a subsequence tang d?n k?t thúc t?i arr[i]
    vector<int> prev(n, -1);  // prev[i] luu ch? s? ph?n t? tru?c arr[i] trong subsequence
    
    // Tìm subsequence dài nh?t tang d?n
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Tìm subsequence dài nh?t
    int maxLength = 0, maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    // Xây d?ng subsequence dài nh?t tang d?n
    vector<int> longestSeq;
    int amplitude = INT_MIN, seqMin = arr[maxIndex], seqMax = arr[maxIndex];
    while (maxIndex != -1) {
        longestSeq.push_back(arr[maxIndex]);
        seqMin = min(seqMin, arr[maxIndex]);
        seqMax = max(seqMax, arr[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    // Ð?o ngu?c l?i subsequence vì dã xây d?ng t? cu?i
    reverse(longestSeq.begin(), longestSeq.end());
    amplitude = seqMax - seqMin;  // Tính amplitude

    return make_pair(longestSeq, amplitude);
}

int main() {
    int n;
    cout << "Nhap so phan tu cua day: ";
    cin >> n;
    
    // Ki?m tra xem ngu?i dùng nh?p n có h?p l? không
    if (n <= 0) {
        cout << "So phan tu phai lon hon 0. Vui long nhap lai!" << endl;
        return 0;
    }
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cout << "So thu " << i+1 << ": ";
        cin >> arr[i];
    }
    
    // G?i hàm maxAmplitudeSequence và nh?n k?t qu?
    pair<vector<int>, int> result = maxAmplitudeSequence(arr);
    vector<int> sequence = result.first;  // Dãy con có biên d? l?n nh?t
    int amplitude = result.second;  // Biên d? c?a dãy con
    
    // In ra dãy con và biên d?
    cout << "\nchuoi con tang lien tuc co bien do lon nhat : ";
    for (int x : sequence) cout << x << " ";
    cout << "\nbien do: " << amplitude << endl;
    
    return 0;
}

