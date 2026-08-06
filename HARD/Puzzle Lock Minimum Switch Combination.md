Problem Statement
An escape-room puzzle lock has M labeled switches (numbered 0 to M-1) and M indicator lights, also numbered 0 to M-1. Each light is either ON or OFF, and the entire light panel's state can be represented as an M-bit integer, where bit k is 1 if light k is ON.

Pressing switch i instantly toggles a fixed set of lights — this fixed set is given as a bitmask mask[i]: pressing switch i XORs the current panel state with mask[i]. Note that pressing the same switch twice in a row cancels itself out (since XOR-ing with the same mask twice returns the panel to what it was before), so no useful strategy ever presses the same switch more than once — only whether each switch is pressed an odd number of times matters, not how many times or in what order.

You are given the starting panel state S and the desired target panel state T. Determine the minimum number of switches that must be pressed (each at most once) so that the final panel state equals T. If it is impossible to reach T from S using any subset of the available switches, output -1.

Input Format
M

mask[0] mask[1] ... mask[M-1]

S T

Output Format
A single integer: the minimum number of switches required, or -1 if it is impossible.

Constraints
1 ≤ M ≤ 20
0 ≤ mask[i] < 2^M
0 ≤ S, T < 2^M
Time Limit: 2 sec
Memory Limit: 256 MB
The output is unique.
Sample Testcase 0
Testcase Input
4
3 5 9 12
6 10
Testcase Output
1
Explanation
S = 6 (0110), T = 10 (1010). We need a subset of switches whose masks XOR together to S XOR T = 6 XOR 10 = 12 (1100). Switch 3 alone has mask[3] = 12, which exactly matches. So a single switch press suffices, and the answer is 1.

Sample Testcase 1
Testcase Input
3
1 2 4
0 3
Testcase Output
2
Explanation
S XOR T = 0 XOR 3 = 3. No single mask equals 3, but mask[0] XOR mask[1] = 1 XOR 2 = 3. So pressing switches 0 and 1 together achieves the target, and no single switch works, so the minimum is 2.