#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void chmax(T &a, T b) {
    if (a < b) {
        a = b;
    }
}

// 章末問題 5.1
int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    // i日目にjをした時のi日間の最大幸福度
    vector<vector<int>> dp(N, vector<int>(3, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (j == k) continue;
                chmax(dp[i + 1][j], dp[i][k] + a[i][j]);
            }
        }
    }

    int res = 0;
    for (int j = 0; j < 3; ++j) {
        chmax(res, dp[N][j]);
    }

    cout << res << endl;
}
