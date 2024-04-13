#include<iostream>
#include<vector>
using namespace std;

struct XeTai{
	string bs;
	float tt;
};

vector<XeTai> xts;

void Create()
{
	xts.push_back(XeTai{"B01",20.0});
	xts.push_back(XeTai{"B02",18.0});
	xts.push_back(XeTai{"B03",26.0});
	xts.push_back(XeTai{"B04",22.0});
	xts.push_back(XeTai{"B05",30.0});
	xts.push_back(XeTai{"B06",27.0});
	xts.push_back(XeTai{"B07",15.0});
}
XeTai max(int left, int right)
{
	if(left==right)
	return xts[left];
	else
	{
		int m = (left+right)/2;
		return max(left,m).tt>max(m+1,right).tt?max(left,m)	: max(m+1,right);
	}
}
int FindIndexToInsert(const vector<int>& arr, int num, int left, int right) {
    if (left >= right) {
        return left;
    }
    int middle = (left + right) / 2; 
	if(num>=arr[middle]&&num<=arr[middle+1])
	return middle+1;
    if (num < arr[middle]) {
        return FindIndexToInsert(arr, num, left, middle);
    } else {
        return FindIndexToInsert(arr, num, middle + 1, right);
    }
}
int main()
{
	vector<int> a={1,3,6,7,8,10};
	cout<<FindIndexToInsert(a,6,0,5);
	
	
}