#include<iostream>
using namespace std;


long double LuyThua(double a, int n)
{
	if(n==1)
	return a;
	else if(n%2==1)
	return a*LuyThua(a,n/2)*LuyThua(a,n/2);
	return LuyThua(a,n/2)*LuyThua(a,n/2);
}

int main()
{
	cout<<LuyThua(2,5);
}