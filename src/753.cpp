#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> memo;

void func(long long N, int current, int use, int &counter) {
    if (current > N) return;

    if (use == 0b111) {
        ++counter;
        memo.push_back(current);
    }

    // 3を付け加える
    func(N, current * 10 + 3, use | 0b001, counter);

    // 5を付け加える
    func(N, current * 10 + 5, use | 0b010, counter);

    // 7を付け加える
    func(N, current * 10 + 7, use | 0b100, counter);
}

// 章末問題 4.5
int main() {
    long long N;
    cin >> N;
    int counter = 0;
    func(N, 0, 0b000, counter);
    sort(memo.begin(), memo.end());
    while (!memo.empty()) {
        cout << memo.back() << " ";
        memo.pop_back();
    }
    cout << endl;
    return 0;
}
