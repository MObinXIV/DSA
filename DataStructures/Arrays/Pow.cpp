#include<bits/stdc++.h>

using namespace std;
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}
//Recursion approach
double myPow(double x, int n) {
         if (n==0)
        return 1;
    else if (n>0)
        return x* pow (x,n-1);
    else
        return 1 / x* pow(x,n+1);
   
    }
    double myPow(double x, int n) {
        double ans =1.0;
        //we store n in another value to handle negative case;
        long temp=n;
        if(temp<0)temp=-1.0*n;
        while(temp>0)
        {
            if(temp%2)
            {
                ans*=x;
                temp--;
            }
            else
            {
                x*=x;
                temp/=2;
            }
    }
    if(n<0) ans=double(1.0)/double(ans);
    return ans; 
    }
int main()
{
    cout << myPow(2, 10) << endl;
}