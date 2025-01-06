#include <iostream>
#include <map>
using namespace std;

// Node c?a danh sách liên k?t
struct Node {
    int denomination;
    Node* next;
};

// Hàm thêm m?t node vào danh sách
void addNode(Node*& head, int denom) {
    Node* newNode = new Node;
    newNode->denomination = denom;
    newNode->next = head;
    head = newNode;
}

// Hàm de rut tien tu cac menh gia
map<int, int> withdrawMoney(int amount) {
    // Kh?i t?o danh sách m?nh giá ti?n
    Node* head = nullptr;
    addNode(head, 1000);
    addNode(head, 2000);
    addNode(head, 5000);
    addNode(head, 10000);
    addNode(head, 20000);
    addNode(head, 50000);
    addNode(head, 100000);
    addNode(head, 200000);
    addNode(head, 500000);

    map<int, int> result;

    // Duy?t qua danh sách liên k?t d? tính s? lu?ng t?ng m?nh giá
    Node* current = head;
    while (current != nullptr) {
        int denom = current->denomination;
        if (amount >= denom) {
            result[denom] = amount / denom;
            amount %= denom;
        }
        current = current->next;
    }

    // Gi?i phóng b? nh? c?a danh sách liên k?t
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
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
    for(map<int, int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << it->first << " VND: " << it->second << " to\n";  // In ra menh gia va so to
    }
    
    return 0;
}

