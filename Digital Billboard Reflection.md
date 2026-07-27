Problem Statement
A technology company designs advanced digital billboards for shopping malls and public spaces. Before deploying a new advertising display, engineers perform a series of visual tests to ensure that images and patterns appear correctly under different display modes.

One of these tests is called Mirror Mode. In this mode, the content displayed on the screen is reflected horizontally, similar to what would be seen in a mirror. The display is represented as a rectangular grid of numerical values, where each value corresponds to the brightness level of a specific display unit.

When Mirror Mode is activated, the positions of the rows remain unchanged. However, within each row, the display units must appear in reverse order. The leftmost value becomes the rightmost value, the second leftmost becomes the second rightmost, and so on.

The engineers have already collected the original display configuration and need your help generating the reflected version. Given the display grid, produce the arrangement that would appear after Mirror Mode is applied.

Input Format
The first line contains two integers R and C.
Next R lines contain C integers.

Output Format
Print the reflected grid.

Constraints
1 ≤ R, C ≤ 100
0 ≤ value ≤ 1000

Sample Testcase 0
Testcase Input
3 2
8 9
1 5
4 7
Testcase Output
9 8
5 1
7 4
Explanation
The elements of every row are printed from right to left.

Sample Testcase 1
Testcase Input
2 3
1 2 3
4 5 6
Testcase Output
3 2 1
6 5 4
Explanation
Each row is reversed independently.