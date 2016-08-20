#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct Building {
    int h;
    int killed;
};

int main() {
    int N, cur_h, cur_l, pre_h, maxArea;

    cin >> N;
    cin >> cur_h;
    maxArea = 0;
    stack<Building> s;
    s.push({ cur_h, 1 });
    for (int i = 1; i < N; i++) {
        cin >> cur_h;

        if (cur_h <= s.top().h) {
            cur_l = 0;
            while (!s.empty() && cur_h <= s.top().h) {
                // The previous buildings which have larger
                // height than current one
                pre_h = s.top().h;
                cur_l += s.top().killed;
                maxArea = max(maxArea, pre_h*cur_l);
                s.pop();
            }
            s.push({ cur_h , cur_l + 1 });
        }
        else
            s.push({ cur_h, 1 });
    }

    cur_l = 0;
    while (!s.empty()) {
        cur_h = s.top().h;
        cur_l += s.top().killed;
        maxArea = max(maxArea, cur_h*cur_l);
        s.pop();
    }

    cout << maxArea;

    return 0;
}
