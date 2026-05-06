#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

class BlockLetterEngine {
private:
    int height = 5;
    int width = 5;
    char brush = '*';
    int spacing = 2;
    int delay = 0;

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

    void setBrush(char b) { brush = b; }
    void setSpacing(int s) { spacing = s; }
    void setDelay(int d) { delay = d; }

    // NORMAL
    void printWord(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        for (int row = 0; row < height; row++) {
            for (char letter : word) {
                auto it = alphabet.find(letter);

                if (it != alphabet.end()) {
                    for (char pixel : it->second[row]) {
                        cout << (pixel == '*' ? brush : ' ');
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

    // BACKWARD
    void printWordBackward(string word) {
        reverse(word.begin(), word.end());
        printWord(word);
    }

    // VERTICAL
    void printWordVertical(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        for (char letter : word) {
            auto it = alphabet.find(letter);

            if (it != alphabet.end()) {
                for (const string& row : it->second) {
                    for (char pixel : row) {
                        cout << (pixel == '*' ? brush : ' ');
                    }
                    cout << endl;
                }
            } else {
                cout << "[Unsupported: " << letter << "]\n";
            }

            cout << endl;
        }
    }

    // DIAGONAL
    void printWordDiagonal(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        int offset = 0;

        for (char letter : word) {
            auto it = alphabet.find(letter);

            if (it != alphabet.end()) {
                for (const string& row : it->second) {
                    cout << string(offset, ' ');

                    for (char pixel : row) {
                        cout << (pixel == '*' ? brush : ' ');
                    }

                    cout << endl;
                }
            }

            offset += width + spacing;
        }
    }

    // ANIMATION
    void animateWord(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        for (char letter : word) {
            printWord(string(1, letter));
            this_thread::sleep_for(chrono::milliseconds(300));
            cout << endl;
        }
    }

    // DESIGN LETTER
    void designLetter() {
        char newChar;
        cout << "Enter character: ";
        cin >> newChar;
        newChar = toupper(newChar);

        vector<string> pattern(height);
        cin.ignore();

        for (int i = 0; i < height; i++) {
            getline(cin, pattern[i]);

            if (pattern[i].length() < width)
                pattern[i] += string(width - pattern[i].length(), ' ');
            else if (pattern[i].length() > width)
                pattern[i] = pattern[i].substr(0, width);
        }

        alphabet[newChar] = pattern;
        cout << "Saved!\n";
    }

    void showMenu() {
        cout << "\n==== ASCII ENGINE 4.0 ====\n";
        cout << "1. Print word\n";
        cout << "2. Animate word\n";
        cout << "3. Backward\n";
        cout << "4. Vertical\n";
        cout << "5. Diagonal\n";
        cout << "6. Change brush\n";
        cout << "7. Change spacing\n";
        cout << "8. Set delay\n";
        cout << "9. Design letter\n";
        cout << "10. Quit\n";
        cout << "===========================\n";
    }
};

int main() {
    BlockLetterEngine engine;
    int choice;
    string input;

    cout << "🔥 ASCII ENGINE 4.0 🔥\n";

    while (true) {
        engine.showMenu();
        cout << "Choice: ";
        cin >> choice;

        if (choice == 10) break;

        switch (choice) {

        case 1:
            cin >> input;
            engine.printWord(input);
            break;

        case 2:
            cin >> input;
            engine.animateWord(input);
            break;

        case 3:
            cin >> input;
            engine.printWordBackward(input);
            break;

        case 4:
            cin >> input;
            engine.printWordVertical(input);
            break;

        case 5:
            cin >> input;
            engine.printWordDiagonal(input);
            break;

        case 6: {
            char b;
            cin >> b;
            engine.setBrush(b);
            break;
        }

        case 7: {
            int s;
            cin >> s;
            engine.setSpacing(s);
            break;
        }

        case 8: {
            int d;
            cin >> d;
            engine.setDelay(d);
            break;
        }

        case 9:
            engine.designLetter();
            break;

        default:
            cout << "Invalid choice\n";
        }
    }

    cout << "Goodbye.\n";
    return 0;
}