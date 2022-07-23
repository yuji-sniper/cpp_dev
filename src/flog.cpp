#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

// 5.2
int main() {
    int N = 7;
    vector<long long> h = {2, 9, 4, 5, 1, 6, 10};
    vector<long long> mc(N, INF);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            mc[i] = 0;
        } else if (i == 1) {
            mc[i] = abs(h[i] - h[i - 1]);
        } else {
            mc[i] = min(mc[i - 1] + abs(h[i] - h[i - 1]),
                        mc[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    cout << mc[N - 1] << endl;
    return 0;
}
