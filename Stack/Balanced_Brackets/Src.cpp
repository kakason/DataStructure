#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isBalanced(string);

unordered_map<char, char> id;

int main() {
    int t;
    string str;

    // preprocess
    id.insert(make_pair('}', '{'));
    id.insert(make_pair(']', '['));
    id.insert(make_pair(')', '('));

    cin >> t;
    while (t--) {
        cin >> str;

        if (isBalanced(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

bool isBalanced(string str) {
    int i, len = str.length();

    stack<char> s;
    for (i = 0; i < len; i++) {
        if (id.find(str[i]) == id.end())
            s.push(str[i]);
        else {
            if (!s.empty() && s.top() == id[str[i]])
                s.pop();
            else
                return false;
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}
