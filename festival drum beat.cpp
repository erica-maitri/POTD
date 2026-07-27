#include <iostream>
using namespace std;

long long gcd(long a, long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long A, B;
    cin >> A >> B;

    long long lcm = (A * B) / gcd(A, B); //100000 × 100000 = 10,000,000,000

    cout << lcm;

    return 0;
}