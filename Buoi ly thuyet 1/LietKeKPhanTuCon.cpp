#include<iostream>
using namespace std;

void KhoiTao(int index[],int n)
{
	for(int i =1;i<=n;i++)
	{
		index[i] = i;
	}
}
void HienThi(int index[],string hsinh[],int k)
{
	for(int i = 1;i<=k;i++)
	{
		cout<<"Ghe "<<i<<": "<<hsinh[index[i]-1]<<"; ";
	}
	cout<<endl;
	
}
void SinhConKeTiep(int index[], int i, int k)
{
	index[i]++;
	i++;
	while(i<=k)
	{
		index[i] = index[i-1]+1;
		i++;
	}
}
void ThuatToanSinh(int n, int k,int index[],string hsinh[])
{
	int i;
	KhoiTao(index, k);
	do{
		i = k;
		HienThi(index,hsinh,k);
		while(i>0&&index[i]>n-k+i)
		i--;
		if(i>0)
		SinhConKeTiep(index, i ,k);
	}
	while(i>0);
}
int main()
{
	string a[]{"Khoi","Tung","Vinh","Tuy","Tien","Long"};
	int k;
	cin>>k;
	int *index = new int[k+1];
	ThuatToanSinh(6,k,index,a);
	delete[] index;
	return 0;
}