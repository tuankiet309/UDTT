#include<iostream>
using namespace std;

int *x;
int *dd;
int n;

void HienThiCauHinh()
{
	for(int i=1;i<=n;i++)
		cout<<x[i];
	cout<<endl;
}

void QuayLui(int i)
{
	for(int j=1;j<=n;j++)
	{		
		if(dd[j]==0)
		{
			dd[j]=1;
			x[i] =j;
			if(i==n)
				{
					HienThiCauHinh();
					
				}
			else
				{
				QuayLui(i+1);	
				}
			dd[j]=0;
		}
	}
}

int main()
{
	cin>>n;
	x = new int[n+1];
	dd = new int[n+1];	
	for(int i = 1;i<=n;i++)
	{
		dd[i] =0;
	}
	QuayLui(1);
	delete[] dd;
	delete[] x;
	return 0;
}