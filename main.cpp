#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

string text;
int option, shift;
void menu(), encodingProcess(), encode(), decode();

int main() {
    menu();

    return 0;
}

string encode(string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        text[i] += shift;
    }
    return text;
}

string decode(string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        text[i] -= shift;
    }
    return text;
}

void menu() {
    system("cls");

    cout << "welcome to HashR menu!" << endl;
    cout << endl << "1. Encode" << endl << "2. Decode" << endl;
    cout << endl << "Your choise: ";
    cin >> option;

    switch (option) {
    case 1:
        encode();
        break;
    case 2:
        decode();
        break;
    default:
        cout << "Wrong option. Please, try again.";
        menu();
    }
}

void encodingProcess() {
    // Replace spacebar signs because C++ doesn't support space bars in encoding
    replace(text.begin(), text.end(), ' ', '_');

    cout << endl << "Encoded succesfully. Your output: '" << encode(text, shift) << "`";
    system("pause >nul");

    menu();
}

void encode() {
    system("cls");
    cout << "Encoding..." << endl;
    cout << endl << "Enter pass: ";
    cin.ignore();
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;

    encodingProcess();
}

void decode() {
    system("cls");
    cout << "Decoding..." << endl;
    cout << endl << "Enter pass: ";
    cin.ignore();
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;

    cout << endl << "Decoded succesfully. Your output: '" << decode(text, shift) << "`";
    system("pause >nul");
    cout << endl << endl;;
    
    menu();
}

