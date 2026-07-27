Problem Statement
Every year, the town of Willowbrook hosts a grand evening celebration where hundreds of guests arrive from different villages. To make the event memorable, the organizers prepare personalized welcome cards for each guest.

However, during one year's celebration, a strong gust of wind scattered the registration papers across the venue. When the organizers collected the papers, they discovered something unusual. Most guests had accidentally registered their names twice because they filled out both the online and offline forms. But one guest had registered only once.

The organizers now need to identify that unique guest so they can prepare the missing welcome card before the event begins.

You are given a list of registration IDs. Every registration ID appears exactly two times, except for one registration ID that appears only once.

Your task is to find and print the registration ID of the guest who registered only once.

Input Format
The first line contains an integer N, representing the number of registration records.

The second line contains N space-separated integers representing the registration IDs.

Output Format
Print the registration ID that appears exactly once.

Constraints
1 ≤ N ≤ 10^5

0 ≤ Registration ID ≤ 10^9

Exactly one registration ID appears once.

Every other registration ID appears exactly twice.

Sample Testcase 0
Testcase Input
5
12 45 12 78 45
Testcase Output
78
Explanation
Frequency of each registration ID:
12 → 2
45 → 2
78 → 1


Only 78 appears once, so the output is 78.

Sample Testcase 1
Testcase Input
7
101 202 303 101 202 404 303
Testcase Output
404
Explanation
Frequency count:
101 → 2
202 → 2
303 → 2
404 → 1


The only registration ID that appears once is 404.
Therefore, the answer is 404.