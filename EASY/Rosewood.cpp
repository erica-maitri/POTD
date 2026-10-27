#include <iostream>
#include <stack>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    stack<int> books;
    int freq[1000001] = {0};
    int distinct = 0;

    while (Q--) {
        char op;
        cin >> op;

        if (op == '+') {
            int g;
            cin >> g;

            books.push(g);

            if (freq[g] == 0) {
                distinct++;
            }
            freq[g]++;
        }
        else if (op == '-') {
            int g = books.top();
            books.pop();

            freq[g]--;

            if (freq[g] == 0) {
                distinct--;
            }
        }
        else if (op == '?') {
            if (books.empty()) {
                cout << 0 << " " << 0 << endl;
            }
            else {
                cout << books.top() << " " << distinct << endl;
            }
        }
    }

    return 0;
}


/*
Simple Explanation
- Stack: Stores the books. The last book added is removed first (LIFO).
- Frequency array: Counts how many books of each genre are currently in the stack.
- distinct: Tracks the number of different genres.
How it works:
1. + g: Add genre g to the stack. If it's appearing for the first time, increase distinct.
2. -: Remove the top book. If its frequency becomes zero, decrease distinct.
3. ?: Print the top genre and the number of distinct genres. If the stack is empty, print 0 0.
Time Complexity
- Each operation takes O(1) time.
- Total time complexity: O(Q).
- Space complexity: O(Q + 10⁶).
*/