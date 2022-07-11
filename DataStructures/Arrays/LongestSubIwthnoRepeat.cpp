#include<bits/stdc++.h>

using namespace std ;
/*I have 2 pointers & I move the right as long as I have no repeating one
case I found my current item already is in the map it has 2 cases it's repeated in in this case we jump our left by it's position+ 1 , else it's in the old substring
So we only update our left value with the new left and update the index of the item always to keep our consequitve right potion
*/
 int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int n =s.size();
        int len=0;
        int l=0, r = 0 ; 
        while (r<n)
        {
            if(mp[s[r]]!=-1)//in case I already push it 
            l=max(mp[s[r]]+1,l);// I check if I already path it 
            mp[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }