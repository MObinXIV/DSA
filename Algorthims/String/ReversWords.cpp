#include<bits/stdc++.h>

using namespace std;


string reverseWords(string s) {
       string res;
       int n = s.size();
       int i= 0;
       while (i<n)
       {
           while(i<n &&s[i]==' ') i++;//The first pointer we move till we place our pointer in the begining of the word
           int j=i+1;
           while(j<n && s[j]!=' ') j++;//till whe reach the end
           string sub=s.substr(i,j-i);
           if(res.size()==0) res=sub;
           else res= sub +" "+res;
           i=j+1;//move our pointer
       }
       return res;
    }