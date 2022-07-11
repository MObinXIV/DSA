#include<bits/stdc++.h>

using namespace std;
void pypart(int n )
{
   /* for (int i = 0; i <n ;i++)
    {
        for (int j = 0  ; j<=i;j++)
        cout<<"*";
        cout<<endl;
    }*/

    int i = 0 , j =0;
    while(i<n)
    {
        while(j<=i)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
        j=0;
    }
}
//Reversed Pyrimid
void pypart2(int n )
{
   /* for (int i = n ; i>=0;i--)
    {
        for (int j  = 0 ; j<=n;j++)
        {
            if(j>=i) cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }*/
    int i =0  , j=0 , k=0;
    while(i<n)
    {
        //for spaces printing 
        while(k<n-i-1)
        {cout<<" ";k++;}
        k=0;
        //for stars 
        while(j<=i) 
        {
            cout<<"*";
            j++;
        }
        j=0;
        i++;
        cout<<endl;
    }
    

}
void InvertedPyr(int n )
{
    /*for (int i = n ; i>=0 ; i--)
    {
        for (int j = 0 ; j<i ; j++)cout<<"*";
        cout<<endl;
    }*/
    
    // Outer loop to handle number of rows
    // n in this case
    int i = n, j = 0;
    while (i > 0) {
 
        // Inner loop to handle number of columns
        // values changing acc. to outer loop
        while (j < i) {
 
            // Printing stars
            cout << "* ";
            j++;
        }
        j = 0; // we have to reset j value so as it can
               // start from beginning and print * equal to i.
        i--;
        // Ending line after each row
        cout << endl;
    }

}
void IvRotate(int n )
{
    for (int i = n ; i>=0;i--)
    {
        //spaces
        for (int j  = 0 ; j<n-i ;j++) cout<<" ";
        for (int j = 0 ; j<i;j++)cout<<"*";
        cout<<endl;
    }
}
void Triangle (int n )
{
    int k =2*n-2;//number of spaces 
    for (int i = 0 ; i<n;i++)
    {
        for (int j = 0 ; j<k;j++) cout<<" ";
        k--;
        // Inner loop to handle number of columns
        // values changing acc. to outer loop
        for (int j = 0; j <= i; j++) 
            // Printing stars
            cout << "* ";
            cout<<endl;
    }
}
int main()

{
    //pypart(5);
    //pypart2(5);
    //InvertedPyr(5);
    Triangle(5);
}