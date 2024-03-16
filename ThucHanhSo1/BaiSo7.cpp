#include<iostream>
#include<algorithm>
using namespace std;

void Init(int a[],int k)
{
	for(int i=1;i<=k;i++)
	a[i] = i;
}

void Display(int a[], int k,string hsinh[])
{
	for(int i = 1;i<=k;i++)
	{
		cout<<"Ghe "<<i<<": "<<hsinh[a[i]-1]<<", ";
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
void GenerateAlgo(int a[], int k,string hsinh[])
{
	Init(a,k);
	int i;
	do{
		Display(a,k,hsinh);
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

	string hsinh[]{"Tung","Vinh","Quang","Minh","Dai","Loi"};
	int *a = new int[6+1];
	GenerateAlgo(a,6,hsinh);
	delete[] a;
	return 0;
}