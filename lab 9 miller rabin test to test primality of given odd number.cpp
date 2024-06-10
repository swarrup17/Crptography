#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Modular exponentiation function (x^y) % p
long long int power(long long int x, long long int y, long long int p) {
    long long int res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Miller-Rabin primality test function
bool millerRabinTest(long long int n, int k) {
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    long long int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Repeat k times
    for (int i = 0; i < k; i++) {
        // Pick a random number in [2..n-2] 
        // Above corner cases make sure that n > 4
        long long int a = 2 + rand() % (n - 4);

        // Compute a^d % n
        long long int x = power(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        // Repeat Rabin test with d divided by 2 until d becomes odd
        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
                return false;
            if (x == n - 1)
                break;
        }

        // Composite
        if (x != n - 1)
            return false;
    }

    // Probably prime
    return true;
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    long long int n;
    cout << "Enter an odd number to test for primality: ";
    cin >> n;

    int k = 5; // Number of iterations
    if (millerRabinTest(n, k))
        cout << n << " is probably prime." << endl;
    else
        cout << n << " is composite." << endl;

    return 0;
}

