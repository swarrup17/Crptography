#include <iostream>
#include <string>
using namespace std;

string vigenere_encrypt(const string& plaintext, const string& key) {
    string ciphertext;
    int keyLen = key.length();
    for (int i = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLen];
        char encryptedChar = 'A' + ((plainChar - 'A' + keyChar - 'A') % 26);
        ciphertext.push_back(encryptedChar);
    }
    return ciphertext;
}

string vigenere_decrypt(const string& ciphertext, const string& key) {
    string plaintext;
    int keyLen = key.length();
    for (int i = 0; i < ciphertext.length(); ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLen];
        char decryptedChar = 'A' + ((cipherChar - keyChar + 26) % 26);
        plaintext.push_back(decryptedChar);
    }
    return plaintext;
}

int main() {
    string plaintext, key;
    
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;

    string encryptedText = vigenere_encrypt(plaintext, key);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = vigenere_decrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

