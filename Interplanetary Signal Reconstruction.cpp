<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> dp(N, 1);

    int ans = 1;

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < i; j++) {

            // If previous element is smaller,
            // we can add current element
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}

/*
================ DRY RUN ================

Input:
8
1 7 3 5 9 4 8 10


Array:
Index:  0  1  2  3  4  5  6  7
Value:  1  7  3  5  9  4  8 10


Initially:

dp = [1,1,1,1,1,1,1,1]


i = 0
a[i] = 1

No previous element

dp[0] = 1


dp = [1,1,1,1,1,1,1,1]


-----------------------------------------

i = 1
a[i] = 7

Check previous:

1 < 7

dp[1] = dp[0] + 1
      = 1 + 1
      = 2


dp = [1,2,1,1,1,1,1,1]


-----------------------------------------

i = 2
a[i] = 3

Previous:

1 < 3

dp[2] = dp[0]+1
      = 2


7 is not smaller


dp = [1,2,2,1,1,1,1,1]


-----------------------------------------

i = 3
a[i] = 5

Previous:

1 < 5
dp = 2

3 < 5
dp[3] = dp[2]+1
      = 3


7 is not smaller


dp = [1,2,2,3,1,1,1,1]


-----------------------------------------

i = 4
a[i] = 9

Previous smaller elements:

1,7,3,5

Best sequence:
1 -> 3 -> 5 -> 9

dp[4] = 4


dp = [1,2,2,3,4,1,1,1]


-----------------------------------------

i = 5
a[i] = 4

Previous:

1 < 4
dp = 2

3 < 4
dp = 3

5,7,9 are bigger


dp = [1,2,2,3,4,3,1,1]


-----------------------------------------

i = 6
a[i] = 8

Previous:

1 -> 8
7 -> 8
3 -> 8
5 -> 8
4 -> 8

Best:

1 -> 3 -> 5 -> 8

dp[6] = 4


dp = [1,2,2,3,4,3,4,1]


-----------------------------------------

i = 7
a[i] = 10

Previous:

Best sequence:

1 -> 3 -> 5 -> 8 -> 10

dp[7] = 5


dp = [1,2,2,3,4,3,4,5]


Answer = maximum value in dp

= 5


Output:
5


Time Complexity: O(N²)
Space Complexity: O(N)

DP (above)	...Easy	O(N²)
Binary Search + lower_bound	 ...Hard	O(N log N)
=======
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> dp(N, 1);

    int ans = 1;

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < i; j++) {

            // If previous element is smaller,
            // we can add current element
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}

/*
================ DRY RUN ================

Input:
8
1 7 3 5 9 4 8 10


Array:
Index:  0  1  2  3  4  5  6  7
Value:  1  7  3  5  9  4  8 10


Initially:

dp = [1,1,1,1,1,1,1,1]


i = 0
a[i] = 1

No previous element

dp[0] = 1


dp = [1,1,1,1,1,1,1,1]


-----------------------------------------

i = 1
a[i] = 7

Check previous:

1 < 7

dp[1] = dp[0] + 1
      = 1 + 1
      = 2


dp = [1,2,1,1,1,1,1,1]


-----------------------------------------

i = 2
a[i] = 3

Previous:

1 < 3

dp[2] = dp[0]+1
      = 2


7 is not smaller


dp = [1,2,2,1,1,1,1,1]


-----------------------------------------

i = 3
a[i] = 5

Previous:

1 < 5
dp = 2

3 < 5
dp[3] = dp[2]+1
      = 3


7 is not smaller


dp = [1,2,2,3,1,1,1,1]


-----------------------------------------

i = 4
a[i] = 9

Previous smaller elements:

1,7,3,5

Best sequence:
1 -> 3 -> 5 -> 9

dp[4] = 4


dp = [1,2,2,3,4,1,1,1]


-----------------------------------------

i = 5
a[i] = 4

Previous:

1 < 4
dp = 2

3 < 4
dp = 3

5,7,9 are bigger


dp = [1,2,2,3,4,3,1,1]


-----------------------------------------

i = 6
a[i] = 8

Previous:

1 -> 8
7 -> 8
3 -> 8
5 -> 8
4 -> 8

Best:

1 -> 3 -> 5 -> 8

dp[6] = 4


dp = [1,2,2,3,4,3,4,1]


-----------------------------------------

i = 7
a[i] = 10

Previous:

Best sequence:

1 -> 3 -> 5 -> 8 -> 10

dp[7] = 5


dp = [1,2,2,3,4,3,4,5]


Answer = maximum value in dp

= 5


Output:
5


Time Complexity: O(N²)
Space Complexity: O(N)

DP (above)	...Easy	O(N²)
Binary Search + lower_bound	 ...Hard	O(N log N)
>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
*/