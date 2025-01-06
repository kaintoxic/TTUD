#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<vector<int>, int> maxAmplitudeSequence(vector<int>& arr) {
    int n = arr.size();  // Kich thuoc cua mang arr
    int maxAmp = 0;  // Bien luu gia tri bien do lon nhat
    vector<int> result;  // Vector de luu day con tang co bien do lon nhat
    
    // Duyet qua tung phan tu cua mang de xet cac day con tang
    for(int i = 0; i < n; i++) {
        vector<int> curr = {arr[i]};  // Day con hien tai, bat dau voi phan tu arr[i]
        int currMin = arr[i], currMax = arr[i];  // Khoi tao min va max cho day con hien tai
        
        // Duyet qua cac phan tu tiep theo de tim day con tang
        for(int j = i + 1; j < n; j++) {
            // Neu phan tu hien tai lon hon phan tu truoc do, no tiep tuc tao thanh day con tang
            if(arr[j] > arr[j-1]) {
                curr.push_back(arr[j]);  // Them phan tu vao day con
                currMin = min(currMin, arr[j]);  // Cap nhat gia tri min cua day
                currMax = max(currMax, arr[j]);  // Cap nhat gia tri max cua day
            }
            else break;  // Neu khong con tang, dung lai
        }
        
        // Tinh bien do cua day con hien tai
        int amp = currMax - currMin;
        
        // Neu bien do lon hon bien do da tim duoc truoc do va day con co it nhat 2 phan tu, cap nhat ket qua
        if(amp > maxAmp && curr.size() > 1) {
            maxAmp = amp;  // Cap nhat bien do lon nhat
            result = curr;  // Cap nhat day con tang co bien do lon nhat
        }
    }
    
    // Tra ve day con tang va bien do lon nhat
    return make_pair(result, maxAmp);
}

int main() {
    int n;
    cout << "Nhap so phan tu cua day: ";  // Nhap so phan tu cua mang
    cin >> n;
    
    vector<int> arr(n);  // Tao mang arr voi kich thuoc n
    cout << "Nhap " << n << " so: ";  // Nhap cac phan tu cua mang
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    // Goi ham maxAmplitudeSequence va nhan ket qua
    pair<vector<int>, int> result = maxAmplitudeSequence(arr);
    vector<int> sequence = result.first;  // Day con co bien do lon nhat
    int amplitude = result.second;  // Bien do cua day con
    
    // In ra day con va bien do
    cout << "\nChuoi con tang co bien do lon nhat: ";
    for(int x : sequence) cout << x << " ";  // In cac phan tu cua day con
    cout << "\nBien do: " << amplitude << endl;  // In bien do
    
    return 0;
}

