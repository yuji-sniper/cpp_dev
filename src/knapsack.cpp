#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    int N = 6;
    long long W = 15;
    vector<long long> weight = {2, 1, 3, 2, 1, 5};
    vector<long long> value = {3, 2, 6, 1, 3, 85};

    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {
            // i番目を選ぶ場合
            if (w - weight[i] >= 0) {
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }
            // i番目を選ばない場合
            chmax(dp[i + 1][w], dp[i][w]);
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}
