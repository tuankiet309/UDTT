#include <iostream>
using namespace std;

void KhoiTao(char a[],int n){
	for(int i = 1;i<=n;i++)
	{
		a[i] = 'a';
	}
}
void SinhConKeTiep(int i,int n, char a[])
{
	a[i] = 'b';
	i++;
	while(i<=n)
	{
		a[i] = 'a';
		i++;
	}
}
void InRaCauHinhHienTai(char a[], int n)
{
	for(int i = 1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}
void ThuatToanSinh(int n, char a[])
{
	KhoiTao(a,n);
	int i;
	do{
		i = n;
		InRaCauHinhHienTai(a,n);
		while(i>0 && a[i]=='b')
		{
			i--;
		}
		if(i>0)
		{
			SinhConKeTiep(i,n,a);
		}
	}
	while(i>0);
	
}
int main()
{
	int n;
	cin>>n;
	char *a = new char[n+1];
	ThuatToanSinh(n,a);
	delete[] a;
	return 0;
}