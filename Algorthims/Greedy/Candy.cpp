#include<bits/stdc++.h>

using namespace std;
int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>ans(n,1);//1st step we fill the whole array with ones 
        int sum =0 ; 

        //Update from left to ritght 
        for(int i = 0 ; i< n-1; i++)
        {
            if(ratings[i+1]>ratings[i])
            ans[i+1]=1+ans[i];
            
        }
        //Update backward
        for(int i = n -2 ; i>=0;i--)
        {
            if(ratings[i]>ratings[i+1] && ans [i]<=ans[i+1])
            {
                ans[i]=ans[i+1]+1;

            }
            sum+=ans[i];
        }
        //get the last one 
        sum+=ans[n-1];
        return sum ;
    }

    //2nd approach we use 2 arrays fro the purpose of l->r traversal & r->l traversal then take the maximum between them
    // نفس الابرواتش اللى فات بس هعمل اتنين لوب و ف الاخر لوب و هاخد الماكس 
    /*public class Solution {
    public int candy(int[] ratings) {
        int sum = 0;
        int[] left2right = new int[ratings.length];
        int[] right2left = new int[ratings.length];
        Arrays.fill(left2right, 1);
        Arrays.fill(right2left, 1);
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }
        for (int i = 0; i < ratings.length; i++) {
            sum += Math.max(left2right[i], right2left[i]);
        }
        return sum;
    }
}*/
// ارراى واحد زى مسألة النابساك
/*public class Solution {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies[ratings.length - 1];
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
}*/

// The last we will take it later from FreecodeCamp video

