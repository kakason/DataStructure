#include <stack>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int N, i, tmp, topValue, MAX;

    //debug
    //fstream input("input.txt", ios::in);

    cin >> N;
    //input >> N;

    MAX = 0;
    stack<int> s;
    cin >> tmp;
    //input >> tmp;
    s.push(tmp);
    for (i = 1; i < N; i++) {
        cin >> tmp;
        //input >> tmp;
        if (tmp > s.top()) {
            MAX = max(MAX, s.top() ^ tmp);
            s.push(tmp);
        }
        else {
            while (!s.empty()) {
                topValue = s.top();
                MAX = max(MAX, tmp ^ topValue);
                if (tmp < topValue)
                    s.pop();
                else
                    break;
            }
            s.push(tmp);
        }
    }

    cout << MAX;

    return 0;
}
