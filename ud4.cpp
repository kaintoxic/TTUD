#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

pair<vector<int>, int> maxAmplitudeSequence(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {{}, 0}; // N?u m?ng r?ng, tr? v? k?t qu? m?c d?nh
    
    vector<int> dp(n, 1);  // dp[i] l� d? d�i c?a subsequence tang d?n k?t th�c t?i arr[i]
    vector<int> prev(n, -1);  // prev[i] luu ch? s? ph?n t? tru?c arr[i] trong subsequence
    
    // T�m subsequence d�i nh?t tang d?n
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // T�m subsequence d�i nh?t
    int maxLength = 0, maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    // X�y d?ng subsequence d�i nh?t tang d?n
    vector<int> longestSeq;
    int amplitude = INT_MIN, seqMin = arr[maxIndex], seqMax = arr[maxIndex];
    while (maxIndex != -1) {
        longestSeq.push_back(arr[maxIndex]);
        seqMin = min(seqMin, arr[maxIndex]);
        seqMax = max(seqMax, arr[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    // �?o ngu?c l?i subsequence v� d� x�y d?ng t? cu?i
    reverse(longestSeq.begin(), longestSeq.end());
    amplitude = seqMax - seqMin;  // T�nh amplitude

    return make_pair(longestSeq, amplitude);
}

int main() {
    int n;
    cout << "Nhap so phan tu cua day: ";
    cin >> n;
    
    // Ki?m tra xem ngu?i d�ng nh?p n c� h?p l? kh�ng
    if (n <= 0) {
        cout << "So phan tu phai lon hon 0. Vui long nhap lai!" << endl;
        return 0;
    }
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cout << "So thu " << i+1 << ": ";
        cin >> arr[i];
    }
    
    // G?i h�m maxAmplitudeSequence v� nh?n k?t qu?
    pair<vector<int>, int> result = maxAmplitudeSequence(arr);
    vector<int> sequence = result.first;  // D�y con c� bi�n d? l?n nh?t
    int amplitude = result.second;  // Bi�n d? c?a d�y con
    
    // In ra d�y con v� bi�n d?
    cout << "\nchuoi con tang lien tuc co bien do lon nhat : ";
    for (int x : sequence) cout << x << " ";
    cout << "\nbien do: " << amplitude << endl;
    
    return 0;
}

