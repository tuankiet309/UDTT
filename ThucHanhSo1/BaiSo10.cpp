#include<iostream>
using namespace std;

long SumOfOdds(long arr[],int n)
{
	if(n==0)
	return 0;
	if(arr[n]%2!=0)
	return arr[n] + SumOfOdds(arr,n-1);
	else
	return SumOfOdds(arr,n-1);
}

int main()
{
	int n;
	cin>>n;
	long arr[n+1];
	for(int i =1;i<=n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Tong cac so le trong day la: "<<SumOfOdds(arr,n);
}