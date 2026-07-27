Problem Statement
An old archive room stores important records in a vertical pile. Whenever a new record arrives, it is placed on top of the existing pile. During inspections, archivists always remove records from the top because the records underneath cannot be accessed directly. As a result, the order of records in the pile keeps changing throughout the day as records are added and removed.

At the end of the day, the chief archivist wants to quickly identify which record is currently visible at the top of the pile. You are given a list of operations that describe how the pile changes over time. Each operation either places a new record on top of the pile or removes the current top record.

After processing all operations in the given order, determine the value of the record that remains at the top. If every record has been removed and the pile becomes empty, print -1.

The operations must be performed exactly in the order they are provided, since each operation affects the state of the pile for the next one. Your task is to simulate these changes and report the final visible record.

Input Format
The first line contains an integer N, representing the number of operations.

The next N lines contain one operation each.

Operations can be:
ADD X     → Place record X on top of the pile.
REMOVE    → Remove the current top record.

Output Format
Print the value of the record currently at the top after all operations.

Print -1 if the pile becomes empty.

Constraints
1 ≤ N ≤ 100000
1 ≤ X ≤ 1000000000

Sample Testcase 0
Testcase Input
5
ADD 10
ADD 20
ADD 30
REMOVE
ADD 40
Testcase Output
40
Explanation
Operations performed:


ADD 10    -> [10]
ADD 20    -> [10, 20]
ADD 30    -> [10, 20, 30]
REMOVE    -> [10, 20]
ADD 40    -> [10, 20, 40]


The record at the top is 40.

Sample Testcase 1
Testcase Input
6
ADD 15
ADD 25
REMOVE
REMOVE
ADD 50
REMOVE
Testcase Output
-1
Explanation
Operations performed:


ADD 15    -> [15]
ADD 25    -> [15, 25]
REMOVE    -> [15]
REMOVE    -> []
ADD 50    -> [50]
REMOVE    -> []


No records remain in the pile, so the answer is -1.