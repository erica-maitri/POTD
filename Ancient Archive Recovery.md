Problem Statement
Deep beneath an abandoned kingdom lies a massive archive containing centuries of historical records. The records are stored inside interconnected chambers arranged in a branching structure.

Every chamber contains a unique artifact number. Explorers have discovered that the archive was designed so that each chamber could connect to at most two deeper chambers.

The kingdom's historians follow a special recovery protocol. Whenever they enter a chamber, they first explore all chambers on the left side, then all chambers on the right side, and only after completely examining both sides do they record the artifact stored in the current chamber.

This method ensures that deeper discoveries are documented before the chambers that led to them.

Your task is to generate the final sequence of artifact numbers that historians would record while following this protocol.

Input Format
First line contains integer N.
Next N integers represent artifact numbers inserted into the archive structure.

The archive structure is a Binary Search Tree (BST). The artifact numbers are inserted into the BST in the order given.

Output Format
Print the recovery sequence.

Constraints
1 ≤ N ≤ 1000
1 ≤ Artifact Number ≤ 10^5

Sample Testcase 0
Testcase Input
5
25 15 35 10 20
Testcase Output
10 20 15 35 25
Explanation
       25
      /    \
   15    35
  /    \
10   20


Therefore, the recovery sequence is: 10 20 15 35 25

Sample Testcase 1
Testcase Input
7
40 20 60 10 30 50 70
Testcase Output
10 30 20 50 70 60 40
Explanation
        40
       /     \
     20    60
    /   \     /   \
  10  30 50 70


Hence, the recovery sequence is: 10 30 20 50 70 60 40