#include<iostream>
#include<algorithm>
using namespace std;

void Init(int a[],int k)
{
	for(int i=1;i<=k;i++)
	a[i] = i;
}

void Display(int a[], int k)
{
	for(int i = 1;i<=k;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}

void GenrateNext(int a[],int k,int i)
{
	int j= k;
	while(a[j]<a[i])
	{
		j--;
	}
	swap(a[i],a[j]);
	i++;
	while(k>i)
	{
		swap(a[i],a[k]);
		i++;
		k--;	
	}	
}
void GenerateAlgo(int a[], int k)
{
	Init(a,k);
	int i;
	do{
		Display(a,k);
		i=k-1;
		while(i>0&&a[i]>a[i+1])
		{
			i--;
		}
		
		if(i>0)
		{
			GenrateNext(a,k,i);
		}
	}
	while(i>0);
}

int main()
{
	int k;
	cin>>k;
	int *a = new int[k+1];
	GenerateAlgo(a,k);
	delete[] a;
	return 0;
}