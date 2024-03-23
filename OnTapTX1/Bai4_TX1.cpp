#include<iostream>
#include<vector>
using namespace std;
struct Chuyenbay{
	string soHieu;
	int giaVe;
	int soGhe;
};

int *x;
vector<Chuyenbay> cb;

void Create()
{
	cb.push_back(Chuyenbay{"VN01",100,25});
	cb.push_back(Chuyenbay{"VN02",300,35});
	cb.push_back(Chuyenbay{"VN03",400,15});
	cb.push_back(Chuyenbay{"VN04",220,22});
	cb.push_back(Chuyenbay{"VN05",240,27});
	cb.push_back(Chuyenbay{"VN06",150,17});
}

void HienThi(Chuyenbay a)
{
	cout<<a.soHieu<<" "<<a.giaVe<<" "<<a.soGhe<<endl;
}
void HienThiGiaVe( int n)
{
	if(n<0)
	return;
	if(cb.at(n).giaVe>250)	
	HienThi(cb.at(n));
	return HienThiGiaVe(n-1);
}

Chuyenbay ChiaDeTri(int l, int r)
{
	if(l==r-1)
		return cb[l].giaVe>cb[r].giaVe ? cb[r] : cb[l];
	else if(l==r)
		return cb[l];
	else if(l<r)
	{
		int m = (l+r)/2;	
		
		return ChiaDeTri(l,m).giaVe > ChiaDeTri(m+1,r).giaVe ? ChiaDeTri(m+1,r) : ChiaDeTri(l,m);
	}
}

void HienThiMa(int k)
{
	for(int i = 0;i<k;i++)
	cout<<cb[x[i]-1].soHieu<<" ";
	cout<<endl;
}

void QuayLui(int n, int k, int i, int index)
{
	if(k==0)
	{
		HienThiMa(index);
		return;
	}
	for(int j = i;j<=n;j++)
	{
		x[index - k] =j;
		QuayLui(n,k-1,j+1,index);
	}
	
}
int main()	
{
	Create();	
	HienThiGiaVe(cb.size()-1);
	cout<<"Min: ";
	x = new int[3];
	HienThi(ChiaDeTri(0,cb.size()-1));
	QuayLui(cb.size(),3,1,3);
}