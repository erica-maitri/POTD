<<<<<<< HEAD
Problem Statement
In the floating kingdom of Aetheria, dreams are not merely thoughts they are woven into giant Resonance Tapestries that power the cities suspended above the clouds.

Riya, the kingdom's youngest Dream Weaver, has been assigned the task of preparing a ceremonial tapestry for the Festival of Dawn. The tapestry is not woven all at once. Instead, it is created through a sequence of magical weaving frames.

Each frame transforms dream-energy from one resonance size into another. A frame that accepts energy of size a × b produces energy of size b × c. Since the output of one frame becomes the input of the next, the entire weaving process forms a valid chain.

Whenever two neighboring weaving results are fused together, magical effort is consumed. If one woven segment has dimensions x × y and the next has dimensions y × z, then the fusion requires:

x × y × z

units of dream-energy.

Different orders of fusion can lead to dramatically different energy costs.

The Royal Council has limited the total dream-energy available for the ceremony. Before the weaving begins, Riya must calculate the smallest possible amount of dream-energy required to complete the entire tapestry.

The chain of weaving frames is guaranteed to be valid.

Input Format
First line contains an integer N, the number of weaving frames.

Next line contains N+1 integers.

If the values are:

p0 p1 p2 ... pN

then the frames are:

p0×p1
p1×p2
...
p(N-1)×pN

Output Format
Print a single integer representing the minimum dream-energy required.

Constraints
2 ≤ N ≤ 200

1 ≤ pi ≤ 1000

Sample Testcase 0
Testcase Input
4
10 20 30 40 30
Testcase Output
30000
Explanation
Among all valid fusion plans, the minimum required dream-energy is 30000.

Sample Testcase 1
Testcase Input
3
20 30 10 40
Testcase Output
14000
Explanation
Two possible fusion plans:


((20×30 × 30×10) × 10×40)


Cost:


20×30×10 = 6000
20×10×40 = 8000


Total = 14000


Other order:


(20×30 × (30×10 × 10×40))


12000 + 24000 = 36000


=======
Problem Statement
In the floating kingdom of Aetheria, dreams are not merely thoughts they are woven into giant Resonance Tapestries that power the cities suspended above the clouds.

Riya, the kingdom's youngest Dream Weaver, has been assigned the task of preparing a ceremonial tapestry for the Festival of Dawn. The tapestry is not woven all at once. Instead, it is created through a sequence of magical weaving frames.

Each frame transforms dream-energy from one resonance size into another. A frame that accepts energy of size a × b produces energy of size b × c. Since the output of one frame becomes the input of the next, the entire weaving process forms a valid chain.

Whenever two neighboring weaving results are fused together, magical effort is consumed. If one woven segment has dimensions x × y and the next has dimensions y × z, then the fusion requires:

x × y × z

units of dream-energy.

Different orders of fusion can lead to dramatically different energy costs.

The Royal Council has limited the total dream-energy available for the ceremony. Before the weaving begins, Riya must calculate the smallest possible amount of dream-energy required to complete the entire tapestry.

The chain of weaving frames is guaranteed to be valid.

Input Format
First line contains an integer N, the number of weaving frames.

Next line contains N+1 integers.

If the values are:

p0 p1 p2 ... pN

then the frames are:

p0×p1
p1×p2
...
p(N-1)×pN

Output Format
Print a single integer representing the minimum dream-energy required.

Constraints
2 ≤ N ≤ 200

1 ≤ pi ≤ 1000

Sample Testcase 0
Testcase Input
4
10 20 30 40 30
Testcase Output
30000
Explanation
Among all valid fusion plans, the minimum required dream-energy is 30000.

Sample Testcase 1
Testcase Input
3
20 30 10 40
Testcase Output
14000
Explanation
Two possible fusion plans:


((20×30 × 30×10) × 10×40)


Cost:


20×30×10 = 6000
20×10×40 = 8000


Total = 14000


Other order:


(20×30 × (30×10 × 10×40))


12000 + 24000 = 36000


>>>>>>> 66b411cc3254250609313542c6c09c2836bbdc49
Minimum energy = 14000.