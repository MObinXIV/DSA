#include<bits/stdc++.h>
// كل الحوار انى باخد القيمة الكبيرة بين 3 مش مضطر لاراى يا قفا 

using namespace std;
int a , b , c ;
int f (  int n , vector<int>&dp)
{
    if (n < 0 || (n > 0 && n < a && n < b && n < c)) // فى حالة ان الطول اكبر من زيرو بس اقل من كل الارقام معانا بفكس 
        return -1e9;
    else if(n==0)return 0 ;
    if(dp[n]!=-1) return dp[n];
    int z= f(n-a,dp);
    int x= f(n-b,dp);
    int y= f(n-c,dp);

    return dp[n]=1+max(max(z,y),x);
    
}

int main ()

{
    int n ;
    cin>>n>>a>>b>>c;
    //int N=1e4+5;
    vector<int>dp(n+1,-1);
    cout<<f(n,dp);
}