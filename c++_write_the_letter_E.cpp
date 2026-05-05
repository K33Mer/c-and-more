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
    int delay = 0; // milliseconds

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
    void setDelay(int d){ delay = d; }

    //🔥 SIDE-BY-SIDE RENDERING
    void printWord(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        for (int row = 0; row < height; row++ ) {
            for (char letter : word) {
                if (alphabet.find(letter) != alphabet.end()) {
                    for (char pixel : alphabet[letter][row]) {
                        cout << (pixel == '*' ? brush : ' ');
                    }
                } else {
                    cout << string(width, ' ');
                }
                cout << string(spacing, ' ');    
            }
            cout << string(spacing, ' ');
            if (delay > 0)
                this_thread::sleep_for (chrono::milliseconds(delay));
        }
    }

    //🔥 TYPEWRITER ANIMATION
    void animateWord(string word) {
        transform(word.begin(), word.end(), word.begin(), :: toupper);

        for (char letter : word){
            printWord(string(1, letter));
            this_thread::sleep_for(chrono::milliseconds(300));
            cout << endl;
        }
    }

    //🔥 DESIGN YOUR OWN LETTER
    void designLetter(){
        char newChar;
        cout << "Enter character to design: ";
        cin >> newChar;
        newChar = toupper(newChar);

        vector<string> pattern(height);

        cout << "Design your letter (" << height << " rows, use *j and space):\n";
        cin.ignore();

        for (int i = 0; i < height; i++){
            getline(cin, pattern[i]);

            //pad or trim to width
            if(pattern[i].length()< width)
               pattern[i]+= string(width - pattern[i].length(), ' ');
            else if (pattern[i].length() > width)
               pattern[i] = pattern[i].substr(0, width);    
        }

        alphabet[newChar] = pattern;
        cout << "Letter '" << newChar << "' saved!\n";
    }

    void showMenu(){
        cout << "\n==== ASCII ENGINE MENU ====\n";
        cout << "1. Print word\n";
        cout << "2. Animate word\n";
        cout << "3. Change brush\n";
        cout << "4. Change spacing\n";
        cout << "5. Set animation speed\n";
        cout << "6. Design new letter\n";
        cout << "7. Quit\n";
        cout << "===========================\n";
    }
};

int main() {
    BlockLetterEngine engine;
    int choice;
    string input;

    cout << "🔥 ASCII ENGINE 3.0 🔥\n";

    while (true){
        engine.showMenu();
        cout << "Choice: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
        
        case 1:
            cout << "Enter word: ";  
            cin >> input;
            engine.printWord(input);
            break;
            
        case 2:
            cout << "Enter word: ";
            cin >> input;
            engine.animateWord(input);
            break;
            
        case 3: {
            char b;
            cout << "Enter brush character: ";
            cin >> b;
            engine.setBrush(b);
            break;
        }
        
        case 4: {
            int s;
            cout << "Enter spacing: ";
            cin >> s;
            engine.setSpacing(s);
            break; 
        }

        case 5: {
            int d;
            cout << "Enter delay (ms): ";
            cin >> d;
            engine.setDelay(d);
            break;
        }

        case 6:
            engine.designLetter();
            break;

        default:
            cout << "Invalid choice.\n";    
        }
        
        cout << "Goodbye. \n";
        return 0;
        
    }
}
