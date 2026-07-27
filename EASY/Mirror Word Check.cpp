#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    int r = n-1;
    while(l<r){   //not l==r
      if(s[l]!=s[r]){
       cout << "NO";
       return 0;
      }
      l++;
      r--;
    }
    cout << "YES";
    return 0;
}