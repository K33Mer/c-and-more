#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std;

class BlockLetterEngine {
private:
    int height = 5;
    int width = 5;
    char brush = '*';
    int spacing = 2;
    int delay = 0;

    string color = "\033[0m";

    map<char, vector<string>> alphabet;

    void initAlphabet() {
        alphabet = {
            {'A', {" *** ","*   *","*****","*   *","*   *"}},
            {'B', {"**** ","*   *","**** ","*   *","**** "}},
            {'C', {" ****","*    ","*    ","*    "," ****"}},
            {'D', {"**** ","*   *","*   *","*   *","**** "}},
            {'E', {"*****","*    ","*****","*    ","*****"}},
            {'F', {"*****","*    ","*****","*    ","*    "}},
            {'G', {" ****","*    ","*  **","*   *"," ****"}},
            {'H', {"*   *","*   *","*****","*   *","*   *"}},
            {'I', {"*****","  *  ","  *  ","  *  ","*****"}},
            {'J', {"*****","   * ","   * ","*  * "," **  "}},
            {'K', {"*   *","*  * ","***  ","*  * ","*   *"}},
            {'L', {"*    ","*    ","*    ","*    ","*****"}},
            {'M', {"*   *","** **","* * *","*   *","*   *"}},
            {'N', {"*   *","**  *","* * *","*  **","*   *"}},
            {'O', {" *** ","*   *","*   *","*   *"," *** "}},
            {'P', {"**** ","*   *","**** ","*    ","*    "}},
            {'Q', {" *** ","*   *","*   *","*  **"," ****"}},
            {'R', {"**** ","*   *","**** ","*  * ","*   *"}},
            {'S', {" ****","*    "," *** ","    *","**** "}},
            {'T', {"*****","  *  ","  *  ","  *  ","  *  "}},
            {'U', {"*   *","*   *","*   *","*   *"," *** "}},
            {'V', {"*   *","*   *","*   *"," * * ","  *  "}},
            {'W', {"*   *","*   *","* * *","** **","*   *"}},
            {'X', {"*   *"," * * ","  *  "," * * ","*   *"}},
            {'Y', {"*   *"," * * ","  *  ","  *  ","  *  "}},
            {'Z', {"*****","   * ","  *  "," *   ","*****"}}
        };
    }

public:
    BlockLetterEngine() {
        initAlphabet();
    }

    void setBrush(char b) {
        brush = b;
    }

    void setSpacing(int s) {
        spacing = s;
    }

    void setDelay(int d) {
        delay = d;
    }

    // 🎨 COLOR
    void setColor(int code) {
        color = "\033[" + to_string(code) + "m";
    }

    // 🔥 PRINT WORD
    void printWord(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        for (int row = 0; row < height; row++) {

            for (char letter : word) {

                auto it = alphabet.find(letter);

                if (it != alphabet.end()) {

                    for (char pixel : it->second[row]) {

                        if (pixel == '*')
                            cout << color << brush << "\033[0m";
                        else
                            cout << " ";
                    }

                } else {
                    cout << string(width, ' ');
                }

                cout << string(spacing, ' ');
            }

            cout << endl;

            if (delay > 0)
                this_thread::sleep_for(chrono::milliseconds(delay));
        }
    }

    // 🔁 SCROLL TEXT
    void scrollText(string word, int window = 40) {

        transform(word.begin(), word.end(), word.begin(), ::toupper);

        string padding(window, ' ');
        string full = padding + word + padding;

        for (int i = 0; i < full.length(); i++) {

            system("cls"); // Windows

            printWord(full.substr(i, window));

            this_thread::sleep_for(chrono::milliseconds(120));
        }
    }

    // 💾 SAVE FONT
    void saveFont(string filename) {

        ofstream file(filename);

        for (auto& p : alphabet) {

            file << p.first << endl;

            for (string row : p.second)
                file << row << endl;
        }

        file.close();

        cout << "Saved to " << filename << endl;
    }

    // 💾 LOAD FONT
    void loadFont(string filename) {

        ifstream file(filename);

        alphabet.clear();

        char key;

        while (file >> key) {

            vector<string> pattern(height);

            file.ignore();

            for (int i = 0; i < height; i++)
                getline(file, pattern[i]);

            alphabet[key] = pattern;
        }

        file.close();

        cout << "Loaded from " << filename << endl;
    }

    // 🛠 DESIGN LETTER
    void designLetter() {

        char c;

        cout << "Enter letter: ";
        cin >> c;

        c = toupper(c);

        vector<string> pattern(height);

        cin.ignore();

        for (int i = 0; i < height; i++)
            getline(cin, pattern[i]);

        alphabet[c] = pattern;

        cout << "Saved!\n";
    }

    void showMenu() {

        cout << "\n==== ASCII ENGINE 5.1 ====\n";
        cout << "1. Print word\n";
        cout << "2. Scroll text\n";
        cout << "3. Change brush\n";
        cout << "4. Change color\n";
        cout << "5. Save font\n";
        cout << "6. Load font\n";
        cout << "7. Design letter\n";
        cout << "8. Quit\n";
        cout << "=============================\n";
    }
};

int main() {

    BlockLetterEngine engine;

    int choice;
    string input;

    while (true) {

        engine.showMenu();

        cout << "Choice: ";
        cin >> choice;

        if (choice == 8)
            break;

        switch (choice) {

        case 1:
            cin >> input;
            engine.printWord(input);
            break;

        case 2:
            cin >> input;
            engine.scrollText(input);
            break;

        case 3: {
            char b;
            cin >> b;
            engine.setBrush(b);
            break;
        }

        case 4: {
            int c;

            cout << "Enter ANSI color (31=red, 32=green, 34=blue): ";

            cin >> c;

            engine.setColor(c);

            break;
        }

        case 5:
            engine.saveFont("font.txt");
            break;

        case 6:
            engine.loadFont("font.txt");
            break;

        case 7:
            engine.designLetter();
            break;

        default:
            cout << "Invalid\n";
        }
    }

    cout << "Goodbye\n";

    return 0;
}