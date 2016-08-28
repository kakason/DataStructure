#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

int main() {
    int N, Q, d,
        i, tmp, tmp_min;

    cin >> N >> Q;

    vector<int> vec;
    vec.reserve(N);

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    // Hint: use sliding window
    while (Q--) {
        cin >> d;
        tmp_min = 1e6;

        // sliding window
        queue<int> window;
        // the first element in deque will be the max value
        // of current window size(d autually is the window size)
        deque<int> maximum;

        for (int i = 0; i < N; i++) {
            if (window.size() < d) {
                window.push(vec[i]);
            }
            else {
                if (window.front() == maximum.front())
                    maximum.pop_front();
                window.pop();
                window.push(vec[i]);
            }

            while (!maximum.empty() && maximum.back() < vec[i])
                maximum.pop_back();
            maximum.push_back(vec[i]);

            // current window size is full means
            // we've found one possible answer
            if (window.size() == d)
                tmp_min = min(tmp_min, maximum.front());
        }

        cout << tmp_min << "\n";
    }

    return 0;
}
