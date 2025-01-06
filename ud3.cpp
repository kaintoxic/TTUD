#include <iostream>
#include <set>
#include <utility>
using namespace std;

pair<int, pair<int, int>*> countPairs(int* A, int n, int m) {
    set<pair<int, int>> uniquePairs;  // Set de loai bo cac cap trung lap
    int maxPairs = n * (n - 1) / 2;   // Toi da so cap co the co
    pair<int, int>* pairs = new pair<int, int>[maxPairs];  // Mang dong de luu cac cap
    int count = 0;  // So luong cap thoa man

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)A[i] * A[j] > m) {
                // Them vao set de kiem tra trung lap
                pair<int, int> p = make_pair(min(A[i], A[j]), max(A[i], A[j]));
                if (uniquePairs.find(p) == uniquePairs.end()) {
                    uniquePairs.insert(p);
                    pairs[count++] = p;  // Luu vao mang dong
                }
            }
        }
    }

    return make_pair(count, pairs);  // Tra ve so luong cap va mang dong chua cac cap
}

int main() {
    int n, m;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int* A = new int[n];  // Mang dong de luu cac phan tu
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "  Phan tu thu " << i + 1 << ": ";
        cin >> A[i];
    }

    cout << "Nhap gia tri m: ";
    cin >> m;

    // Goi ham countPairs
    pair<int, pair<int, int>*> result = countPairs(A, n, m);
    int count = result.first;  // So luong cap
    pair<int, int>* pairs = result.second;  // Mang chua cac cap

    // In ra ket qua
    cout << "\nSo cap co tich lon hon " << m << ": " << count << "\nCac cap so: ";
    for (int i = 0; i < count; i++) {
        cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
    }
    cout << endl;

    // Giai phong bo nho
    delete[] A;
    delete[] pairs;

    return 0;
}

