#include<iostream>

using namespace std;

void main()

{
    int *p=NULL;//intialize pointer to null
    
    p=new(nothrow) int; //Request for new memory for variable using new operatotr 

    if(!p) cout<<"allocation of memory failed \n";
    else
    {
        *p=29;
        cout<<"The value of p is " <<*p<<endl;
    }

    float *r=new float(5.5);
    cout<<"The value of r "<<*r<<endl;
     int n = 5;
    int *q = new(nothrow) int[n];
 
    if (!q)
        cout << "allocation of memory failed\n";
    else
    {
        for (int i = 0; i < n; i++)
            q[i] = i+1;
 
        cout << "Value store in block of memory: ";
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
 
    // freed the allocated memory
    delete p;
    delete r;
 
    // freed the block of allocated memory
    delete[] q;
}