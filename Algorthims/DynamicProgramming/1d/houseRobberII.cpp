/*The only deference is that we can't contain 1st and last in same array
so we do house robberI for 2 arrays which no one contain the other and take the maximum

*/
int rob1(vector<int>& nums) {
    int n = nums.size();
   
   int prev=nums[0];
   int prev2=0;
   for (int i = 1 ; i<n;i++)
   {
       int take=nums[i];
       if(i>1)take+=prev2;
       int notTake= prev;
       int curi=max(take,notTake);
       prev2=prev;
       prev=curi;
   }
    return prev;
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> last, First;

        for (int i= 0 ; i<n ; i++)
        {
            if (i!=n-1) First.push_back(nums[i]);//generate all the elements except the last one 
            if(i!=0) last.push_back(nums[i]);//generate all the elements except the first one
        }
        return max(rob1(First),rob1(last));
        
    }