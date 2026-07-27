<<<<<<< HEAD
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void postOrder(Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;

    while (n--) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    postOrder(root);

    return 0;
}
/*
The best possible approach for this problem is still:

Build the BST from the insertion order.
Perform a postorder traversal.

This is optimal because the input only gives the insertion order, so the BST must be constructed first.

Complexity
Average Time Complexity: O(N log N)
Building BST: O(N log N)
Postorder traversal: O(N)
Overall: O(N log N)
Worst Time Complexity: O(N²)
If the BST becomes skewed (e.g., sorted input).
Space Complexity: O(H)
H = height of the BST (recursion stack).
Best/Average: O(log N)
Worst: O(N)

=======
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void postOrder(Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;

    while (n--) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    postOrder(root);

    return 0;
}
/*
The best possible approach for this problem is still:

Build the BST from the insertion order.
Perform a postorder traversal.

This is optimal because the input only gives the insertion order, so the BST must be constructed first.

Complexity
Average Time Complexity: O(N log N)
Building BST: O(N log N)
Postorder traversal: O(N)
Overall: O(N log N)
Worst Time Complexity: O(N²)
If the BST becomes skewed (e.g., sorted input).
Space Complexity: O(H)
H = height of the BST (recursion stack).
Best/Average: O(log N)
Worst: O(N)

>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
Note: There is no algorithm with better worst-case than O(N²) if you build a normal BST by repeated insertion. To guarantee O(N log N) in the worst case, you would need a self-balancing BST (such as an AVL tree or Red-Black tree), but the problem specifically states to construct a normal BST from the insertion order.*/