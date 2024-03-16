#include<iostream>
using namespace std;

int SumOfNumbers(long n)
{
	if(n<10)
	return n;
	return n%10+SumOfNumbers(n/10);
}

int main()
{
	long n;
	cin>>n;
	cout<<"Tong cac chu so: "<<SumOfNumbers(n);
	return 0;
}