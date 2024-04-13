#include<iostream>
using namespace std;

float a[20]{3,5,1,4,2,6,8,7,9,122,22,14,15,12,19,28,45,111,43,77};

float tong(int l, int r)
{
	if(l==r)
	return a[l];
	if(l==r-1)
	{
		return a[l] + a[r];
	}
	else{
		int m = (l+r)/2;
		return tong(l,m) + tong(m+1,r);
	}
}
int main()
{
	cout<<tong(0,19);
	float tongg = 0;
	for(int i=0;i<20;i++)
	{
		tongg+=a[i];
	}
	cout<<endl<<tongg;
}