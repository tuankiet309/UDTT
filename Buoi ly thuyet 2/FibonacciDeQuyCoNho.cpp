/*
	Name: 
	Copyright: 
	Author: 
	Date: 15/03/24 19:17
	Description: 
*/

#include <iostream>
using namespace std;

long long memo[100]; // Mảng để lưu các giá trị Fibonacci đã tính trước đó

// Hàm đệ quy tính số Fibonacci thứ n với việc lưu nhớ kết quả
long long Fibonacci(int n) {
    if (n <= 1) return n;

    // Nếu đã tính trước đó, trả về kết quả đã tính
    if (memo[n] != -1) return memo[n];

    // Nếu chưa tính, tính và lưu vào mảng memo trước khi trả về
    return memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Nhap vao so n: ";
    cin >> n;

    // Khởi tạo mảng memo với -1 (chưa tính) cho các giá trị
    for (int i = 0; i <= n; ++i) {
        memo[i] = -1;
    }

    // Hiển thị dãy n số Fibonacci và tính tổng của dãy
    long long sum = 0;
    cout << "Day " << n << " so fibonacci la: ";
    for (int i = 0; i < n; ++i) {
        long long fib = Fibonacci(i);
        sum += fib;
        cout << fib << " ";
    }
    cout << endl;

    cout << "Tong cua day fibonacci la: " << sum << endl;

    return 0;
}