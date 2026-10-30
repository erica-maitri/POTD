Problem Statement
Kabir supervises the overnight parcel desk at Harishpur Junction, where goods wait on shelves until a freight wagon pulls in with room to spare. Every parcel has a unique identifier and a promised delivery deadline. Whenever a wagon arrives, Kabir loads the waiting parcel with the nearest deadline. If two waiting parcels share that nearest deadline, the one with the smaller identifier goes first.

The booking office keeps sending short messages to the desk throughout the night. A message may announce a freshly booked parcel along with its deadline. It may report that a customer has moved the deadline of a waiting parcel to a new value, which can be earlier or later than the old one. It may report that a customer has withdrawn a waiting parcel completely. Finally, it may announce that a wagon has just pulled in and wants exactly one parcel. A parcel that has been loaded or withdrawn leaves the shelves permanently, though the booking office is allowed to hand the same identifier to a brand new parcel later.

Kabir used to walk the whole length of the shelves every time a wagon arrived, and on busy nights this left trains idling on the platform. The desk may now receive hundreds of thousands of messages in one shift, so he needs the loading log to be produced quickly. The messages are always consistent: a deadline change or a withdrawal always names a parcel that is waiting at that moment, and a booking never uses an identifier that is currently waiting.

For every wagon message, Kabir wants the identifier of the parcel that was loaded, written on its own line in the same order in which the wagons arrived. When no parcel is waiting at the moment a wagon pulls in, he writes the word IDLE for that wagon instead.

Input Format
The first line contains an integer Q, the number of messages.

Each of the next Q lines is one message in one of these forms:

ARRIVE id deadline for a newly booked parcel.
DELAY id deadline to change the deadline of a waiting parcel.
CANCEL id to withdraw a waiting parcel.
DISPATCH for a wagon that wants one parcel.
Output Format
For every DISPATCH message, print one line containing the identifier of the loaded parcel, or IDLE if no parcel is waiting.

Constraints
1 ≤ Q ≤ 200000

1 ≤ id ≤ 200000

1 ≤ deadline ≤ 10^9

All messages are consistent as described in the statement.

Sample Testcase 0
Testcase Input
8
ARRIVE 5 30
ARRIVE 2 20
ARRIVE 9 20
DELAY 2 50
CANCEL 5
DISPATCH
DISPATCH
DISPATCH
Testcase Output
9
2
IDLE
Explanation

Parcels 5, 2 and 9 are booked with deadlines 30, 20 and 20. Parcel 2 is then moved to deadline 50, and parcel 5 is withdrawn.

Only parcels 9 (deadline 20) and 2 (deadline 50) remain, so the first wagon takes parcel 9.

The second wagon takes parcel 2.

The third wagon finds the shelves empty, so the log says IDLE.

Sample Testcase 1
Testcase Input
9
ARRIVE 7 10
ARRIVE 3 10
DISPATCH
DELAY 7 5
ARRIVE 4 7
DISPATCH
DISPATCH
ARRIVE 3 100
DISPATCH
Testcase Output
3
7
4
3
Explanation

Parcels 7 and 3 both have deadline 10, so the tie goes to the smaller identifier and the first wagon takes parcel 3.

Parcel 7 is moved up to deadline 5 and parcel 4 arrives with deadline 7. The second wagon takes parcel 7 and the third takes parcel 4.

Identifier 3 is reused for a new parcel with deadline 100.

The last wagon takes this new parcel 3.
