#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int Q, type, k;
    string str = "", w;

    vector<string> state;

    cin >> Q;
    while (Q--) {
        cin >> type;

        switch (type) {
        case 1:
            cin >> w;
            state.push_back(str);
            str.append(w);
            break;

        case 2:
            cin >> k;
            state.push_back(str);
            str.erase(str.length() - k, k);
            break;

        case 3:
            cin >> k;
            cout << str[k - 1] << "\n";
            break;

        default:
            str = state.back();
            state.pop_back();
            break;

        }
    }

    return 0;
}
