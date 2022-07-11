#include<bits/stdc++.h>

using namespace std;
vector<int> repeatedNumber( vector<int> &array) {
    int n = array.size() + 1;

    vector<int> substitute(n, 0); // initializing the substitute array with 0 of size n+1.

    vector<int> ans;              // initializing the answer  array .

    for (int i = 0; i < array.size(); i++)
    {
        substitute[array[i]]++;
    }

    for (int i = 1; i <= array.size(); i++)
    {
        if (substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

vector<int> repeatedNumber( vector<int> &A) {
    int n = A.size();
   long long s= (n*(n+1))/2;
   long long p=(n * (n +1) *(2*n +1) )/6;
   long long miss=0 , repeat =0;
   for (int i =0 ; i<A.size();i++)
   {
       s-=(long long ) A[i];
       p -= (long long int)A[i]*(long long int)A[i];
   }
   miss = (s+p/s)/2;
   repeat=miss-s;
   vector <int> ans;

    ans.push_back(repeat);
    ans.push_back(miss);

    return ans;

   
}


//Xor approach

vector < int >repeatedNumber (const vector < int >&arr)
{
    int xor1=arr[0];
    int x=0 , y=0;
    int n = arr.size();
    /* Get the xor of all array elements */
    for (int i =1; i< n ; i++)
    xor1^=arr[i];
    
    //we xor to get x^y
    for (int i =1; i<=n;i++)
    xor1^=i;

    //Get the right most bit of number
    int st=xor1 & ~(xor1-1);
    //No we divie it to 2 baskets according to the matching of right most bit 

    for (int i=0 ; i<n;i++)
    {
    
        if(arr[i]&st)
        x^=arr[i];
        else
        y^=arr[i];
    }

    for (int i=1 ; i<=n;i++)
    {
        if(i & st) x^=i;
        else
        y^=i;

    }
   // to get the repeating and missing as we konw them
   int cx=0;
   for (int i = 0 ; i< n ; i++)
   {
       //if x is repeating 
       if(arr[i]==x )cx++;
   }
   if(cx==0) return{y,x};
   return {x,y};

}


//missing number only

int getMissingNo(int a[], int n)
{
    int n_elements_sum = n * (n + 1) / 2;//Sum of all 
    int sum = 0;
 
    for (int i = 0; i < n - 1; i++)
        sum += a[i];//Sum of remaining 
    return n_elements_sum - sum;
}
 