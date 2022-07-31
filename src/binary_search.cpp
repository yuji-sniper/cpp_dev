#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;

const int INF = 1 << 29;

template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }

// code 6.1
int binary_search(int key, vector<int> &a) {
    int left = 0, right = (int)a.size() - 1;
    while (right >= left) {
        int mid = (left + right) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int key;
    cin >> key;

    cout << binary_search(key, a) << endl;
}
