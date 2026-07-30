Problem Statement
The Heritage Museum of Ashwood houses thousands of ancient artifacts collected from archaeological excavations across different countries. Every artifact is assigned a unique registration number before it is placed inside the museum's secure storage vaults.

Every year, during the Annual Preservation Audit, Curator Meera asks two independent departments to submit the registration numbers of all artifacts currently under their responsibility. The Storage Department records every artifact physically present in the vault, while the Preservation Department records every artifact that has completed its preservation process.

After both departments submit their reports, the records are merged into a single ledger. According to museum policy, every properly processed artifact should appear exactly twice in this merged ledger—once from each department.

However, this year, one newly excavated artifact reached the storage vault just before the audit began. Since it has not yet undergone preservation, its registration number appears only once in the merged ledger, whereas every other registration number appears exactly twice.

Meera wants to identify this artifact before the museum opens to visitors. Manually checking thousands of records would take hours, so she decides to use a computer program to examine the merged ledger.

It is guaranteed that there is exactly one registration number that appears only once.

Print the registration number of the artifact that is still waiting for preservation.

Input Format
The first line contains an integer N, representing the total number of registration numbers.

The second line contains N space-separated integers representing the merged ledger.

Output Format
Print the registration number that appears only once.

Constraints
1 ≤ N ≤ 100000

N is always odd.

1 ≤ Registration Number ≤ 10^9

Exactly one registration number appears once.

Every other registration number appears exactly twice.

Sample Testcase 0
Testcase Input
7
312 451 129 312 451 278 129
Testcase Output
278
Explanation
The museum receives the following merged ledger:


312 451 129 312 451 278 129


The curator checks how many times every registration number appears.


Registration Number	First Appearance	Second Appearance	Total Count
312	yes	yes	2
451	yes	yes	2
129	yes	yes	2
278	yes	no	1

Since every properly processed artifact should appear twice, the only registration number that violates the rule is 278.


Final Verification


312  


451  


129  


278  ← Missing Preservation Entry


Therefore, the program prints


278

Sample Testcase 1
Testcase Input
11
900 145 673 145 900 421 673 810 810 256 256
Testcase Output
421
Explanation
The merged ledger contains


900 145 673 145 900 421 673 810 810 256 256


The occurrence of every registration number is checked.


Registration Number	Number of Occurrences
900	2
145	2
673	2
810	2
256	2
421	1

Every registration number except 421 appears exactly twice.


Since 421 appears only once, it represents the newly arrived artifact that has not yet completed preservation.


Hence, the output is


421