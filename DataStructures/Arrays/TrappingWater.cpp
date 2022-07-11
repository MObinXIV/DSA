#include<bits/stdc++.h>

using namespace std;
//by observation the amount of water that can be stored in particular index is the min(max(left),max(right))-height[i]
int trap(vector<int>& height) {
        int n = height.size();
        int wrappedWater=0;
        for (int i = 0 ; i<n ;i++)
        {
         int temp=i;
         int lm = 0 , rm = 0;
         while(temp>=0)
         {
            lm=max(lm,height[temp]);
            temp--;
         }
         temp=i;
         while(temp<n)
         {
            rm=max(rm,height[temp]);
            temp++;
         }
         wrappedWater+=min(rm,lm)-height[i];
        }
        return wrappedWater;


    }

    //Suffix & prefix sum approach

    int trap(vector<int>& height) {
      int n = height.size();
      int prefix[n] , suffix[n];
      prefix[0]=height[0];
      for(int i = 1 ; i<n ; i++)//Get the max left for each index 
      {
         prefix[i]=max(prefix[i-1],height[i]);
      }
      suffix[n-1]=height[n-1];
      for(int i = n-2; i >=0;i--)//Get the max right for each index
      {
         suffix[i]=max(suffix[i+1],height[i]);
      }
      int wrappedWater=0;
      for(int i = 0 ; i<n;i++)
      wrappedWater+=min(prefix[i],suffix[i])-height[i];

      return wrappedWater;


    }

    //2 Pointers approach
    // The idea with simplicity I always make sure which is the min ( max(l),max(r)),
    
    int trap(vector<int>& height) {
      int n = height.size();
      int l = 0 , r= n-1;
      int maxL=0, maxR=0;
      int res=0;
      while(l<=r)
      {
         if(height[l]<=height[r])//This mean my current max height is in the left potion
         {
            if(height[l]>=maxL) maxL=height[l];//I'll only update my max left as the ther's no trapping water 
            else
            res+=maxL-height[l];//Get the difference as in my basic formula
            l++;
         }
         else // This mean my min height is in the right potion
         {
            if(height[r]>=maxR)maxR=height[r];
            else 
            res+=maxR-height[r];
            r--;
         }
      }
      return res;
    }

    