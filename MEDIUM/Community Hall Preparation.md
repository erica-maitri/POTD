Problem Statement
Every year, the town of Riverview hosts a week-long cultural celebration in its newly renovated community hall. Before each day's events begin, different teams enter the hall to decorate the stage, arrange seating, install lighting, test sound systems, and prepare exhibition booths.

Each team has already been assigned a preparation period with a starting time and an ending time. However, due to a planning mistake, several teams have been scheduled during overlapping periods. Since all teams need access to the same central workspace, overlapping preparations cannot take place simultaneously.

The event coordinator, Riya, wants to organize the teams into the smallest possible number of independent preparation zones. Every zone follows a separate schedule, meaning teams assigned to the same zone must never overlap in time. Whenever two teams have overlapping preparation periods, they must be placed in different zones.

Two preparation periods are considered non-conflicting if one finishes at or before the other begins.

Help Riya calculate the minimum number of preparation zones required so that every team's assigned preparation period can be accommodated without changing any timings.

Input Format
The first line contains an integer N, representing the number of preparation teams.

Each of the next N lines contains two space-separated integers:

S – starting time.

E – ending time.

Output Format
Print a single integer representing the minimum number of preparation zones required.

Constraints
1 ≤ N ≤ 200000

0 ≤ S < E ≤ 10^9

Sample Testcase 0
Testcase Input
5
1 4
2 5
3 6
6 8
7 9
Testcase Output
3
Explanation
Preparation schedule:


Team A : [1-----4]


Team B :   [2-----5]


Team C :     [3-----6]


Team D :           [6---8]


Team E :             [7---9]


During the time interval between 3 and 4, three teams are working simultaneously.


One possible allocation is:


Zone 1 : A → D


Zone 2 : B → E


Zone 3 : C


              Timeline


             1 2 3 4 5 6 7 8 9


              |  |  |  |  |  |  |  |  |


Zone 1 : [   A  ]     [ D ]


Zone 2 :    [   B  ]      [ E ]


Zone 3 :       [   C  ]


Since no arrangement can place these three overlapping teams into fewer than three zones, the answer is 3.

Sample Testcase 1
Testcase Input
6
1 3
2 4
4 6
5 8
6 7
8 10
Testcase Output
2
Explanation
Preparation schedule:


A : [1---3]


B :   [2---4]


C :       [4---6]


D :         [5-----8]


E :           [6---7]


F :                 [8---10]


A valid assignment is:


Zone 1 : A → C → E → F


Zone 2 : B → D


Timeline


             1 2 3 4 5 6 7 8 9 10


              |  |  |  |  |  |  |  |  |   |


Zone 1 : [ A ]  [ C ][E] [  F  ]


Zone 2 :    [ B ]  [   D  ]


Only two preparation zones are sufficient for all teams.


Therefore, the answer is 2.