#include <iostream>
#include <string>
using namespace std;
string rail_fence_encrypt(const string& plaintext, int rail_size) {
    string ciphertext;
    int n = plaintext.length();
    int gap = 2 * (rail_size - 1);
    
    for (int i = 0; i < rail_size; ++i) {
        int j = i;
        while (j < n) {
            ciphertext.push_back(plaintext[j]);
            if (i != 0 && i != rail_size - 1 && j + gap - 2 * i < n)
                ciphertext.push_back(plaintext[j + gap - 2 * i]);
            j += gap;
        }
    }
    return ciphertext;
}
string rail_fence_decrypt(const string& ciphertext, int rail_size) {
    string plaintext(ciphertext.length(), ' ');
    int n = ciphertext.length();
    int gap = 2 * (rail_size - 1);
    int p = 0;

    for (int i = 0; i < rail_size; ++i) {
        int j = i;
        while (j < n) {
            plaintext[j] = ciphertext[p++];
            if (i != 0 && i != rail_size - 1 && j + gap - 2 * i < n)
                plaintext[j + gap - 2 * i] = ciphertext[p++];
            j += gap;
        }
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    int rail_size;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the rail size: ";
    cin >> rail_size;

    ciphertext = rail_fence_encrypt(plaintext, rail_size);
    cout << "Encrypted Text: " << ciphertext << endl;

    string decryptedText = rail_fence_decrypt(ciphertext, rail_size);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

