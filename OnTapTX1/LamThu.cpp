#include<iostream>
#include<vector>
using namespace std;
//Ham khai bao cau truc
struct ChuyenBay{
	string soHieu;
	float giaVe;
	int soGhe;
};
//Ham ho tro hien thi
void HienThi(ChuyenBay a)
{
	cout<<a.soHieu<<" "<<a.giaVe<<" "<<a.soGhe;
	cout<<endl;
}
//Cau a
void HienThiDeQuy(vector<ChuyenBay>chuyenBay,int n)
{
	if(n<0)
	return;
	if(chuyenBay[n].giaVe<3000)
	HienThi(chuyenBay[n]);
	return HienThiDeQuy(chuyenBay,n-1);
}
//Cau b
ChuyenBay ChuyenBayMinCDT(vector<ChuyenBay>chuyenBay,int l,int r)
{
	if(l=r-1)
	{
		if(chuyenBay[l].soGhe>chuyenBay[r].soGhe)
		return chuyenBay[r];
		else return chuyenBay[l];
	}
	else if(l<r)
	{
		int m = (l-r)/2;
		if(ChuyenBayMinCDT(chuyenBay,l,m).soGhe > ChuyenBayMinCDT(chuyenBay,m+1,r).soGhe)
		return ChuyenBayMinCDT(chuyenBay,m+1,r);
		else return ChuyenBayMinCDT(chuyenBay,l,m);
	}
}

//Cau c
void HienThiDanhSach(vector<CHuyenBay>chuyenBay, int k)
{
	for(int i=0;i<=k;i++)
	{
		cout<<chuyenBay[i].soHieu<<" ";
	}
	cout<<endl;
}

void Try(int k)
{
	
}
int main()
{
	vector<ChuyenBay> chuyenBay;
	ChuyenBay a = {"VN01",1000,30};
	ChuyenBay b = {"VN02",3000,27};
	ChuyenBay c = {"VN03",2000,38};
	ChuyenBay d = {"VN04",2500,40};
	ChuyenBay e = {"VN05",800,26};
	ChuyenBay f = {"VN06",3500,22};
	chuyenBay.push_back(a);
	chuyenBay.push_back(b);
	chuyenBay.push_back(c);
	chuyenBay.push_back(d);
	chuyenBay.push_back(e);
	chuyenBay.push_back(f);
	HienThi(ChuyenBayMinCDT(chuyenBay,0,5));
	return 0;
}