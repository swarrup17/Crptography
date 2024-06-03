//ERROR some changes are requird for key//
#include <iostream>
#include <string>

using namespace std;

string encryptDecrypt(string text, string key) {
    string result = "";
    for (size_t i = 0; i < text.size(); ++i)
        result += text[i] ^ key[i % key.size()];
    return result;
}

int main() {
    string plaintext, key;

    // Get plaintext from user
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Get key from user
    cout << "Enter the key: ";
    getline(cin, key);

    // Check if the lengths of plaintext and key are equal
    if (plaintext.length() != key.length()) {
        cout << "Error: Length of plaintext and key must be equal." << endl;
        return 1;
    }

    // Encrypt the plaintext using the key
    string ciphertext = encryptDecrypt(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;

    // Decrypt the ciphertext using the key
    string decryptedText = encryptDecrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}

