<<<<<<< HEAD
#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<long long, int> freq;
    long long id;

    for (int i = 0; i < N; i++) {
        cin >> id;
        freq[id]++;
    }

    long long ansId;
    int maxFreq = 0;

    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            ansId = it.first;
        }
    }

    cout << ansId << " " << maxFreq;

    return 0;
}
/*Time Complexity: O(N log N) (due to map)
Space Complexity: O(N)*/

/*The maximum possible frequency is N.
1 ≤ N ≤ 100000
Since 100000 easily fits in an int (maximum int is about 2 billion), int is sufficient.

A map stores keys in ascending order:
101
205
310

maxFreq = 0
First element
101 -> 3
3 > 0

Yes.

maxFreq = 3
ansId = 101
Second element
205 -> 3

Check
3 > 3 ?

No.

Since we only use > (not >=), we do not replace 101.

Third element
310 -> 1
1 > 3 ?

No.

Final answer

101 3

What if we had used >=?
if (it.second >= maxFreq)

Dry run:

101 -> 3
ans = 101

Then
205 -> 3
Since
3 >= 3
is true,
ans = 205

which is wrong, because the problem asks for the smallest ID in case of a tie.
.................
If we were using unordered_map

unordered_map does not keep keys sorted.

Then we'd need to handle ties explicitly:

if (count > maxFreq) {
    maxFreq = count;
    ans = id;
}
else if (count == maxFreq && id < ans) {
    ans = id;
}

This extra condition ensures that among IDs with the same maximum frequency, the smallest ID is chosen.
=======
#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<long long, int> freq;
    long long id;

    for (int i = 0; i < N; i++) {
        cin >> id;
        freq[id]++;
    }

    long long ansId;
    int maxFreq = 0;

    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            ansId = it.first;
        }
    }

    cout << ansId << " " << maxFreq;

    return 0;
}
/*Time Complexity: O(N log N) (due to map)
Space Complexity: O(N)*/

/*The maximum possible frequency is N.
1 ≤ N ≤ 100000
Since 100000 easily fits in an int (maximum int is about 2 billion), int is sufficient.

A map stores keys in ascending order:
101
205
310

maxFreq = 0
First element
101 -> 3
3 > 0

Yes.

maxFreq = 3
ansId = 101
Second element
205 -> 3

Check
3 > 3 ?

No.

Since we only use > (not >=), we do not replace 101.

Third element
310 -> 1
1 > 3 ?

No.

Final answer

101 3

What if we had used >=?
if (it.second >= maxFreq)

Dry run:

101 -> 3
ans = 101

Then
205 -> 3
Since
3 >= 3
is true,
ans = 205

which is wrong, because the problem asks for the smallest ID in case of a tie.
.................
If we were using unordered_map

unordered_map does not keep keys sorted.

Then we'd need to handle ties explicitly:

if (count > maxFreq) {
    maxFreq = count;
    ans = id;
}
else if (count == maxFreq && id < ans) {
    ans = id;
}

This extra condition ensures that among IDs with the same maximum frequency, the smallest ID is chosen.
>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
*/