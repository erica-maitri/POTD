Problem Statement
Tara runs a small community radio archive that registers new operator call signs as they come in, one at a time, over the course of an evening. Every call sign is a string of uppercase letters, and Tara has noticed an odd pattern: many new call signs are formed by extending an already-registered call sign with a few extra letters, since operators from the same club tend to pick related signs.

She wants a "novelty score" for every call sign as it arrives, based only on the call signs registered strictly before it:

If the incoming call sign is a brand-new string never registered before, its novelty score is its full length minus the length of the longest already-registered call sign that is also an exact prefix of it. If no registered call sign is a prefix, the score is just its full length.
If the incoming call sign is an exact duplicate of a call sign registered earlier in the evening, it is flagged instead of scored. Tara logs these separately as likely re-transmissions of the same registration request, and they contribute nothing to her nightly novelty total.
Every call sign that is not a duplicate gets permanently added to the archive (available for matching against future arrivals), while duplicates are simply flagged and not scored.

At the end of the evening, alongside the per-arrival results, Tara wants the running total of all novelty scores, since her club uses that number to gauge how much genuinely new naming activity happened.

She tried tracking this by eye for the first few dozen entries and quickly lost track once call signs started sharing long common beginnings she needs this automated for the full night's log, which can run into thousands of entries.

Input Format
Line 1: integer N — number of call signs registered during the evening.
Next N lines: one call sign each, a non-empty string of uppercase letters A–Z, in arrival order.
Output Format
Print N lines. For each call sign, in arrival order, print its novelty score, or -1 if it was flagged as a duplicate. After the N lines, print a final line in the format Total: X where X is the sum of all novelty scores (duplicates contribute nothing).

Constraints
1 <= N <= 2 * 10^4

1 <= length of each call sign <= 20

Sum of all call sign lengths <= 2 * 10^5

Each character is an uppercase English letter (A–Z) or a digit (0–9), matching real-world call sign formats

Sample Testcase 0
Testcase Input
4
A
AB
ABC
ABCD
Testcase Output
1
1
1
1
Total: 4
Explanation

A arrives with an empty archive: score = 1 - 0 = 1. Added to the archive.

AB arrives; A is a registered prefix of it (length 1): score = 2 - 1 = 1. Added to the archive.

ABC arrives; the longest registered prefix is now AB (length 2), not just A: score = 3 - 2 = 1. Added to the archive.

ABCD arrives; the longest registered prefix is ABC (length 3): score = 4 - 3 = 1.

Every step contributes exactly one new letter of novelty, so the total is 4.

Sample Testcase 1
Testcase Input
5
VU2ABC
VU2AB
VU2ABCD
VU2AB
VU2XY
Testcase Output
6
5
1
-1
5
Total: 17
Explanation

VU2ABC arrives first with nothing registered yet, so no prefix match exists: score = 6 - 0 = 6. It is added to the archive.

VU2AB arrives next; VU2ABC is longer than VU2AB so it cannot be a prefix of it, and no other registered sign matches either: score = 5 - 0 = 5. It is added to the archive.

VU2ABCD arrives; the registered sign VU2ABC (length 6) is an exact prefix of it, and it's the longest such match: score = 7 - 6 = 1. It is added to the archive.

VU2AB arrives again; it exactly matches a call sign registered earlier (from the second arrival), so it is flagged as a duplicate: output -1, and it contributes nothing to the total.

VU2XY arrives; it shares the letters VU2 with several registered signs but none of those registered signs matches it fully as a prefix (they diverge at the 4th character), so no registered sign qualifies: score = 5 - 0 = 5.

Total = 6 + 5 + 1 + 5 = 17 (the duplicate is excluded).