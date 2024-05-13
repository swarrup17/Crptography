#include <iostream>
#include <vector>
using namespace std;

int mod(int a, int m) {
    return (a % m + m) % m;
}

void getCofactor(const vector<vector<int> &a, vector<vector<int> &temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = a[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(const vector<vector<int>> &a, int n) {
    if (n == 1)
        return a[0][0];
    int det = 0;
    vector<vector<int>> temp(n, vector<int>(n));
    int sign = 1;
    for (int f = 0; f < n; f++) {
        getCofactor(a, temp, 0, f, n);
        det += sign * a[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

void adjoint(const vector<vector<int>> &a, vector<vector<int>> &adj) {
    int n = a.size();
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(a, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}

bool inverse(const vector<vector<int>> &a, vector<vector<int>> &inv) {
    int n = a.size();
    int det = determinant(a, n);
    if (det == 0) {
        cout << "Inverse does not exist";
        return false;
    }
    vector<vector<int>> adj(n, vector<int>(n));
    adjoint(a, adj);
    int invDet = mod(det, 26);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = mod(adj[i][j] * invDet, 26);
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the size of key matrix: ";
    cin >> n;
    cout << "Enter the key matrix: \n";
    vector<vector<int>> keyMatrix(n, vector<int>(n));
    vector<vector<int>> inverseMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> keyMatrix[i][j];
        }
    }
    if (!inverse(keyMatrix, inverseMatrix)) {
        return 1;
    }

    string message;
    cout << "Enter the message to encrypt/decrypt: ";
    cin >> message;

    int temp = (n - message.size() % n) % n;
    for (int i = 0; i < temp; i++) {
        message += 'x';
    }

    string result = "";
    int k = 0;
    while (k < message.size()) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int temp = k;
            for (int j = 0; j < n; j++) {
                sum += (inverseMatrix[i][j] * (message[temp++] - 'a')) % 26;
                sum = mod(sum, 26);
            }
            result += (sum + 'a');
        }
        k += n;
    }

    cout << "Result: " << result << '\n';
    return 0;
}

