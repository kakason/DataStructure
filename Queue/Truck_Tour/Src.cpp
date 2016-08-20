#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, tmp_pro, tmp_dis, tmp_sum, ans;
    bool finished;

    cin >> N;
    vector<int> Dis;
    Dis.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> tmp_pro >> tmp_dis;
        Dis[i] = tmp_pro - tmp_dis;
    }

    // greedy algorithm
    for (int i = 0; i < N; i++) {
        finished = true;
        tmp_sum = 0;
        ans = i;
        for (int j = i; j < N + i; j++) {
            tmp_sum += Dis[j%N];
            if (tmp_sum < 0) {
                finished = false;
                break;
            }
        }

        if (finished)
            break;
    }

    cout << ans;

    return 0;
}
