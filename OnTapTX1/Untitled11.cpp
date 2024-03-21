#include<iostream>
using namespace std;

long long power(long long a, long long n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 1) // n là s? l?
        return a * power(a, n - 1);
    else { // n là s? ch?n
        long long half_power = power(a, n / 2);
        return half_power * half_power;
    }
}
int main()
{
	cout<<power(3,4);
}