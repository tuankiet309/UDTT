#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct hs{
	string ten;
	string hodem;
	int nam;
	string diachi;
};

vector<hs> dshs {
	{"Kiet","Tuan",2003,"Ha Noi"},
	{"Cuong","Hoang",2004,"Ha Dong"},
	{"Viet","Long",2002,"Quang Ninh"},
	{"Vinh","Thanh",2005,"Ho Tay"},
	{"Duc","Anh",2003,"Thanh Xuan"},
	{"V","Ha",1997,"TPHCM"},
				};
void merge(int l, int r)
{
	vector<hs> temp(6);
	if(r>l)
	{
		int m =(l+r)/2;
		merge(l,m);
		merge(m+1,r);
		for(int i = m; i >=l; i--)
		{
			temp[i] = dshs[i];
		}
		for(int j=m+1;j<=r;j++)
		{
			temp[r+m+1-j] = dshs[j];
		}
		int i=l,j=r;
		for(int k=l;k<=r;k++)
		{
			if(temp[i].ten.compare(temp[j].ten)<0)
			{
				dshs[k]=temp[i];
				i++;
			}
			else{
				dshs[k]=temp[j];
				j--;
			}
		}
	}
}
int CDT(int l, int r,string s)
{
	int m = (l+r)/2;
	if(l==r && dshs[m].ten.compare(s)!=0)
	{
		return -1;
	}
	if(dshs[m].ten.compare(s)==0)
	{
		return m;
	}
	else if(dshs[m].ten.compare(s)<0)
	{
		return CDT(m+1,r,s);
	}
	else
	{
		return CDT(l,m,s);
	}
	
}
int main()
{
	merge(0,5);
	for(int i=0;i<dshs.size();i++)
	{
		cout<<dshs[i].ten<<endl;
	}
	string s;
	cin>>s;
	cout<<CDT(0,5,s);
	
}