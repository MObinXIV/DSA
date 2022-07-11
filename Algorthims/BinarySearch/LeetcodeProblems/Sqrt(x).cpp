int mySqrt(int x) {
        if (x == 0 || x == 1)
        return x;
      long long   low=1,high=x;
        long long   mid;
        long long  ans;
         
        while(low<=high)
        {
            mid= long (low+high)/2;
            
            if(mid *mid==x) return mid;
            if(mid *mid<x){ low=mid+1;
            //The tricky point in the problem 
            ans=mid;//keep floor value(in case our guy has a float value we return it's floor (it will never reach mid*mid))
            }
            else
            high = mid-1;
        }
        return ans;
    }
    int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
    return x;
 
    // Starting from 1, try all numbers until
    // i*i is greater than or equal to x.
    int i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}