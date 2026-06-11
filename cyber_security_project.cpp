#include <iostream>
#include <string>
#include <cctype>
#include <functional>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ==================================
// HASH TOOL
// ==================================

size_t generateHash(string text)
{
    hash<string> hasher;
    return hasher(text);
}

// ==================================
// CAESAR CIPHER
// ==================================

string encryptCaesar(string text, int shift)
{
    for (char& c : text)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';

            c = ((c - base + shift) % 26) + base;
        }
    }

    return text;
}

string decryptCaesar(string text, int shift)
{
    return encryptCaesar(text, 26 - shift);
}
// ==================================
// XOR ENCRYPTION
// ==================================

string xorEncrypt(string text, char key)
{
    for(char& c : text)
    {
        c ^= key;
    }
    
    return text;
}

// ==================================
// PASSWORD CHECKER
// ==================================

bool isStrongPassword(const string& password)
{
    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    for (char c : password)
    {
        if (isupper(c))
            upper = true;
        else if (islower(c))
            lower = true;
        else if (isdigit(c))
            digit = true;
        else
            special = true;
    }

    return password.length() >= 8
        && upper
        && lower
        && digit
        && special;
}
// ==================================
// RANDOM PASSWORD GENERATOR
// ==================================

string generatePassword(int length)
{
    string chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*";

    string password;
    
    for (int i = 0; i < length; i++)
    {
        password += chars[rand() % chars.length()];
    }

    return password;
}
// ==================================
// LOGGING
// ==================================

void saveLog(const string & entry)
{


ofstream file("security_log.txt", ios::app);
   
   if (file.is_open())
   {
       file << entry << endl;
       file.close();
   }
}

// ==================================
// FILE INTEGRITY CHECKER
// ==================================

size_t hashFile(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "File not found.\n";
        return 0;
    }

    stringstream buffer;
    buffer << file.rdbuf();

    return generateHash(buffer.str());
}

// ===================================
// LOGIN SYSTEM
// ===================================

bool login()
{
    string username;
    string password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    return username == "admin"
        && password == "Password123!";

}

// ==================================    
// MENU
// ==================================

void showMenu()
{
    cout << "\n====================================\n";
    cout << " Security+ Concepts Toolkit\n";
    cout << "====================================\n";
    cout << "1. Generate Hash\n";
    cout << "2. Caesar Cipher\n";
    cout << "3. Password Strength Checker\n";
    cout << "4. XOR Encryption\n";
    cout << "5. Generate Random Password\n";
    cout << "6. Save Log Entry\n";
    cout << "7. File Integrity Checker\n";
    cout << "8. User Login Simulation\n";
    cout << "9. Exit\n";
    cout << "====================================\n";
    cout << "Choice: ";
}

// ==================================
// MAIN
// ==================================

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string text;

                cin.ignore();

                cout << "\nEnter text to hash: ";
                getline(cin, text);

                cout << "\nHash:\n";
                cout << generateHash(text) << endl;

                break;
            }

            case 2:
            {
                string message;
                int shift;

                cin.ignore();

                cout << "\nEnter message: ";
                getline(cin, message);

                cout << "Shift amount: ";
                cin >> shift;

                string encrypted =
                    encryptCaesar(message, shift);

                cout << "\nEncrypted:\n";
                cout << encrypted << endl;

                cout << "\nDecrypted:\n";
                cout << decryptCaesar(encrypted, shift)
                     << endl;

                break;
            }

            case 3:
            {
                string password;

                cout << "\nEnter password: ";
                cin >> password;

                if (isStrongPassword(password))
                    cout << "\nPassword is STRONG\n";
                else
                    cout << "\nPassword is WEAK\n";

                break;
            }

            case 4:
            {
                string text;
                char key;

                cin.ignore();

                cout << "\nEnter text: ";
                getline(cin, text);

                cout << "Enter key character: ";
                cin >> key;

                string encrypted =
                    xorEncrypt(text, key);

                cout << "\nEncrypted:\n";
                cout << encrypted << endl;

                cout << "\nDecrypted:\n";
                cout << xorEncrypt(encrypted, key)
                     << endl;

                break;
            }

            case 5:
            {
                int length;

                cout << "\nPassword length: ";
                cin >> length;

                cout << "\nGenerated Password:\n";
                cout << generatePassword(length)
                     << endl;

                break;
            }

            case 6:
            {
                string entry;

                cin.ignore();

                cout << "\nEnter log message: ";
                getline(cin, entry);

                saveLog(entry);

                cout << "Log saved.\n";

                break;
            }

            case 7:
            {
                string filename;

                cout << "\nEnter filename: ";
                cin >> filename;

                cout << "\nFile Hash:\n";
                cout << hashFile(filename)
                     << endl;

                break;
            }

            case 8:
            {
                int attempts = 0;

                while (attempts < 3)
                {
                    if (login())
                    {
                        cout << "\nAccess Granted\n";
                        break;
                    }

                    attempts++;
                    cout << "\nAccess Denied\n";
                }

                if (attempts == 3)
                {
                    cout << "\nAccount Locked\n";
                }

                break;
            }

            case 9:
            {
                cout << "\nGoodbye!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid choice.\n";
            }
        }

    } while (choice != 9);

    return 0;
}
                

                
                


            
        
        