#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    long long N;
     cin >> N;

    stack<long long> st;
     for(int i = 0;i<N;i++){
        
        string op;
        cin >> op;
        
        /*long long x;
        cin >> x; */  // not here as remove have no number after that  

        if(op=="ADD"){
            long long x;
        cin >> x;
          st.push(x);
        }else{
            if(!st.empty()){
                st.pop();
            }
        }
     } 

     if (st.empty()){
        cout << -1;
     }else{
        cout << st.top();
     }
    return 0;
}