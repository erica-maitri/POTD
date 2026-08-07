Problem Statement
Along the Stormcrest Coast, a chain of old lighthouses helps ships navigate safely during the night. After a severe storm, several lighthouse beacons stopped working and must be repaired before sunset. Each repair requires a different amount of time depending on the extent of the damage.

The coastal authority has assigned Meera to organize the restoration work. The repair crew can work on only one lighthouse at a time, and once a repair begins, it continues until that lighthouse is completely restored.

Every lighthouse has a priority deadline. If its repair is completed on or before this time, it is considered an on-time restoration. Otherwise, the lighthouse is still repaired, but it is marked as delayed and does not contribute to the emergency preparedness report.

Since completing every repair before its deadline is impossible, Meera wants to prepare an order of repairs that allows the largest possible number of lighthouses to be restored on time.

Using the repair information for all lighthouses, determine the maximum number of on-time restorations that can be achieved.

Input Format
The first line contains an integer N, representing the number of damaged lighthouses.

Each of the next N lines contains two integers:

T – the time required to repair the lighthouse.

D – the latest time by which the repair must be completed to be considered on time.

Output Format
Print a single integer representing the maximum number of lighthouses that can be restored on time.

Constraints
1 < N < 2 x 10^5

1 < T, D < 10^9

Sample Testcase 0
Testcase Input
5
3 4
2 5
1 3
4 8
2 6
Testcase Output
3
Explanation
The repair details are:


Lighthouse	Repair Time	Deadline
A	3	4
B	2	5
C	1	3
D	4	8
E	2	6

After sorting by deadline:


Lighthouse	Repair Time	Deadline
C	1	3
A	3	4
B	2	5
E	2	6
D	4	8

Process the repairs:


Step	Selected Repair Times	Total Time	Action
C	{1}	1	Keep
A	{1,3}	4	Keep
B	{1,3,2}	6	Exceeds deadline 5, remove longest repair (3)
E	{1,2,2}	5	Keep
D	{1,2,2,4}	9	Exceeds deadline 8, remove longest repair (4)

The remaining selected repairs require times:


1, 2, 2


Thus, the maximum number of lighthouses that can be restored on time is:


3

Sample Testcase 1
Testcase Input
6
5 7
3 5
2 6
4 10
6 9
1 4
Testcase Output
4
Explanation
The repair details are:


Lighthouse	Repair Time	Deadline
A	5	7
B	3	5
C	2	6
D	4	10
E	6	9
F	1	4

After sorting by deadline:


Lighthouse	Repair Time	Deadline
F	1	4
B	3	5
C	2	6
A	5	7
E	6	9
D	4	10

Processing the repairs:


Step	Selected Repair Times	Total Time	Action
F	{1}	1	Keep
B	{1,3}	4	Keep
C	{1,3,2}	6	Keep
A	{1,3,2,5}	11	Exceeds deadline 7, remove longest repair (5)
E	{1,3,2,6}	12	Exceeds deadline 9, remove longest repair (6)
D	{1,3,2,4}	10	Keep

The remaining selected repairs require times:


1, 2, 3, 4


These repairs finish by time 10, which is within the last selected deadline.


Therefore, the maximum number of lighthouses that can be restored on time is:
4