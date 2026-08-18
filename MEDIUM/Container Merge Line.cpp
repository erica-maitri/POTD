#include <iostream>
#include <stack>
using namespace std;

int main() {

    int n;
    cin >> n;

    stack<long long> st;

    for (int i = 0; i < n; i++) {

        long long x;
        cin >> x;

        // Put new container on TOP
        st.push(x);

        // Keep checking the TOP TWO containers
        while (st.size() >= 2) {

            // Take the top container
            long long top = st.top();
            st.pop();

            // Take the second container
            long long second = st.top();

            // If they are equal, merge them
            if (top == second) {

                st.pop();

                // Put their sum back on TOP
                st.push(top + second);
            }
            else {

                // They are different.
                // Put the first container back.
                st.push(top);

                break;
            }
        }
    }

    /*
       A stack prints from TOP to BOTTOM,
       but the question wants BOTTOM to TOP.

       So we use another stack.
    */

    stack<long long> temp = st;

    cout << st.size() << endl;

    // temp currently has the same TOP-to-BOTTOM order.
    // Move elements to another stack to reverse the order.
    stack<long long> answer;

    while (!temp.empty()) {
        answer.push(temp.top());
        temp.pop();
    }

    // Now answer gives BOTTOM -> TOP
    while (!answer.empty()) {
        cout << answer.top() << " ";
        answer.pop();
    }

    cout << endl;

    return 0;
}

