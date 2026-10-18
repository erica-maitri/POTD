Problem Statement
Riya works the night shift as a corridor safety inspector for the Eastern rail line. Along a straight stretch of track there are n signal posts in a row, and the current brightness of each lamp has just been logged in order. Regulation requires every possible block of k consecutive posts to be reviewed as a unit: within such a block, inspectors only care about the single brightest lamp, since that is the one a driver actually notices from a distance. As the review block slides one post at a time from the beginning of the corridor to the end, Riya must record the brightness of the standout lamp for every position the block occupies.

Once the slide finishes, her supervisor asks a follow up question for the incident report: across every block that was reviewed, which brightness value kept turning up as the standout lamp more often than any other value did? If two brightness values were the standout the same number of times, the report should favour the smaller of the two, since a lower certified standard is considered safer to sign off on.

Riya needs the complete list of standout brightness values, one for every block position in order, and afterward the single dominant value together with how many blocks it dominated. Both pieces are needed quickly, well before the next train is due to leave the yard, so she can attach them to tonight's report and move on to the next stretch of track.

Help Riya put together the review log for tonight's corridor. 

Input Format
Line 1: two integers n and k.
Line 2: n integers, the brightness of each lamp in order along the corridor.
Output Format
Line 1: n minus k plus 1 integers, the standout brightness for every block position, in order, separated by single spaces.
Line 2: two integers, the dominant brightness value and the number of blocks it stood out in.
Constraints
1 <= k <= n <= 2 * 10^5

1 <= brightness_i <= 10^9

Sample Testcase 0
Testcase Input
5 2
7 7 1 9 9
Testcase Output
7 7 9 9
7 2
Explanation

The blocks are [7,7], [7,1], [1,9], [9,9], giving standout values 7, 7, 9, 9.

Both 7 and 9 stood out exactly twice, a tie.

The report favours the smaller value, so 7 is reported as dominant with count 2.

Sample Testcase 1
Testcase Input
6 3
4 3 5 5 2 6
Testcase Output
5 5 5 6
5 3
Explanation

The blocks are [4,3,5], [3,5,5], [5,5,2], [5,2,6].

Their standout brightness values are 5, 5, 5, 6 respectively.

Value 5 stood out in 3 blocks while 6 stood out in only 1, so 5 is dominant.