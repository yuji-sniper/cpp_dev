#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

void chmin(long long &a, long long b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    int N = 7;
    vector<long long> h = {2, 9, 4, 5, 1, 6, 10};
    
    vector<long long> dp(N, INF);

    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        if (i + 1 < N) {
            chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < N) {
            chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}
