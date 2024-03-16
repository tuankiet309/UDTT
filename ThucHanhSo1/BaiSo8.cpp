#include<iostream>
using namespace std;
int maxi, maxj;
int o[maxi][maxj];
bool flag[maxi][maxj];
void loang(int i, int j)
{
	flag[i][j] == true;
	if(j>0)
	if((o[i][j-1]==o[i][j])&&!flag[i][j-1])
	loang(i,j-1);
	
	if(i>0)
	if((o[i-1][j]==o[i][j])&&!flag[i-1][j])
	loang(i-1,j);
	
	if(j<maxj)
	if((o[i][j+1]==o[i][j])&&!flag[i][j+1])
	loang(i,j+1);
	
	if(i<maxi)
	if((o[i+1][j]==o[i][j])&&!flag[i+1][j])
	loang(i+1,j);
}
void count()
{
	for(int i=0;i<maxi;i++)
	for(int j=0;i<maxj;j++)
		
 } 