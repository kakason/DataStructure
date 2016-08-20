#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Plant {
    int index;
    int killtime;
};

int main() {
    // Reference: http://algorithmsandme.in/2014/02/stock-span-problem/

    int N, P, maxTime, curTime;
    cin >> N;

    vector<int> pes;
    pes.reserve(N);

    stack<Plant> s;
    s.push({ 0, -1 }); // The first element will survive to the last

    cin >> P;
    pes.push_back(P);
    maxTime = -1;
    for (int i = 1; i < N; i++) {
        cin >> P;
        pes.push_back(P);
        curTime = 1;

        // Hint:
        // 1. The killer's index will always on the top of the stack.
        // 2. If pes[i] <= pes[s.top()], i need to wait the plants(index < i) to die.

        while (!s.empty() && pes[s.top().index] >= pes[i]) {
            curTime = max(curTime, s.top().killtime + 1);
            s.pop();
        }

        // Stack is empty means i will survive to the last
        if (s.empty())
            curTime = -1;

        s.push({ i, curTime });
        maxTime = max(maxTime, curTime);
    }

    if (maxTime == -1) // Case: 1 1 1 1 1 1
        cout << 0;
    else
        cout << maxTime;

    return 0;
}
