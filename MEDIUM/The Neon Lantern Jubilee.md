Problem Statement
Every year, the riverside town where Ananya lives hosts the spectacular Neon Lantern Jubilee. A long boardwalk is decorated with N floating neon lanterns, numbered from 1 to N. Each lantern glows with a unique color spectrum represented by a non-negative integer called its identification code.

To create the grand opening drone show, Ananya programs drones to fly over continuous segments of lanterns. A flight path begins at lantern L and ends at lantern R (1 ≤ L ≤ R ≤ N).

According to the festival tradition, a flight path is considered Perfectly Harmonized if the bitwise XOR of all lantern identification codes in that segment is exactly equal to the festival's special Cosmic Key value K.

Since thousands of lanterns illuminate the boardwalk and the number of possible flight paths is enormous, manually checking every segment is impossible.

Help Ananya determine the total number of continuous lantern segments whose cumulative XOR value is exactly K.

Input Format
The first line contains two integers N and K, representing the number of lanterns and the Cosmic Key.

The second line contains N space-separated non-negative integers representing the identification code of each lantern.

Output Format
Print a single integer representing the total number of continuous lantern segments whose bitwise XOR is exactly K.

Constraints
1 ≤ N ≤ 100000

0 ≤ K ≤ 10⁹

0 ≤ Lantern Code ≤ 10⁹

Sample Testcase 0
Testcase Input
5 6
3 4 2 1 5
Testcase Output
2
Explanation
The lantern identification codes are:


Lantern Position	1	2	3	4	5
Identification Code	3	4	2	1	5

The Cosmic Key is K = 6.


All continuous segments are checked.


Segment	XOR Value	Perfectly Harmonized
(1,1) → [3]	3	No
(1,2) → [3,4]	7	No
(1,3) → [3,4,2]	5	No
(1,4) → [3,4,2,1]	4	No
(1,5) → [3,4,2,1,5]	1	No
(2,2) → [4]	4	No
(2,3) → [4,2]	6	Yes
(2,4) → [4,2,1]	7	No
(2,5) → [4,2,1,5]	2	No
(3,3) → [2]	2	No
(3,4) → [2,1]	3	No
(3,5) → [2,1,5]	6	Yes
(4,4) → [1]	1	No
(4,5) → [1,5]	4	No
(5,5) → [5]	5	No

The valid segments are:



(2,3)

(3,5)


Hence, the answer is: 2

Sample Testcase 1
Testcase Input
4 0
2 2 3 3
Testcase Output
3
Explanation
The lantern identification codes are:


Lantern Position	1	2	3	4
Identification Code	2	2	3	3

The Cosmic Key is K = 0.


All continuous segments are examined.


    Segment	XOR Value	Perfectly Harmonized
(1,1) → [2]	2	No
(1,2) → [2,2]	0	Yes
(1,3) → [2,2,3]	3	No
(1,4) → [2,2,3,3]	0	Yes
(2,2) → [2]	2	No
(2,3) → [2,3]	1	No
(2,4) → [2,3,3]	2	No
(3,3) → [3]	3	No
(3,4) → [3,3]	0	Yes
(4,4) → [3]	3	No

The valid segments are:



(1,2)

(1,4)

(3,4)


Hence, the total number of Perfectly Harmonized segments is: 3