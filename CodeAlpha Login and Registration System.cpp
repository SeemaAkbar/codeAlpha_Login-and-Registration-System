#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    string savedUser, savedPassword;

    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter username: ";
    cin >> username;

    // Check duplicate username
    ifstream readFile("users.txt");

    while (readFile >> savedUser >> savedPassword) {
        if (savedUser == username) {
            cout << "Username already exists!\n";
            readFile.close();
            return;
        }
    }

    readFile.close();

    cout << "Enter password: ";
    cin >> password;

    // Save user details
    ofstream file("users.txt", ios::app);

    if (!file) {
        cout << "File error!\n";
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    string savedUser, savedPassword;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> savedUser >> savedPassword) {

        if (savedUser == username &&
            savedPassword == password) {

            cout << "\nLogin successful!\n";
            cout << "Welcome, " << username << "!\n";

            file.close();
            return;
        }
    }

    file.close();

    cout << "Invalid username or password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
