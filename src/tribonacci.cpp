#include <iostream>
#include <vector>

using namespace std;

vector<long long> nums;

// インデックスiの数を返す
long long tribo(int i) {
    if (i == 0) return nums[0] = 0;
    else if (i == 1) return nums[1] = 0;
    else if (i == 2) return nums[2] = 1;

    if (nums[i] != -1) return nums[i];

    return nums[i] = tribo(i - 1) + tribo(i - 2) + tribo(i - 3);
}

// トリボナッチ数列のN番目の値を取得する
int main() {
    int N;
    cin >> N;
    nums.assign(N, -1);
    cout << tribo(N - 1) << endl;
    return 0;
}
