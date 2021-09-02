/*
 * One programming language has the following keywords that cannot be 
 * used as identifiers:
 * break, case, continue, default, defer, else, for, 
 * func, goto, if, map, range, return, struct, type, var
 * Write a program to find if the given word is a keyword or not
 */
#include <bits/stdc++.h>
using namespace std;

vector<string> reserved = {"break", "case", "continue", "default", "defer",
        "else", "for", "func", "goto", "if", "map", "range", 
        "return", "struct", "type", "var"};

int main() {
    string word;
    cin >> word;
    bool reservation = false;
    for (int i = 0; i < reserved.size() && !reservation; i++)
            reservation = reserved[i] == word;
    if (reservation)
        cout << word << " is a keyword" << endl;
    else
        cout << word << " is not a keyword" << endl;
}
