Problem Statement
Dev operates the main entry console at a multi-day music festival. Every attendee wears an RFID wristband with a numeric ID, and every time someone walks through a gate, the console logs a + scan for that ID. Occasionally a scanner misfires and logs the same person twice in a row; when a gate staffer notices, they issue a - correction for that ID to cancel out the erroneous extra scan. Dev is guaranteed that a - correction is only ever issued for an ID that currently has at least one uncancelled scan.

At the end of each day, Dev needs to know the K wristband IDs with the highest net scan count (total + scans minus total - corrections for that ID). Wristbands whose net count drops to zero or below are treated as never having genuinely entered and are excluded entirely.

When two IDs are tied on net scan count, Dev breaks the tie using whichever ID was scanned first that day (the smaller position in the log at which its very first + occurred) that's the ordering his sponsorship dashboard expects, since sponsors care about early, loyal attendees.

If fewer than K wristbands end the day with a positive net count, Dev only wants however many actually qualify he doesn't want the report padded with anything.

Dev has thousands of scan events to process by the time the gates close, far too many to tally by hand, and he needs the day's leaderboard ready the moment the last gate shuts.

Input Format
Line 1: two integers N K: number of scan events and the leaderboard size requested.
Next N lines: each either + id or - id, describing one scan event in chronological order.
Output Format
Print up to K lines (fewer if fewer IDs qualify), each containing an ID and its net scan count, space-separated, ordered by net count descending and, for ties, by first-scan position ascending.

Constraints
1 <= N <= 10^5

1 <= K <= 10^5

1 <= id <= 10^9

Every - event refers to an ID with a currently positive net count

Sample Testcase 0
Testcase Input
8 2
+ 101
+ 202
+ 101
- 202
+ 303
+ 101
+ 202
+ 303
Testcase Output
101 3
303 2
Explanation

ID 101 is scanned at events 1, 3, and 6, all +, giving a net count of 3, first seen at event 1.

ID 202 is scanned + at event 2, corrected - at event 4, then scanned + again at event 7, giving a net count of 1, first seen at event 2.

ID 303 is scanned + at events 5 and 8, giving a net count of 2, first seen at event 5.

Ranking by net count descending: 101 (3), then 303 (2), then 202 (1).

Only the top K = 2 are printed: 101 3 followed by 303 2.

Sample Testcase 1
Testcase Input
6 3
+ 5
+ 7
+ 5
- 7
+ 9
- 9
Testcase Output
5 2
Explanation

ID 5 is scanned + at events 1 and 3, giving a net count of 2.

ID 7 is scanned + at event 2 and corrected - at event 4, giving a net count of 0, so it is excluded.

ID 9 is scanned + at event 5 and corrected - at event 6, giving a net count of 0, so it is excluded.

Only ID 5 has a positive net count, so even though K = 3 was requested, just one line qualifies.

The output is exactly 5 2, with no padding for the unmet remainder of K.