#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Hàm d? sinh ra các chu?i tam phân có d? dài N, ch? ch?a dúng 1 s? 1
vector<string> generateTernaryStrings(int N) {
    vector<string> result;

    // Duy?t qua t?t c? các v? trí có th? ch?a 1 (t? 0 d?n N-1)
    for (int i = 0; i < N; i++) {
        // Duy?t qua t?t c? các chu?i có d? dài N, ch? có dúng 1 s? 1
        for (int j = 0; j < (1 << (N - 1)); j++) {
            string curr = "";
            bool placedOne = false;
            // Xây d?ng chu?i
            for (int k = 0; k < N; k++) {
                if (k == i) {
                    curr += "1";  // Ð?t "1" t?i v? trí i
                    placedOne = true;
                } else {
                    if (j & (1 << (k - (k > i))) ) {
                        curr += "2";  // Ch?n "2" n?u bit tuong ?ng là 1
                    } else {
                        curr += "0";  // Ch?n "0" n?u bit tuong ?ng là 0
                    }
                }
            }
            result.push_back(curr);  // Thêm chu?i vào k?t qu?
        }
    }

    return result;
}

int main() {
    int N;
    cout << "Nh?p N (>=3): ";
    cin >> N; // Nh?p N

    // G?i hàm sinh chu?i tam phân
    vector<string> result = generateTernaryStrings(N);

    // In ra k?t qu?
    cout << "\nCác chu?i tam phân có d? dài " << N << " ch?a dúng 1 s? 1:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    cout << "T?ng s? chu?i: " << result.size() << endl; // In ra t?ng s? chu?i

    return 0;
}

