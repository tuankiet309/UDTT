#include<iostream>
using namespace std;

long long Fibonacci(int n,long long*memo)
{
	if(n<3)
	return 1;
	if(memo[n]!=-1)
	return memo[n];
	return memo[n]=Fibonacci(n-1,memo) + Fibonacci(n-2,memo);
}
int main()
{
	long n;
	cin>>n;
	long long *memo = new long long[n+1];
	for(long i = 1;i<=n;i++)
	{
		memo[i] = -1;
	}
	cout<<"So fibonacci thu "<<n<<" la: "<<Fibonacci(n,memo);
	delete[] memo;
	return 0;
}