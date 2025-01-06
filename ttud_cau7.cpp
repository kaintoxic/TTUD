#include <iostream>
using namespace std;

int stepCount = 0;  // Bi?n d?m s? bu?c

void hanoiTower(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        stepCount++;  // Tang s? bu?c
        cout << "Di chuyen dia 1 tu cot " << source << " sang cot " << target << endl;
        return;
    }
    
    // Di chuyen n-1 dia tu cot nguon sang cot trung gian
    hanoiTower(n-1, source, target, auxiliary);
    
    // Di chuyen dia lon nhat sang cot dich
    stepCount++;  // Tang s? bu?c
    cout << "Di chuyen dia " << n << " tu cot " << source << " sang cot " << target << endl;
    
    // Di chuyen n-1 dia tu cot trung gian sang cot dich
    hanoiTower(n-1, auxiliary, source, target);
}

int main() {
    int n;
    cout << "Nhap so dia: ";
    cin >> n;
    
    cout << "Cac buoc giai bai toan thap Ha Noi voi " << n << " dia:" << endl;
    hanoiTower(n, 'A', 'B', 'C');
    
    // In s? bu?c
    cout << "\nTong so buoc di chuyen: " << stepCount << endl;
    
    return 0;
}
//source: c?t nguon (A).
//auxiliary: c?t phu (B).
//target: c?t dích (C).
//1Hanoi(n, source, auxiliary, target):
//    1. N?u n == 1:
//        - Di chuy?n dia t? c?t source sang c?t target.
//    2. N?u n > 1:
//        - Di chuy?n n-1 dia t? c?t source sang c?t auxiliary (dùng c?t target làm c?t ph?).
//        - Di chuy?n dia l?n nh?t t? c?t source sang c?t target.
//        - Di chuy?n n-1 dia t? c?t auxiliary sang c?t target (dùng c?t source làm c?t ph?).
//2De di chuyen n dia tu cot nguon A sang cot dich C (dung cot trung gian B):
//
//Neu n = 1:
//
//Di chuyen dia tu cot A sang cot C
//Ket thuc
//Neu n > 1:
//
//Bu?c 1: Di chuyen n-1 dia tu cot A sang cot B (dung C lam trung gian) 
//Bu?c 2: Di chuyen dia thu n (dia lon nhat) tu cot A sang cot C 
//Bu?c 3: Di chuyen n-1 dia tu cot B sang cot C (dung A lam trung gian)
