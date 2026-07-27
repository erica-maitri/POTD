<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
   int N;
   int K;

   cin >> N >> K;
   

   vector <int> pack(N);
   for(int i = 0 ; i< N ;i++){
    cin >> pack[i];
   }

   /*vector<int> v;

    for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    v.push_back(x);
   }*/
   
   /*
    priority_queue<int> pq;
   for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }*/

    // Build max heap in O(N)
    priority_queue<int> pq(pack.begin(), pack.end());

    // Print first K largest elements
    while (K--) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

/*Example Input:
N = 6, K = 3
Array = [40, 15, 60, 25, 80, 35]

Step 1: Read the array
v = [40, 15, 60, 25, 80, 35]

Step 2: Create a max heap
priority_queue<int> pq(v.begin(), v.end());

Heap (conceptually):
        80
      /    \
    40      60
   /  \    /
 25   15  35

(Internally, the heap may have a different layout, but the top is always the largest.)

Step 3: Print first K largest elements

Iteration 1:
pq.top() = 80
Output: 80
pq.pop()

Remaining heap:
        60
      /    \
    40      35
   /
 25
/
15

-----------------------------------

Iteration 2:
pq.top() = 60
Output: 80 60
pq.pop()

Remaining heap:
       40
      /  \
    25    35
   /
 15

-----------------------------------

Iteration 3:
pq.top() = 40
Output: 80 60 40
pq.pop()

K becomes 0, stop.

Final Output:
80 60 40

while (K--) uses the post-decrement (--) operator.

It means:

Check the current value of K.
If it is not 0, execute the loop.
After the check, decrease K by 1.

n C++:

0 → false
Any non-zero value (1, -1, 5, 100, etc.) → true
When K is 0, the condition uses 0, which is false, so the loop stops.
Only after that check does K become -1.
The loop never checks -1 because it has already exited.
0 is the only integer value that is false in C++.
-1 is true.
while (K--) stops because the condition sees 0, not because it sees -1.*/


/*Reading input into vector
→ O(N)

Building max heap
This uses the heap construction algorithm (make_heap), which takes:
→ O(N)

Extracting K maximum elements
pq.top() → O(1)
pq.pop() → O(log N)

Repeated K times:
→ O(K log N)

Total Time Complexity:
O(N+KlogN)
	​
Space Complexity (SC):
vector<int> pack(N);
Stores N elements:
→ O(N)
priority_queue<int> pq;
Stores N elements internally:
→ O(N)
Total:
O(N)
	
Final Answer:
Time Complexity  : O(N + K log N)
Space Complexity : O(N)

This is one of the best approaches for this problem because you only need the first K largest values, not the complete sorted array.*/




//......
//OR
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // Sort in descending order
    sort(v.begin(), v.end(), greater<int>());

    // Print first K elements
    for (int i = 0; i < K; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
Time Complexity
Reading input: O(N)
Sorting: O(N log N)
Printing first K elements: O(K)

Overall Time Complexity: O(N log N)
=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
   int N;
   int K;

   cin >> N >> K;
   

   vector <int> pack(N);
   for(int i = 0 ; i< N ;i++){
    cin >> pack[i];
   }

   /*vector<int> v;

    for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    v.push_back(x);
   }*/
   
   /*
    priority_queue<int> pq;
   for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }*/

    // Build max heap in O(N)
    priority_queue<int> pq(pack.begin(), pack.end());

    // Print first K largest elements
    while (K--) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

/*Example Input:
N = 6, K = 3
Array = [40, 15, 60, 25, 80, 35]

Step 1: Read the array
v = [40, 15, 60, 25, 80, 35]

Step 2: Create a max heap
priority_queue<int> pq(v.begin(), v.end());

Heap (conceptually):
        80
      /    \
    40      60
   /  \    /
 25   15  35

(Internally, the heap may have a different layout, but the top is always the largest.)

Step 3: Print first K largest elements

Iteration 1:
pq.top() = 80
Output: 80
pq.pop()

Remaining heap:
        60
      /    \
    40      35
   /
 25
/
15

-----------------------------------

Iteration 2:
pq.top() = 60
Output: 80 60
pq.pop()

Remaining heap:
       40
      /  \
    25    35
   /
 15

-----------------------------------

Iteration 3:
pq.top() = 40
Output: 80 60 40
pq.pop()

K becomes 0, stop.

Final Output:
80 60 40

while (K--) uses the post-decrement (--) operator.

It means:

Check the current value of K.
If it is not 0, execute the loop.
After the check, decrease K by 1.

n C++:

0 → false
Any non-zero value (1, -1, 5, 100, etc.) → true
When K is 0, the condition uses 0, which is false, so the loop stops.
Only after that check does K become -1.
The loop never checks -1 because it has already exited.
0 is the only integer value that is false in C++.
-1 is true.
while (K--) stops because the condition sees 0, not because it sees -1.*/


/*Reading input into vector
→ O(N)

Building max heap
This uses the heap construction algorithm (make_heap), which takes:
→ O(N)

Extracting K maximum elements
pq.top() → O(1)
pq.pop() → O(log N)

Repeated K times:
→ O(K log N)

Total Time Complexity:
O(N+KlogN)
	​
Space Complexity (SC):
vector<int> pack(N);
Stores N elements:
→ O(N)
priority_queue<int> pq;
Stores N elements internally:
→ O(N)
Total:
O(N)
	
Final Answer:
Time Complexity  : O(N + K log N)
Space Complexity : O(N)

This is one of the best approaches for this problem because you only need the first K largest values, not the complete sorted array.*/




//......
//OR
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // Sort in descending order
    sort(v.begin(), v.end(), greater<int>());

    // Print first K elements
    for (int i = 0; i < K; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
Time Complexity
Reading input: O(N)
Sorting: O(N log N)
Printing first K elements: O(K)

Overall Time Complexity: O(N log N)
>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
Space Complexity: O(N) (for the vector)*/