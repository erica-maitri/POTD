#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int R,C;
    cin >> R >> C;
    int arr[100][100];

    for(int i=0;i<R;i++){
        for(int j = 0; j< C ;j++){
            cin >> arr[i][j];
        }
    }
    
     for(int i=0;i<R;i++){
      for(int j = C-1 ;j>=0;j--){
        cout << arr[i][j];
        if(j!=0){
         cout << " ";
        }
      }
      cout << endl;
     }

    return 0;
}

/*
R = 2
C = 3
a =
1 2 3
4 5 6

Step 3: Print each row in reverse

Matrix:
1 2 3
4 5 6

Row 0 (i = 0):
j = 2 → print a[0][2] = 3
Output: 3

j = 1 → print a[0][1] = 2
Output: 3 2

j = 0 → print a[0][0] = 1
Output: 3 2 1

Print a new line.

--------------------------------

Row 1 (i = 1):
j = 2 → print a[1][2] = 6
Output: 6

j = 1 → print a[1][1] = 5
Output: 6 5

j = 0 → print a[1][0] = 4
Output: 6 5 4

Print a new line.

Final Output:
3 2 1
6 5 4

Time Complexity (TC)
Reading the matrix: O(R × C)
Printing the reversed rows: O(R × C)

Overall Time Complexity: O(R × C)

Space Complexity (SC)
Matrix a[100][100] stores R × C elements.

Space Complexity: O(R × C)

Extra Space Used: O(1) (no additional data structure is used besides the input matrix).*/