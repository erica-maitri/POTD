Problem Statement
Aarav works the night shift at a hillside telecom relay station that logs the signal strength reading (an integer) from a distant satellite once every second. His supervisor has asked him to identify the longest continuous stretch of seconds during which the tower could have safely run in "synchronization mode."

Synchronization mode has two hard rules, both discovered the hard way after a outage last monsoon:

Within the chosen stretch, the difference between the strongest and weakest reading must never exceed a tolerance value D. A bigger swing confuses the tower's auto-gain circuit.
No exact reading may repeat within the stretch. A repeated value earlier in the night meant a stuck sensor, and the engineers later learned that a repeat inside the same stretch is a reliable predictor of a glitch, so any stretch containing a duplicate is rejected outright.
Aarav has the full log of readings for the night and needs the length of the longest stretch obeying both rules, along with where it begins, so the report can reference the exact timestamps. If several stretches tie for the longest length, he wants the one that starts earliest.

He tried checking every possible stretch by hand for the first hour of data and gave up after realizing the full night's log has tens of thousands of entries clearly this needs to be automated before his shift ends.

Input Format
Line 1: two integers N D: number of readings and the tolerance.
Line 2: N space-separated integers, the readings in order (1-indexed seconds).
Output Format
Two space-separated integers: the length of the longest valid stretch, and the 1-indexed second at which it starts (earliest such start if tied).

Constraints
1 <= N <= 10^5

0 <= D <= 10^9

1 <= reading[i] <= 10^9

Sample Testcase 0
Testcase Input
5 5
10 20 15 25 30
Testcase Output
2 2
Explanation

Starting at second 1 with value 10, adding second 2 (value 20) creates a difference of 10, which exceeds D = 5, so the window must drop second 1.

The stretch [20, 15] (seconds 2–3) has a difference of 5 (<= D) and both values are distinct — valid, length 2.

Adding second 4 (value 25) to that stretch makes the difference 10 again, forcing another shrink.

The stretch [25, 30] (seconds 4–5) is also valid with length 2, tying the earlier stretch but starting later.

The longest length is 2, and the earliest stretch achieving it starts at second 2.

Sample Testcase 1
Testcase Input
6 2
3 5 4 3 6 5
Testcase Output
3 1
Explanation

The stretch [3, 5, 4] (seconds 1–3) has max 5, min 3, difference 2 (<= D), and all three values are distinct — valid, length 3.

Extending to second 4 brings in another 3, which duplicates the reading at second 1, so the window must shrink until the duplicate is excluded.

The stretch [5, 4, 3] (seconds 2–4) is also valid with length 3, but it starts later than the first stretch found.

Continuing the scan, no stretch beyond length 3 satisfies both the difference rule and the distinctness rule.

The longest length is 3, and the earliest stretch achieving it starts at second 1.
