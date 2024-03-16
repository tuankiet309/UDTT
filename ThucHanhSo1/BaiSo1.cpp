#include<iostream>
using namespace std;

void Init(int a[], int n)
{
	for(int i=1;i<=n;i++)
	{
		a[i] = 0;
	}
}

void Display(int a[], int n)
{
	for(int i = 1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}
void GenerateNext(int a[], int n, int i)
{
	a[i] = 1;
	i++;
	for(int j=i;j<=n;j++)
	{
		a[j] = 0;
	}
}
void GenerateAlgo(int a[], int n)
{
	int i;
	Init(a,n);
	do{
		Display(a,n);
		i = n;
		while(i>0&&a[i]==1)
		{
			i--;
		}
		if(i>0)
		{
			GenerateNext(a,n,i);
		}
	}
	while(i>0);
}

int main()
{
	int n;
	cin>>n;
	int *a = new int[n+1];
	GenerateAlgo(a,n);
	delete[] a;
	return 0;
}