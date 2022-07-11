int findMin(vector<int>& nums) {
        int low=0, hi=nums.size()-1;
    while(low<hi)
    {
        int mid=(low+hi)>>1;
        
        if(nums[hi]>nums[mid]) // for this reason I'm sure that my right is absoultelry bigger than me 
        {
            hi=mid;//low still as we saw as it might be my answer
        }
        else
        low=mid+1;//You are not sure if it's our answer or not 
    }
    //always end at low ==high
    return nums[low];
    }