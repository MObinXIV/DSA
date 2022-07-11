#include<bits/stdc++.h>
using namespace std;
//We take the Xor between 2 numbers and take the carry by anding 
int getSum(int a, int b) {
        while(b)
        {
            int t=(a&b)<<1;
            a=a^b;
            b=t;
        }
        return a;
    } 