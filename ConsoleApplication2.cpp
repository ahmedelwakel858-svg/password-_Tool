#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generatePassword(int length) {
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    string password = "";
    for (int i = 0; i < length; i++) {
        password += chars[rand() % chars.length()];
    }
    return password;
}

string checkStrength(string pass) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;
    for (char c : pass) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSymbol = true;
    }
    int score = hasUpper + hasLower + hasDigit + hasSymbol;
    if (pass.length() >= 12 && score == 4) return "Strong";
    if (pass.length() >= 8 && score >= 3) return "Medium";
    return "Weak";
}

int main() {
    srand(time(0));
    int choice;
    cout << "1) Generate password\n2) Check password strength\nChoose: ";
    cin >> choice;

    if (choice == 1) {
        int length;
        cout << "Length: ";
        cin >> length;
        cout << "Your password: " << generatePassword(length) << endl;
    }
    else if (choice == 2) {
        string pass;
        cout << "Enter password: ";
        cin >> pass;
        cout << "Strength: " << checkStrength(pass) << endl;
    }
    return 0;
}