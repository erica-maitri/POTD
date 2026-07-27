Problem Statement
A remote island nation uses an advanced emergency communication network to broadcast alerts during storms, earthquakes, and other natural disasters. The communication system begins from a central command station and spreads messages through a hierarchy of relay towers.

Every relay tower can forward the message to at most two other towers. When an emergency alert is issued, the message starts from the central station and travels outward through all connected relay towers.

After every emergency drill, the government wants to analyze how the alert propagated through the network. Instead of tracking the exact path taken by the message, they are interested in understanding the order in which towers received the alert level by level.

The central station receives the alert first. After that, all towers directly connected to it receive the alert. Then, all towers connected to those towers receive it, and so on.

Your task is to generate a report showing the relay towers grouped according to the stage at which they receive the alert. The communication hierarchy is represented as a Binary Search Tree (BST) formed by inserting the given tower IDs in the order they appear in the input.

For example, if the command station is tower 10, and it directly informs towers 5 and 15, then tower 10 belongs to stage 0, towers 5 and 15 belong to stage 1, and so forth.

The report should display the tower identifiers stage by stage from the first stage to the last.

Input Format
First line contains integer N representing the number of relay towers.
The next N integers represent the insertion order of tower IDs into the communication hierarchy.

Output Format
Print the tower IDs level by level.
Each stage should appear on a separate line.

Constraints
1 ≤ N ≤ 1000
1 ≤ Tower ID ≤ 10^5

Sample Testcase 0
Testcase Input
6
10 5 15 2 7 20
Testcase Output
10
5 15
2 7 20
Explanation
The communication hierarchy formed is:


10
 /  \
5   15
/  \     \
2  7    20


Towers are reported stage-wise.

Sample Testcase 1
Testcase Input
7
50 30 70 20 40 60 80
Testcase Output
50
30 70
20 40 60 80
Explanation
The communication hierarchy formed is:


         50
      /       \
    30       70
  /    \      /     \ 
20  40  60     80