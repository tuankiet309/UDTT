#include <iostream>
#include <algorithm>
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {
    return N;
}
using namespace std;

void KhoiTao(int n, int index[])
{
	for(int i = 1;i<=n;i++)
	{
		index[i] = i;
	}
}

void HienThi(int n, int index[],string hsinh[])
{
	for(int i = 1;i<=n;i++)
	{
		cout<<"Ghe "<<i<<": "<<hsinh[index[i]-1]<<"; ";
	}
	cout<<endl;
}

void SinhConKeTiep(int i, int index[], int n) {
    int k = n;
    while (index[k] < index[i]) {
        k--;    
    }
    swap(index[i], index[k]);
    i++;
    int j = n;
    while (j > i) {
        swap(index[i], index[j]);
        i++;
        j--;
    }
}
void ThuatToanSinh(int n, int index[], string hsinh[]) {
    int i;
    do {
        HienThi(n, index, hsinh);
        i = n - 1;
        while (i > 0 && index[i] > index[i + 1]) {
            i--;
        }
        if (i > 0)
            SinhConKeTiep(i, index, n);
    } while (i > 0);
}

int main() {
    string hsinh[]{"Kiet","Tung","Vinh","Phu","Nhuan"};
    int n = arraySize(hsinh);
    int *index = new int[n+1];
    KhoiTao(n, index); // Initialize index array
    ThuatToanSinh(n, index, hsinh);
    delete[] index;
    return 0;
}