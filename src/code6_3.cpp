#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;

const int INF = 1 << 29;

template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }

int main() {
    int left = 20, right = 36;

    while (right - left > 1) {
        int mid = (left + right) / 2;
        cout << mid << "歳未満ですか？(yes/no)：";
        string ans;
        cin >> ans;
        if (ans == "yes") right = mid;
        else left = mid;
    }
    cout << endl;

    cout << "あなたは" << left << "歳です！" << endl;
}
