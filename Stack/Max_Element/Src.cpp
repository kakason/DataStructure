#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MIN -1e9

int main() {
    int N;
    cin >> N;

    vector<int> stack;
    stack.reserve(N);

    int type, number;
    int max = MIN; // use this variable to manipulate the max value
    while(N--){
        cin >> type;

        if(type == 1){
            cin >> number;
            if(number > max){
                max = number;
            }
            stack.push_back(number);
        }
        else if(type == 2){
            if(stack.back() == max){
                max = MIN;
                for(int i = 0; i < stack.size() - 1; i++)
                    if(stack[i] > max)
                        max = stack[i];
            }
            stack.pop_back();
        }
        else{
            cout << max << "\n";
        }
    }

    return 0;
}
