#include <iostream>
#include <vector>
using namespace std;

// Ham merge de sap xep mang con
void merge(vector<int>& arr, int trai, int giua, int phai) {
    int n1 = giua - trai + 1;
    int n2 = phai - giua;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[trai + i];
    for (int j = 0; j < n2; j++) R[j] = arr[giua + 1 + j];

    int i = 0, j = 0, k = trai;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Ham MergeSort
void mergesort(vector<int>& arr, int trai, int phai) {
    if (trai < phai) {
        int giua = trai + (phai - trai) / 2;
        mergesort(arr, trai, giua);  // Sap xep nua dau
        mergesort(arr, giua + 1, phai); // Sap xep nua sau
        merge(arr, trai, giua, phai);  // Hop nhat
    }
}

// Ham heapify de duy tri cau truc heap
void heapify(vector<int>& arr, int n, int i) {
    int lon_nhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;

    if (trai < n && arr[trai] > arr[lon_nhat]) lon_nhat = trai;
    if (phai < n && arr[phai] > arr[lon_nhat]) lon_nhat = phai;

    if (lon_nhat != i) {
        swap(arr[i], arr[lon_nhat]);
        heapify(arr, n, lon_nhat); // De quy
    }
}

// Ham HeapSort
void heapsort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); // Duy tri heap
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); // Duy tri heap sau khi doi vi tri
    }
}

// Ham partition cho QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Ham QuickSort
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1); // Sap xep nua dau
        quicksort(arr, pi + 1, high); // Sap xep nua sau
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Tao ban sao cho moi thuat toan
    vector<int> arr_merge = arr;
    vector<int> arr_quick = arr;
    vector<int> arr_heap = arr;

    cout << "\nMang ban dau: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // MergeSort
    mergesort(arr_merge, 0, n - 1);
    cout << "\nSau khi Merge Sort: ";
    for (int x : arr_merge) cout << x << " ";
    cout << endl;

    // QuickSort
    quicksort(arr_quick, 0, n - 1);
    cout << "Sau khi Quick Sort: ";
    for (int x : arr_quick) cout << x << " ";
    cout << endl;

    // HeapSort
    heapsort(arr_heap);
    cout << "Sau khi Heap Sort: ";
    for (int x : arr_heap) cout << x << " ";
    cout << endl;

    return 0;
}

