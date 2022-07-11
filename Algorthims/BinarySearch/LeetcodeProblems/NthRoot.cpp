#include<bits/stdc++.h>

using namespace std;
double multiply(double num , double n )
{
    double ans =1.0;
    for (int i = 1 ; i<=n ; i++)
    {
        ans*=num;
    }
    return ans;
}
double getNthRoot(int n  ,int m )
{
    double low =1;
    double high=m;
    double eps=1e-6;
    while((high-low)>eps)
    {
        double mid = (high+low)/2.0;
        if(multiply(mid,n)<m)
        {
            low=mid;
        }
        else
        high=mid;
    }
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
}
int main()

{
    int n=3, m=27; 
	getNthRoot(n, m);
}