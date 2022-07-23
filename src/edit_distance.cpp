#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

template<class T>
void chmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

const int INF = pow(2, 29);

// 5.5
int main() {
    string S = "logistic";
    string T = "algorithm";

    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));

    dp[0][0] = 0;

    for (int i = 0; i <= S.size(); ++i) {
        for (int j = 0; j <= T.size(); ++j) {
            // 最後の文字が変更操作
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            // 最後の文字が削除操作
            if (i > 0) {
                chmin(dp[i][j], dp[i - 1][j] + 1);
            }
            // 最後の文字が挿入操作
            if (j > 0) {
                chmin(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }

    cout << dp[S.size()][T.size()] << endl;
}