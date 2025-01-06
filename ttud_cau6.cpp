#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Ham de sinh ra cac chuoi tam phan
void generateTernary(string curr, int pos, int N, int hasOne, vector<string>& result) {
    if(pos == N) {
        if(hasOne == 1) result.push_back(curr); // Neu co dung 1 so 1, them vao ket qua
        return;
    }
    
    if(!hasOne) generateTernary(curr + "1", pos + 1, N, 1, result); // Neu chua co so 1, sinh chuoi co 1
    generateTernary(curr + "0", pos + 1, N, hasOne, result); // Sinh chuoi co 0
    generateTernary(curr + "2", pos + 1, N, hasOne, result); // Sinh chuoi co 2
}

// Ham sinh ra danh sach cac chuoi tam phan
vector<string> generateTernaryStrings(int N) {
    vector<string> result;
    generateTernary("", 0, N, 0, result); // Goi ham de sinh chuoi
    return result;
}

int main() {
    int N;
    cout << "Nhap so nguyen duong N (N>=3): ";
    cin >> N; // Nhap N
    
    // Goi ham sinh chuoi tam phan
    vector<string> result = generateTernaryStrings(N);
    
    // In ra ket qua
    cout << "\nCac chuoi tam phan do dai " << N << " chi chua dung 1 so 1:\n";
    for(int i = 0; i < result.size(); i++) { 
        cout << result[i] << endl;
    }
    cout << "Tong so chuoi: " << result.size() << endl; // In ra tong so chuoi
    
    return 0;
}

