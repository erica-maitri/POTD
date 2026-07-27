#include <queue>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int N;
   cin >> N;

   string E;
   queue<int> e;
   for (int i = 0;i< N;i++){
    cin >> E;
     if(E=="ENTER"){
        long long x;
        cin >> x;
        e.push(x);
   }else{
    if(!e.empty())    // pop only if q is not empty , if already empty again loop
    e.pop();
   }
   }
   if(!e.empty()){
   cout << e.front();
   }else{
    cout << "EMPTY" << endl;
   }
    return 0;
}