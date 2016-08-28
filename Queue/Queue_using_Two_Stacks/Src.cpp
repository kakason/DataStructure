#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s1;
    stack<int> s2;

    int Q, tmp, front = 0;
    cin >> Q;

    while (Q--) {
        cin >> tmp;

        // Case 1
        if (tmp == 1) {
            cin >> tmp;

            if (s1.empty())
                front = tmp;

            s1.push(tmp);
        }
        // Case 2
        else if (tmp == 2) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop();
        }
        // Case 3
        else {
            if (s2.empty())
                cout << front << "\n";
            else
                cout << s2.top() << "\n";
        }
    }

    return 0;
}
