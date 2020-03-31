#include <iostream>
using namespace std;

bool is_vowel(char c) {
    switch(tolower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

string pigLatinify(string str) {
    string suff = "ay";
    char first = str[0];
    string new_str = "";
    int i;
    bool isQ = false;
    if (str.find("qu") == 0) {
        i = 2;
        isQ = true;
    } else {
        i = 1;
    }
    new_str = str.substr(i, str.size()-i);
    if (isQ) {
        new_str += str.substr(0, i);
        new_str += suff;
    } else if (is_vowel(first)) {
        new_str += 'w';
        new_str += suff;
    } else {
        new_str += first;
        new_str += suff;
    }
    return new_str;

}

int main() {
   string str;
   cout << "Enter a word: \n";
   cin >> str;
   cout << "Pig Latin: " << pigLatinify(str) <<endl;
   return 0;
}