#include<iostream>
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
	a[i] = a[i]+1;
	i++;
	while(i<=k)
		{
		a[i] = a[i-1]+1;
		i++;
	}

}
void GenerateAlgo(int a[], int n, int k)
{
	Init(a,k);
	int i;
	do{
		Display(a,k);
		i=k;
		while(i>0&&a[i]==n-k+i)
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
	int n,k;
	cin>>n>>k;
	int *a = new int[n];
	GenerateAlgo(a,n,k);
	delete[] a;
	return 0;
}