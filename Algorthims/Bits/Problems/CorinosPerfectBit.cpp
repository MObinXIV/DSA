#include<bits/stdC++.h>

using namespace std;
int lowbit(int x)//Get the least significnt bit 
{
	return x&(-x);
}
int main(){
    int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int w=lowbit(x);//Get lsb of the number 
		while(!(w^x) || !(w&x))w++;//increase till satisfy the condition ( 101 &001=001 ->  001 &101=001 & 001^101=100)
		cout<<w<<endl;
	}
	return 0;
}