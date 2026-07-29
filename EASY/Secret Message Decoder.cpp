#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
     
    string s ;
    cin >> s;
    char c;
    cin >> c;
    int count=0;
    int n = s.size();

    for(int i=0;i<n;i++){
      if(s[i]==c){
        count++;
      }
    }

    cout << count;



    return 0;
}
/*
Time Complexity (TC): O(n)
Space Complexity: O(1)
*/