#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    long long  N;
    cin >> N;
    vector <long long> v(N);
    for(int i = 0;i<N;i++){
       
      cin >> v[i];
    }

    //or
    //vector <int> v;
    //for(int i = 0;i<N;i++){
     //int t;
        //cin >> t;
        //v.push_back(t);
        //}
    

    sort(v.begin(),v.end());

    for(int i = 1;i<N;i+=2){ //check in pair of 2
        if(v[i-1]!=v[i]){
            cout << v[i-1];
            return 0;
        }

        //for (int i = 0; i < N - 1; i += 2) {
       //if (v[i] != v[i + 1]) {
        //cout << v[i];
        //return 0;} 
         // }
          //cout << v[N - 1]
    }
    cout << v[N-1]; //if unique no was last no
    return 0;
}

//1 2 2 3 3  v[i-1] should be printed
//129 129 278 312 312 451 451  v[i] should be printed 
// how to decide which to print so 
//print in pair of 2

/*For example, if N = 5:

Initially:

v = [0, 0, 0, 0, 0]

After push_back(1), push_back(2), ...:

v = [0, 0, 0, 0, 0, 1, 2, 2, 3, 3]
tc=TC=O(NlogN)
sc=O(n)*/



/*#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        ans ^= x;
    }

    cout << ans;

    return 0;
}
//TC=O(N)​
//cs=o(1)*/

/*
Number read     Operation                    ans becomes
---------------------------------------------------------
312             0 ^ 312                     312
451             312 ^ 451                   312^451
129             (312^451) ^ 129             312^451^129
312             312^451^129^312             451^129  (because 312^312 = 0)
451             451^129^451                 129      (because 451^451 = 0)
278             129^278                     129^278
129             129^278^129                 278      (because 129^129 = 0)
*/