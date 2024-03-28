#include<iostream>
using namespace std;

long Fibo(int n)
{
	if(n<3)
	return 1;
	else
	return Fibo(n-2)+Fibo(n-1);
}

int main()
{
	cout<<Fibo(6);
}