#include<iostream>
using namespace std;
void encrypt(char message[], int key) {
    for(int i = 0; message[i] != '\0'; ++i){
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}
void decrypt(char message[], int key) {
    for(int i = 0; message[i] != '\0'; ++i){
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}
int main()
{
    char message[100], ch;
    int key;
    cout << "Enter a message to encrypt: ";
    cin.getline(message, 100);
    cout << "Enter key: ";
    cin >> key;
    encrypt(message, key);
    cout << "Encrypted message: " << message << endl;
    cout << "Enter a message to decrypt: ";
    cin.ignore(); // Clear input buffer
    cin.getline(message, 100);
    cout << "Enter key: ";
    cin >> key;
    decrypt(message, key);
    cout << "Decrypted message: " << message << endl;
    return 0;
}
