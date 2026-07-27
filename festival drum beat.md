<<<<<<< HEAD
Problem Statement
During the Grand River Festival, two giant ceremonial drums are played continuously.

Kabir's drum produces a loud beat every A seconds.
Tara's drum produces a loud beat every B seconds.
At the start of the celebration, both drums are struck together.

The event organizer wants to know after how many seconds the next simultaneous loud beat will occur. This helps synchronize fireworks and stage performances.

Given the beat intervals of the two drums, determine the waiting time until they sound together again.

Illustration: 

Kabir's Drum : every 4 sec
Tara's Drum : every 6 sec
Time:
0 1 2 3 4 5 6 7 8 9 10 11 12

K : *       *       *       *
T : *           *           *

Both together again at 12
Input Format
Two integers A and B.

Output Format
Print the time after which both drums beat together again.

Constraints
1 ≤ A, B ≤ 105

Sample Testcase 0
Testcase Input
4 6
Testcase Output
12
Explanation
The first common beat after the start occurs at 12 seconds.

Sample Testcase 1
Testcase Input
5 8
Testcase Output
40
Explanation
40 is the earliest moment when both drum patterns align again.

..................................................
Take 4 and 6.

Factors

4 : 1, 2, 4
6 : 1, 2, 3, 6

Common = 1, 2
HCF = 2

Multiples

4 : 4, 8, 12, 16, 20...
6 : 6, 12, 18, 24...

LCM = 12

This is exactly your drum problem:

Drum A beats every 4 sec
Drum B beats every 6 sec
They beat together again after 12 sec (the LCM).
Easy Trick to Remember
HCF   |	LCM
Think Divide	|Think Multiply
Largest common factor |	Smallest common multiple
Answer is ≤ both numbers	| Answer is ≥ both numbers
Used when splitting/grouping |	Used when matching cycles/events
Shortcut Formula

If you know the HCF (GCD), then:

LCM=A×B/HCF

Example:
For 4 and 6:

HCF = 2
LCM = (4 × 6) ÷ 2 = 24 ÷ 2 = 12

So whenever you see problems like two clocks, two drums, traffic lights, buses, or events repeating, think LCM. Whenever you see largest equal groups, dividing things equally, or greatest number that divides both, think HCF.

Yes! You do take the common factors in HCF. The important part is that you choose the largest one.

HCF = Highest Common Factor
GCD = Greatest Common Divisor

=======
Problem Statement
During the Grand River Festival, two giant ceremonial drums are played continuously.

Kabir's drum produces a loud beat every A seconds.
Tara's drum produces a loud beat every B seconds.
At the start of the celebration, both drums are struck together.

The event organizer wants to know after how many seconds the next simultaneous loud beat will occur. This helps synchronize fireworks and stage performances.

Given the beat intervals of the two drums, determine the waiting time until they sound together again.

Illustration: 

Kabir's Drum : every 4 sec
Tara's Drum : every 6 sec
Time:
0 1 2 3 4 5 6 7 8 9 10 11 12

K : *       *       *       *
T : *           *           *

Both together again at 12
Input Format
Two integers A and B.

Output Format
Print the time after which both drums beat together again.

Constraints
1 ≤ A, B ≤ 105

Sample Testcase 0
Testcase Input
4 6
Testcase Output
12
Explanation
The first common beat after the start occurs at 12 seconds.

Sample Testcase 1
Testcase Input
5 8
Testcase Output
40
Explanation
40 is the earliest moment when both drum patterns align again.

..................................................
Take 4 and 6.

Factors

4 : 1, 2, 4
6 : 1, 2, 3, 6

Common = 1, 2
HCF = 2

Multiples

4 : 4, 8, 12, 16, 20...
6 : 6, 12, 18, 24...

LCM = 12

This is exactly your drum problem:

Drum A beats every 4 sec
Drum B beats every 6 sec
They beat together again after 12 sec (the LCM).
Easy Trick to Remember
HCF   |	LCM
Think Divide	|Think Multiply
Largest common factor |	Smallest common multiple
Answer is ≤ both numbers	| Answer is ≥ both numbers
Used when splitting/grouping |	Used when matching cycles/events
Shortcut Formula

If you know the HCF (GCD), then:

LCM=A×B/HCF

Example:
For 4 and 6:

HCF = 2
LCM = (4 × 6) ÷ 2 = 24 ÷ 2 = 12

So whenever you see problems like two clocks, two drums, traffic lights, buses, or events repeating, think LCM. Whenever you see largest equal groups, dividing things equally, or greatest number that divides both, think HCF.

Yes! You do take the common factors in HCF. The important part is that you choose the largest one.

HCF = Highest Common Factor
GCD = Greatest Common Divisor

>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
They are just two different names for the same concept.