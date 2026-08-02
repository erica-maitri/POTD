#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int M;
    cin >> M;

    // mask[i] = effect of button i
    vector<int> mask(M);
    for (int i = 0; i < M; i++)
        cin >> mask[i];

    int S, T;
    cin >> S >> T;

    // XOR value we need to create
    int need = S ^ T;

    int ans = INT_MAX;

    // Total subsets = 2^M
    int total = 1 << M;    //or int total = 2^M; 2^M (2 raised to the power M)

    // Try every subset
    for (int subset = 0; subset < total; subset++) {

        int xr = 0;
        int cnt = 0;

        // Check every button
        for (int i = 0; i < M; i++) {

            // If button i is selected
            // Check if button i is selected in the current subset.
            // If ith bit of subset is 1, the condition is true.check by &
// &=used to check which buttons are selected in the current subset.
            if (subset & (1 << i)) {    
                xr ^= mask[i];
                cnt++;
            }
        }

        // Found required XOR
        if (xr == need)
            ans = min(ans, cnt);
    }

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}

/*<< is the left shift operator.

Every left shift by 1 multiplies the number by 2.

Examples:

1 << 0 = 1      // 2^0
1 << 1 = 2      // 2^1
1 << 2 = 4      // 2^2
1 << 3 = 8      // 2^3
1 << 4 = 16     // 2^4
1 << 5 = 32     // 2^5
*/

/*
In short:

& → checks whether to use a button.
^= → combines the selected button's mask using XOR.

We use & because we need to know which buttons are included in the current subset before XORing their masks.

Example:
M = 3
mask = {1,2,4}
S = 0
T = 3

need = S ^ T = 0 ^ 3 = 3

total = 1<<3 = 8
So subsets are 0 to 7.

------------------------------------
subset = 0 (000)

i=0
subset&(1<<0)
000&001=000 -> false
Button0 not selected

i=1
000&010=000 -> false
Button1 not selected

i=2
000&100=000 -> false
Button2 not selected

xr=0
cnt=0
0!=3

------------------------------------
subset = 1 (001)

i=0
001&001=001 -> true
Button0 selected
xr=0^1=1
cnt=1

i=1
001&010=000 -> false

i=2
001&100=000 -> false

xr=1
1!=3

------------------------------------
subset = 2 (010)

i=0
010&001=000 -> false

i=1
010&010=010 -> true
Button1 selected
xr=0^2=2
cnt=1

i=2
010&100=000 -> false

xr=2
2!=3

------------------------------------
subset = 3 (011)

i=0
011&001=001 -> true
Button0 selected
xr=0^1=1
cnt=1

i=1
011&010=010 -> true
Button1 selected
xr=1^2=3
cnt=2

i=2
011&100=000 -> false

xr=3
3==need
ans=2

------------------------------------
subset = 4 (100)

i=0
100&001=000 -> false

i=1
100&010=000 -> false

i=2
100&100=100 -> true
Button2 selected
xr=0^4=4
cnt=1

xr=4
4!=3

------------------------------------
subset = 5 (101)

i=0
101&001=001 -> true
Button0 selected
xr=0^1=1
cnt=1

i=1
101&010=000 -> false

i=2
101&100=100 -> true
Button2 selected
xr=1^4=5
cnt=2

xr=5
5!=3

------------------------------------
subset = 6 (110)

i=0
110&001=000 -> false

i=1
110&010=010 -> true
Button1 selected
xr=0^2=2
cnt=1

i=2
110&100=100 -> true
Button2 selected
xr=2^4=6
cnt=2

xr=6
6!=3

------------------------------------
subset = 7 (111)

i=0
111&001=001 -> true
Button0 selected
xr=0^1=1
cnt=1

i=1
111&010=010 -> true
Button1 selected
xr=1^2=3
cnt=2

i=2
111&100=100 -> true
Button2 selected
xr=3^4=7
cnt=3

xr=7
7!=3

Final Answer = 2
*/