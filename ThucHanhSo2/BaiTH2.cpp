#include<iostream>

using namespace std;

int GCD(int a,int b)
{
	while(a%b!=0)
	{
		int c = a;
		a = b;
		b = c%a;
	}
	return b;
}

int main()
{
	cout<<GCD(12,9);
}