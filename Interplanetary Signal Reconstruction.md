Problem Statement
In the year 2487, humanity has established communication stations across multiple planets. During a massive solar storm, several sections of a long interplanetary transmission were corrupted.

Engineers have recovered fragments of the original signal. Each fragment is represented by a positive integer indicating its reliability score. To reconstruct the message, engineers must select fragments in increasing order of reliability.

However, there is a catch. Fragments can only be connected if their reliability score is strictly higher than the previous selected fragment. Any decrease or equality breaks the reconstruction chain.

The final quality of the recovered message depends entirely on the length of the longest valid reconstruction chain.

Your task is to determine the maximum number of fragments that can be connected to form a valid signal reconstruction.

Input Format
First line contains integer N.
Second line contains N space-separated integers.

Output Format
Print the length of the longest valid reconstruction chain.

Constraints
1 ≤ N ≤ 200000
1 ≤ score[i] ≤ 10^9

Sample Testcase 0
Testcase Input
8
1 7 3 5 9 4 8 10
Testcase Output
5
Explanation
One possible chain:
1 → 3 → 5 → 8 → 10
Length = 5.

Sample Testcase 1
Testcase Input
6
3 10 2 11 5 12
Testcase Output
4
Explanation
One optimal chain is:
3 → 10 → 11 → 12
Length = 4.