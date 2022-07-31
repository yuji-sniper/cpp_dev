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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    int min_value = INF;

    sort(b.begin(), b.end());

    b.push_back(INF);

    for (int i = 0; i < N; ++i) {
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);
        int val = *iter;
        int sum = a[i] + val;
        if (sum < min_value) min_value = sum;
    }

    cout << min_value << endl;
}
