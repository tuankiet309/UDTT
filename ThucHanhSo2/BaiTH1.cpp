#include<iostream>
using namespace std;

int GCD(int a,int b)
{
	if(a%b==0)
	return b;
	else
	return GCD(b,a%b);
}

int main()
{
	cout<<GCD(12,8);
}