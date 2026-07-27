Problem Statement
A massive storm has struck several villages in a remote valley. The disaster management team has established a central warehouse containing emergency supply packages. Each package has a priority score indicating how urgently it should be dispatched. A higher score means the package contains more critical supplies such as medicines, food, or rescue equipment.

Due to limited transportation capacity, the team can send only one package at a time. To ensure that the most important supplies reach affected areas first, the dispatch system always chooses the package with the highest priority among all currently available packages.

As new packages continue arriving at the warehouse, the operators record their priority scores. After all packages have been registered, the rescue coordinator wants to know which packages will be dispatched first.

Your task is to determine the priorities of the first K dispatched packages in the exact order they leave the warehouse.

Input Format
The first line contains two integers, N and K.

Second line contains N space-separated integers representing package priorities.

Output Format
Print K integers representing the dispatch order.

(Multiple packages may have the same priority. The output should contain only the priority values of the first K dispatched packages in non-increasing order.)

Constraints
1 ≤ K ≤ N ≤ 10^5

−2^31 ≤ Priority ≤ 2^31 − 1

Sample Testcase 0
Testcase Input
5 2
12 45 18 90 27
Testcase Output
90 45
Explanation
The first package dispatched has priority 90, followed by 45.

Sample Testcase 1
Testcase Input
6 3
40 15 60 25 80 35
Testcase Output
80 60 40