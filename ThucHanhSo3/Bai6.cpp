#include<iostream>
using namespace std;

//int a[15]{3,5,1,4,2,6,8,7,9,122,22,14,15,12,19};
//int a[5]{3,5,7,9,11};
bool isEven(int a)
{
	return a%2==0;
}
int findSmallestEven(int left, int right) {
    if (left == right) {
        if (isEven(a[left])) {
            return a[left];
        } else {
            return INT_MAX; 
        }
    }

    int mid = left + (right - left) / 2;
    int leftResult = findSmallestEven(left, mid);
    int rightResult = findSmallestEven( mid + 1, right);

    return leftResult>rightResult?rightResult:leftResult;
}

int main()
{
	int temp = findSmallestEven(0,4);
	if(temp==INT_MAX)
	{
		cout<<"Khong ton tai so chan";
	}
	else
	cout<<temp;
}