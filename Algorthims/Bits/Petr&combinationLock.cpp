//Petr and a Combination Lock

/*
we Generate all The subsets and set the 0 subset with (-) and 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
   
    vector<int>arr(n);
    for (int i=0;i<n;i++)
    cin>>arr[i];

    bool flag=0;
    int sum;
    for (int num =0;num<(1<<n);num++)
    {
        sum=0;
        for (int bit= 0;bit<n;bit++)
        {
            if (num &(1<<bit))//if The bit is set we add it 
            sum+=arr[bit];
            else 
            sum-=arr[bit];//if not we subtract it 
        }
        if (sum%360==0)//This means we reach 0 
        {
            flag=1;
            break;
        }
    }
    if (flag)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}