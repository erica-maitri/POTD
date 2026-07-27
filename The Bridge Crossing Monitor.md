Problem Statement
A newly constructed suspension bridge connects two remote towns separated by a deep valley.

To ensure safety, the bridge authority has imposed a strict rule: at any moment, only a limited number of vehicles can be on the bridge.

Throughout the day, vehicles arrive at one end of the bridge and wait for permission to enter.

Whenever a vehicle completes its crossing, it leaves the bridge, making room for another waiting vehicle.

The monitoring system records two types of events:

- A vehicle arrives and joins the waiting line.
- A vehicle finishes crossing and leaves the bridge.

At the end of the day, the chief engineer wants to know which vehicle is currently at the front of the waiting line.

If no vehicles are waiting, the system should report that the line is empty.

You must process all recorded events and determine the vehicle that would be granted permission next.

Input Format
The first line contains an integer N, the number of recorded events.

The next N lines each contain one event.

An event is either:

- ENTER X

- EXIT

Output Format
The ID of the vehicle currently at the front of the waiting line.

EMPTY if no vehicles are waiting.

Constraints
1 ≤ N ≤ 10^5

1 ≤ X ≤ 10^9

Sample Testcase 0
Testcase Input
7
ENTER 10
ENTER 20
ENTER 30
EXIT
ENTER 40
EXIT
ENTER 50
Testcase Output
30
Explanation
Processing the events:


ENTER 10


Front → [10]


ENTER 20


Front → [10][20]


ENTER 30


Front → [10][20][30]


EXIT


10 leaves


Front → [20][30]


ENTER 40


Front → [20][30][40]


EXIT


20 leaves


Front → [30][40]


ENTER 50


Front → [30][40][50]


The vehicle at the front is:


30

Sample Testcase 1
Testcase Input
6
ENTER 100
EXIT
EXIT
ENTER 200
EXIT
EXIT
Testcase Output
EMPTY
Explanation
ENTER 100


Front → [100]


EXIT


100 leaves


Front → [ ]


EXIT


No effect


ENTER 200


Front → [200]


EXIT


200 leaves


Front → []


EXIT


No effect


No vehicles remain in the waiting line.


Therefore:


EMPTY