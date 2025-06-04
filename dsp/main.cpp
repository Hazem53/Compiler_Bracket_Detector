#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an opening bracket
bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Function to check if a character is a closing bracket
bool isClosingBracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

// Function to match opening and closing brackets
bool areBracketsMatching(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to find errors in brackets and their line numbers
void findBracketErrors(const string& input) {
    stack<pair<char, int> > bracketsStack; // Stack to keep track of opening brackets and their line numbers

    int lineNumber = 1; // Current line number

    for (char ch : input) {
        if (ch == '\n') {
            lineNumber++; // Increment line number when encountering a newline character
        } else if (isOpeningBracket(ch)) {
            bracketsStack.push({ch, lineNumber});
        } else if (isClosingBracket(ch)) {
            if (bracketsStack.empty() || !areBracketsMatching(bracketsStack.top().first, ch)) {
                cout << "Error: Unexpected closing bracket '" << ch << "' at line " << lineNumber << endl;
                return;
            }
            bracketsStack.pop(); // Remove matching opening bracket from the stack
        }
    }

    // Check for unmatched opening brackets
    while (!bracketsStack.empty()) {
        cout << "Error: Unmatched opening bracket '" << bracketsStack.top().first << "' at line " << bracketsStack.top().second << endl;
        bracketsStack.pop();
    }

    cout << "No bracket errors found." << endl;
}

int main() {
    string input;
    cout << "Enter the text to check for bracket errors (press Enter then Ctrl+D to finish):\n";

    // Read input from the user until EOF (Ctrl+D)
    char ch;
    while (cin.get(ch)) {
        input += ch;
    }

    findBracketErrors(input);

    return 0;
}
