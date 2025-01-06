#include <iostream>
#include <vector>
#include <string>
using namespace std;

// H�m d? sinh ra c�c chu?i tam ph�n c� d? d�i N, ch? ch?a d�ng 1 s? 1
vector<string> generateTernaryStrings(int N) {
    vector<string> result;

    // Duy?t qua t?t c? c�c v? tr� c� th? ch?a 1 (t? 0 d?n N-1)
    for (int i = 0; i < N; i++) {
        // Duy?t qua t?t c? c�c chu?i c� d? d�i N, ch? c� d�ng 1 s? 1
        for (int j = 0; j < (1 << (N - 1)); j++) {
            string curr = "";
            bool placedOne = false;
            // X�y d?ng chu?i
            for (int k = 0; k < N; k++) {
                if (k == i) {
                    curr += "1";  // �?t "1" t?i v? tr� i
                    placedOne = true;
                } else {
                    if (j & (1 << (k - (k > i))) ) {
                        curr += "2";  // Ch?n "2" n?u bit tuong ?ng l� 1
                    } else {
                        curr += "0";  // Ch?n "0" n?u bit tuong ?ng l� 0
                    }
                }
            }
            result.push_back(curr);  // Th�m chu?i v�o k?t qu?
        }
    }

    return result;
}

int main() {
    int N;
    cout << "Nh?p N (>=3): ";
    cin >> N; // Nh?p N

    // G?i h�m sinh chu?i tam ph�n
    vector<string> result = generateTernaryStrings(N);

    // In ra k?t qu?
    cout << "\nC�c chu?i tam ph�n c� d? d�i " << N << " ch?a d�ng 1 s? 1:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    cout << "T?ng s? chu?i: " << result.size() << endl; // In ra t?ng s? chu?i

    return 0;
}

