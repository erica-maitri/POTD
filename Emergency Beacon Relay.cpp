#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct Node{
    int data;
    Node *l ,*r;

    Node(int val){
        data = val;
        l=r=NULL;
    }
};

Node* insert(Node* root, int val){
    if(root==NULL)
     return new Node(val);

     if(val < root->data){
        root->l= insert(root->l, val);
     }else{
        root->r= insert(root->r, val);
     }
     return root;
}
 void level(Node* root){
     if(root==NULL)
     return;

    queue<Node*> q;
    q.push(root);

     while(!q.empty()){
       int size = q.size();

         while(size--){    //when size = 0 so leave loop
           Node* cur = q.front();
           q.pop();

           cout << cur->data;

           if(size){   // if size is not null
             cout << " ";
           }

           if(cur->l){
            q.push(cur->l);
           }

           if(cur->r){
            q.push(cur->r);
           }

         }
         cout << endl;

     }

}
int main() {
   int N;
   cin >> N;
    
   Node* root = NULL;

   for(int i = 0;i<N;i++){
    int x; 
    cin >> x;
    root = insert(root, x);

   }

   level(root);
    return 0;
}

/*

while (0)
{
    cout << "Hi";
}

cout << "Done";
output:
Done

Dry Run (Sample Input)

Input:
6
10 5 15 2 7 20

-------------------------------------------------
Step 1: Build the BST
-------------------------------------------------

Insert 10
Tree:
10

Insert 5
5 < 10, so go left.

    10
   /
  5

Insert 15
15 > 10, so go right.

    10
   /  \
  5   15

Insert 2
2 < 10 → go left to 5
2 < 5  → insert on left of 5

      10
     /  \
    5   15
   /
  2

Insert 7
7 < 10 → go left to 5
7 > 5  → insert on right of 5

      10
     /  \
    5   15
   / \
  2   7

Insert 20
20 > 10 → go right to 15
20 > 15 → insert on right of 15

        10
       /  \
      5    15
     / \     \
    2   7     20

-------------------------------------------------
Step 2: Level Order Traversal (BFS)
-------------------------------------------------

Queue = [10]

-------------------------
Level 0
-------------------------

size = 1

Pop 10
Print: 10

Push left child 5
Push right child 15

Queue = [5, 15]

Output:
10

-------------------------
Level 1
-------------------------

size = 2

Pop 5
Print: 5

Push 2
Push 7

Queue = [15, 2, 7]

Pop 15
Print: 15

Push 20

Queue = [2, 7, 20]

Output:
10
5 15

-------------------------
Level 2
-------------------------

size = 3

Pop 2
Print: 2

Queue = [7, 20]

Pop 7
Print: 7

Queue = [20]

Pop 20
Print: 20

Queue = []

Output:
10
5 15
2 7 20

-------------------------------------------------
Final Output
-------------------------------------------------

10
5 15
2 7 20
*/

