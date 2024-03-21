#include<iostream>
using namespace std;
int *x;
int n;
void HienThiCauHinh()
{
	for(int i=0;i<n;i++)
		cout<<x[i];
	cout<<endl;
}

void QuayLui(int i)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n)
			HienThiCauHinh();
		else{
			QuayLui(i+1);
			}
	}
	
}

int main()
{
	cin>>n;
	x = new int[n];
	QuayLui(0);
}