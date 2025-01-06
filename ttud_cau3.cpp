#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

pair<int, vector<pair<int,int>>> countPairs(vector<int>& A, int m) {
    // Dinh nghia set de luu tru cac cap phan tu (de loai bo cac cap trung lap)
    set<pair<int,int>> uniquePairs;
    int n = A.size();  // Lay kich thuoc cua mang A
    
    // Duyet qua tat ca cac cap (i, j) trong mang A
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            // So sanh tich cua hai phan tu va kiem tra xem co lon hon m khong
            if((long long)A[i] * A[j] > m) {
                // Chen cap moi vao set, dung min va max de cap duoc xep theo thu tu tang dan
                uniquePairs.insert(make_pair(min(A[i], A[j]), max(A[i], A[j])));
            }
        }
    }
    
    // Tao vector chua cac cap so tu set (set se tu dong loai bo cap trung lap)
    vector<pair<int,int>> pairs(uniquePairs.begin(), uniquePairs.end());
    
    // Tra ve so luong cap va vector chua cac cap
    return make_pair(pairs.size(), pairs);
}

int main() {
    int n, m;
    cout << "Nhap so phan tu cua mang: ";  // Nhap so phan tu cua mang
    cin >> n;
    
    vector<int> A(n);  // Tao mang A co kich thuoc n
    cout << "Nhap " << n << " phan tu: ";  // Nhap cac phan tu cua mang
    for(int i = 0; i < n; i++) cin >> A[i];
    
    cout << "Nhap gia tri m: ";  // Nhap gia tri m
    cin >> m;
    
    // Goi ham countPairs de lay ket qua
    pair<int, vector<pair<int,int>>> result = countPairs(A, m);
    int count = result.first;  // So luong cap thoa man
    vector<pair<int,int>> pairs = result.second;  // Vector chua cac cap
    
    // In ra so luong cap va cac cap so
    cout << "\nSo cap co tich lon hon " << m << ": " << count;
    cout << "\nCac cap so: ";
    for(int i = 0; i < count; i++) {
        cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";  // In ra cac cap
    }
    cout << endl;
    
    return 0;
}

