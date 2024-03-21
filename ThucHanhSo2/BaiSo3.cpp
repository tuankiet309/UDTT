#include <iostream>
using namespace std;

int *x;

void HienThiCauHinh(int k) {
    cout << "{ ";
    for (int i = 0; i < k; ++i) {
        cout << x[i] << " ";
    }
    cout << "}\n";
}

void QuayLui(int n, int k, int i, int index) {
    if (k == 0) {
        HienThiCauHinh(index);
        return;
    }

    for (int j = i; j <= n; ++j) {
        x[index - k] = j; //
        QuayLui(n, k - 1, j + 1, index);
    }
}
////Vi du cho cac ban de hieu hon//////

/*
	Ta co k=3,n=4,i=1, index =3
	Dau tien k!=0 nen bo qua ham in
	Tien vao vong lap:
	j=i=1;
	x[3-3]=1
	===> Quay lui tiep: (i=2,k=2)
			j=i=2;
			x[3-2]=j=2
			===>Quay lui tiep: (i=3,k=1)
					j=i=3
					x[3-1]=j=3;
					===>Quay lui tiep: (i=4, k=0)
							Vi k == 0 nen in ra cau hinh x[0]=1,x[1]=2,x[2]=3 roi quay lai;					
					<===
					Vong lap(dong 20) tiep tuc chay j++ ta co j=4, k =1
					x[3-1] = j =4;
					===>Quay lui tiep: (i=4,k=0)
							Vi k == 0 ne in ra cau hinh x[0]=1, x[1] =2, x[2] =4 roi quay lai;
					<===
					Vi j=4 tuc la da dat gioi han vong lap vong lap ket thuc va ham de quy nay cung ket thuc nen quay lai
			<===
			Tiep tuc vong lap ta co j = i =2 chua dat dieu kien cua vong lap, vong lap tiep tuc chay ta co 
			j=3,k=2;
			x[3-2] = j =3
			===>Quay lui tiep (i=4,k=1)
					j=i=4
					x[3-1]=j=4
					===>Quay lui tiep: (i=5,k=0)
							Vi k== 0 nen in ra cau hinh x[0] =1, x[1]=3, x[2] =4 roi quay lai
					<===
					Vi j = 4, dat dieu kien dung cua vong lap, ta ket thuc vong lap va cung ket thuc ham de quy nay tai day
			<===
			Tiep tuc vong lap ta co j = i =3 chua dat dieu kien cua vong lap, vong lap tiep tuc chay ta co
			j = 4, k =2;
			x[3-2] = 4
			===> Quay lui tiep (i=4,k=2)
					j = i =4  da dat gioi han cua vong lap nen ta quay lai
			<===
			Tiep tuc vong lap ta co j = i = 4 da dat dieu kien dung cua vong lap, ta quay lai
	<===
	Ta co 
	j = i =2;
	x[3-3] = 2
	......Doan sau cac ban tu hieu :3......
						
									
						 
		

*/
int main() {
    int n, k;
    
    cout << "Nhap vao n va k: ";
    cin >> n >> k;
	x = new int[k];
    QuayLui(n, k, 1,k);
    delete[] x; // nếu sử dụng con trỏ động nhớ giải phóng bộ nhớ
    return 0;
}