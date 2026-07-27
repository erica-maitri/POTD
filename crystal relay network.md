Problem Statement
In the ancient kingdom of Aerion, energy is transferred between cities using a network of magical crystal relays. The kingdom consists of N relay towers arranged in a straight line, numbered from 1 to N.

Each relay tower stores a certain amount of energy represented by an integer value. During a seasonal energy transfer ceremony, a messenger starts at the first tower and must eventually reach the last tower.

However, the messenger cannot simply move from one tower to the next. Due to the unstable nature of the crystal network, the messenger may jump from tower i to any tower j such that j > i.

Whenever the messenger jumps from tower i to tower j, the energy consumed is:

|Energy[i] - Energy[j]| × (j - i)

The royal engineers want to determine the minimum total energy required for the messenger to travel from the first tower to the last tower.

Since the kingdom contains thousands of relay towers, checking every possible route manually is impossible. Different jump sequences may lead to drastically different total energy costs.

For example, consider the following relay towers:

Crystal Energy Layout

Tower:    1    2    3    4
Energy:   5    1    7    4

Possible route:

1 -----> 2 -----> 4

Cost:

|5-1| × 1 = 4
|1-4| × 2 = 6

Total = 10

Another route:

1 -------------> 4

Cost:

|5-4| × 3 = 3

Clearly, different paths produce different costs.

Your task is to determine the minimum possible energy consumption required to reach the final tower.

Input Format
First line contains an integer N.

Second line contains N space-separated integers representing the energy values stored in each tower.

Output Format
Print a single integer representing the minimum energy required to reach the last tower.

Constraints
2  ≤  N  ≤  1000
1  ≤  Energy[i]  ≤  10^5

Sample Testcase 0
Testcase Input
5
10 2 8 3 7
Testcase Output
6
Explanation
One optimal route:


1 -> 3 -> 5


Cost:


|10 - 8| × 2 = 4
|8 - 7| × 2 = 2


Total = 6


Checking all valid routes shows the minimum achievable cost is 6.


Therefore, the output should be: 6

Sample Testcase 1
Testcase Input
4
5 1 7 4
Testcase Output
3
Explanation
Possible routes:


1 -> 4
Cost = |5 - 4| × 3 = 3
1 -> 2 -> 4
Cost = 4 + 6 = 10
1 -> 3 -> 4
Cost = 4 + 3 = 7


Minimum possible cost = 3