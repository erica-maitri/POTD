The Kingdom of Vardania hosts a grand cultural festival every year. During the festival, citizens from different towns visit the capital city to participate in various events, performances, and competitions.

To manage the crowd efficiently, every visitor receives a unique Visitor ID when entering the festival grounds. Throughout the day, visitors may enter and leave different event zones multiple times. Every time a visitor enters a zone, their visitor ID is recorded in the central attendance ledger.

At the end of the day, the chief organizer wants to know which visitor appeared the most frequently in the ledger. This information is used to identify the festival's "Most Active Participant."

However, the ledger contains thousands of entries, and manually counting the appearances of each Visitor ID would take too much time.

You are given the sequence of recorded visitor IDs exactly as they appear in the attendance ledger.

Your task is to determine:

1. Which visitor ID appears the maximum number of times.
2. How many times that visitor ID appears.

If multiple Visitor IDs have the same highest frequency, output the smallest Visitor ID among them.

Input Format
The first line contains an integer N, representing the number of entries recorded in the attendance ledger.

The second line contains N space-separated integers representing the Visitor IDs.

Output Format
Print two integers separated by a space:

* The Visitor ID that appears the most frequently.
* Its frequency.

If multiple Visitor IDs have the same maximum frequency, print the smallest Visitor ID among them.

Constraints
1 ≤ N ≤ 10^5

−2^31 ≤ Visitor ID ≤ 2^31 − 1

Sample Testcase 0
Testcase Input
7
101 205 101 310 205 101 205
Testcase Output
101 3
Explanation
Frequency of each Visitor ID:


101 → 3
205 → 3
310 → 1


The maximum frequency is 3.


Both 101 and 205 have this frequency.


Since 101 is smaller, the answer is:


101 3

Sample Testcase 1
Testcase Input
8
4 8 4 2 8 8 1 4
Testcase Output
4 3
Explanation
Frequency table:


4 → 3
8 → 3
2 → 1
1 → 1


The highest frequency is 3.


Both Visitor 4 and Visitor 8 appear 3 times.


The smaller Visitor ID is 4.


Therefore, the output is 4 3.