#include <iostream>
#include <map>
using namespace std;

// Hàm de rut tien tu cac menh gia
map<int, int> withdrawMoney(int amount) {
    // Danh sach cac menh gia tien
    int denominations[] = {500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000};
    int numDenominations = sizeof(denominations) / sizeof(denominations[0]);
    map<int, int> result;

    // Duyet qua tung menh gia de tim so luong can rut
    for (int i = 0; i < numDenominations; i++) {
        int denom = denominations[i];
        if (amount >= denom) {
            result[denom] = amount / denom;  // Tinh so luong toi da cua menh gia
            amount %= denom;  // Cap nhat so tien con lai
        }
    }

    return result;
}

int main() {
    int amount;
    cout << "Nhap so tien can rut: ";
    cin >> amount;  // Nhap so tien can rut
    
    // Goi ham de tim so luong tung menh gia
    map<int, int> result = withdrawMoney(amount);
    
    // In ra ket qua
    cout << "\nSo to tien can rut:\n";
    for (map<int, int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << it->first << " VND: " << it->second << " to\n";  // In ra menh gia va so to
    }
    
    return 0;
}

