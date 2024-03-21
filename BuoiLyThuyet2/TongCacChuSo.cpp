#include<iostream>
using namespace std;

long DeQuy(long long n)
{
	if(n<10)
	return n;
	return n%10+DeQuy(n/10);
}
long  Lap(long long n)
{
	long tongChuSo = 0;
	while(n>10)
	{
		tongChuSo+=n%10;
		n/=10;
	}
	return tongChuSo+n;
}
int main()
{
	cout<<DeQuy(999)<<endl;
	cout<<Lap(987);
	return 0;
}