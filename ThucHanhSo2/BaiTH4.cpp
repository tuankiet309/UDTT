#include<iostream>

using namespace std;

long Fibo(int n) {
    if (n <= 2)
        return 1;
    
    long a = 1, b = 1;
    for (int i = 3; i <= n; i++) {
        long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main(){
	cout<<Fibo(3);
}