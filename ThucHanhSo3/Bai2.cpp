#include<iostream>
using namespace std;

float a[15]{3,5,1,4,2,6,8,7,9,11,22,14,15,12,19};
void mergeSort(int l,int r)
{
	float b[15]{0};
	if(r>l)
	{
		int m = (r+l)/2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		for(int i = m;i>=l;i--)
		{
			b[i] = a[i];
		}
		for(int j=m+1;j<=r;j++)
		{
			b[r+m+1-j] = a[j];
		}
		int i=l;
		int j =r;
		for(int k=l;k<=r;k++)
		{
			if(b[i]<b[j])
			{
				a[k]=b[i];i++;
			}
			else
			{
				a[k]=b[j];j--;
			}
		}
	}
}
int main()
{
	mergeSort(0,14);
	for(int i=0;i<15;i++)
	{
		cout<<a[i]<<" ";
	}
}