#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;

const int INF = 1 << 29;

template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }

// 章末問題 5.8
int main() {
    Int N, M;
    cin >> N >> M;
    vector<Int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<vector<double>> dp(N + 1, vector<double>(M + 1, 0));

    for (int i = 0; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            for (int k = 0; k < i; ++k) {
                double sum = 0;
                for (int l = k; l < i; ++l) {
                    sum += a[l];
                }
                chmax(dp[i][j], dp[k][j - 1] + sum / (i - k));
            }
        }
    }

    double res = 0;
    for (int i = 0; i <= M; ++i) {
        chmax(res, dp[N][i]);
    }
    cout << fixed << setprecision(10) << res << endl;
}
