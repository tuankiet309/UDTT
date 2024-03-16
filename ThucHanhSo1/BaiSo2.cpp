#include<iostream>
using namespace std;

void Init(char a[], int n)
{
	for(int i=1;i<=n;i++)
	{
		a[i] = 'a';
	}
}

void Display(char a[], int n)
{
	for(int i = 1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}
void GenerateNext(char a[], int n, int i)
{
	a[i] = 'b';
	i++;
	for(int j=i;j<=n;j++)
	{
		a[j] = 'a';
	}
}
void GenerateAlgo(char a[], int n)
{
	int i;
	Init(a,n);
	do{
		Display(a,n);
		i = n;
		while(i>0&&a[i]=='b')
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
	char *a = new char[n+1];
	GenerateAlgo(a,n);
	delete[] a;
	return 0;
}