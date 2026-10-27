Problem Statement
Meera looks after the returns cart at the Rosewood Reading Room, a small library where visitors drop borrowed books into a chute that feeds a narrow cart. Every book carries a genre code printed on its spine. Because the cart is so narrow, each returned book lands on top of the pile already there, and when Meera begins shelving she can only lift the book that sits at the very top. A book that arrived early becomes reachable only after every book dropped later has been shelved.

Throughout the day the front desk sends Meera three kinds of notes. One announces that a visitor has just returned a book, along with its genre code. Another tells her to shelve one book, and she always shelves the book at the top of the pile. The front desk never sends this note when the cart is empty. The last asks for a status report, which the head librarian uses to decide how many shelving trolleys to prepare.

A status report consists of two figures. The first is the genre code of the book currently at the top of the pile, or 0 when the cart holds no books at all. The second is the number of different genres present on the cart at that moment, with each genre counted once no matter how many of its books are on the pile.

On festival weekends the desk can send hundreds of thousands of notes in a single day. The head librarian wants every status report answered the instant it is requested, because a slow answer delays the whole shelving round. Meera therefore needs each report ready without re-examining the entire cart.

Meera writes the two figures of each status report on one line, in the same order in which the reports were requested.

Input Format
The first line contains an integer Q, the number of notes.

Each of the next Q lines is one note in one of these forms:

+ g for a returned book with genre code g.
- for shelving the book at the top of the pile.
? for a status report.
Output Format
For every ? note, print one line with two space separated integers: the genre code of the top book (or 0 if the cart is empty) and the number of different genres on the cart.

Constraints
1 ≤ Q ≤ 300000

1 ≤ g ≤ 10^6

A - note is never sent while the cart is empty.

Sample Testcase 0
Testcase Input
9
+ 12
+ 7
+ 12
?
-
?
-
-
?
Testcase Output
12 2
7 2
0 0
Explanation

Books with genres 12, 7 and 12 are placed in that order, so the pile holds two genres and genre 12 is on top.

After one book is shelved, the second 12 is gone, but the first 12 is still lower in the pile. The top is now 7 and two genres remain.

Shelving two more books removes 7 and then the first 12.

The last report finds an empty cart, so it prints 0 0.

Sample Testcase 1
Testcase Input
10
+ 3
+ 8
+ 8
-
-
+ 3
?
-
+ 20
?
Testcase Output
3 1
20 2
Explanation

Books 3, 8, 8 are placed, then the two 8s are shelved, leaving only the first 3.

Another 3 is placed, so the first report sees top genre 3 and just one genre on the cart.

Shelving removes the top 3, and a book of genre 20 is placed.

The cart now holds genres 3 and 20 with 20 on top, so the second report is 20 2.
