#include<bits/stdc++.h>

using namespace std;
//Greedy approach, We only check for the wiggle sequence (the number are ordered like -> 3,7,4 (رقم اكبر و اللى بعده اصغر و هكذا))
int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int cnt=1;
        int sign = 0 ;//We start with no knowledge of sign
        for(int i  =  1 ; i< nums.size();i++)
        {
            if(nums[i] - nums[i-1]<0 && sign !=-1)//check if the difference is negative and the previous sign is positive or it's a begining
            {
                sign=-1;//update the sign
                cnt++;
            }
            else if (nums[i] - nums[i-1]>0 && sign !=1)//check if the difference is positive and the previous sign is neg or it's a begining
            {
                sign=1;
                cnt++;
            }
        }
        return cnt;
    }

    //Dp approach 
    // ببساطة بعمل 2 اراى واحد للى طالع و واحد للى نازل  و بعدين اعمل ابدايت و اخد و الكبير 
    // تحويل دى لريكرشن سهل مش مستاهل ههه
    
     int wiggleMaxLength(int nums[]) {
        if (nums.length() < 2)
            return nums.length();
        int up []= new int[nums.length()];
        int down []= new int[nums.length()];
        up[0] = down[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }
        return Math.max(down[nums.length - 1], up[nums.length - 1]);
    }