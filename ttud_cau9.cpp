#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ham tra ve danh sach cac cuoc hop toi da co the chon
vector<int> maxMeetings(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    // Danh sach cac cuoc hop duoi dang (finish, start, index)
    vector<pair<pair<int, int>, int>> meetings;
    
    // Tao danh sach cac cuoc hop
    for(int i = 0; i < n; i++) {
        meetings.push_back({{finish[i], start[i]}, i});
    }
    
    // Sap xep cac cuoc hop theo thoi gian ket thuc (finish)
    sort(meetings.begin(), meetings.end());
    
    // Danh sach cac cuoc hop duoc chon
    vector<int> selected = {meetings[0].second};
    int lastFinish = meetings[0].first.first;
    
    // Chon cac cuoc hop toi da co the
    for(int i = 1; i < n; i++) {
        if(meetings[i].first.second >= lastFinish) {
            selected.push_back(meetings[i].second);
            lastFinish = meetings[i].first.first;
        }
    }
    return selected;
}

int main() {
    int n;
    cout << "Nhap so cuoc hop: ";
    cin >> n;
    
    vector<int> start(n), finish(n);
    cout << "Nhap thoi gian bat dau va ket thuc cua tung cuoc hop:\n";
    
    // Nhap thoi gian bat dau va ket thuc cho tung cuoc hop
    for(int i = 0; i < n; i++) {
        cout << "Cuoc hop " << i+1 << " (batdau ketthuc): ";
        cin >> start[i] >> finish[i];
    }
    
    // Goi ham de tim danh sach cac cuoc hop toi da
    vector<int> selected = maxMeetings(start, finish);
    
    // In ra danh sach cuoc hop duoc chon
    cout << "\nDanh sach cac cuoc hop duoc chon: ";
    for(int i : selected) cout << i+1 << " ";
    cout << "\nSo cuoc hop toi da: " << selected.size() << endl;
    
    return 0;
}

