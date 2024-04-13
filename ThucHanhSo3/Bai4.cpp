#include<iostream>
using namespace std;

long mu(int a, int n)
{
	if(n<1)
	return 1;
	if(n==1)
	{
		return a;
	}
	else{
		if(n%2==0)
		return mu(a,n/2) * mu(a,n/2);
		else
		return mu(a,n/2) * mu(a,n/2) *a;
	}
}

int main()
{
	cout<<mu(3,3);
}