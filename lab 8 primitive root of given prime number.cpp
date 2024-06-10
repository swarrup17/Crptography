#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate power under mod
int power(int x, int y, int p) {
    int res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function to find gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find primitive root of prime number p
int primitiveRoot(int p) {
    vector<int> factors;

    int phi = p - 1;
    int n = phi;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);

    for (int res = 2; res <= p; res++) {
        bool flag = true;
        for (int i = 0; i < factors.size() && flag; i++) {
            if (power(res, phi / factors[i], p) == 1)
                flag = false;
        }
        if (flag)
            return res;
    }
    return -1;
}

int main() {
    int p;
    cout << "Enter a prime number: ";
    cin >> p;

    int primitiveRootNum = primitiveRoot(p);
    if (primitiveRootNum != -1)
        cout << "Primitive root of " << p << " is " << primitiveRootNum << endl;
    else
        cout << "Primitive root doesn't exist for " << p << endl;

    return 0;
}

