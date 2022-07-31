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
    int N;
    cin >> N;
    vector<Int> H(N), S(N);
    for (Int i = 0; i < N; ++i) cin >> H[i];
    for (Int i = 0; i < N; ++i) cin >> S[i];

    Int M  = 0;
    for (int i = 0; i < N; ++i) M = max(M, H[i] + S[i] * N);
    Int left = 0, right = M;
    
    while (right - left > 1) {
        Int mid = (left + right) / 2;
        bool ok = true;
        vector<Int> t(N, 0);
        for (int i = 0; i < N; ++i) {
            if (H[i] > mid) ok = false;
            else t[i] = (mid - H[i]) / S[i];
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < N; ++i) {
            if (i > t[i]) ok = false;
        }
        if (ok) right = mid;
        else left = mid;
    }

    cout << right << endl;
    
}
