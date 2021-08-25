/*
* The program will recieve 3 English words inputs from STDIN
* 
* These three words will be read one at a time, in three separate line
* The first word should be changed like all vowels should be replaced by *
* The second word should be changed like all consonants should be replaced by @
* The third word should be changed like all char should be converted to upper case
* Then concatenate the three words and print them
* Other than these concatenated word, no other characters/string 
* should or message should be written to STDOUT
* 
* For example if you print "how are you" then output should be "h*wa@eYOU".
* 
* You can assume that input of each word will not exceed more than 5 chars
*/
#include <bits/stdc++.h>
using namespace std;

vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int main() {
    string s1, s2, s3;
    string result = "";
    cin >> s1 >> s2 >> s3;
    for (int i = 0; i < s1.size(); i++) {
        char c = s1[i];
        for (int j = 0; j < vowels.size(); j++) {
            if (s1[i] == vowels[j]) {
                c = '*';
                break;
            }
        }
        result += c;
    }
    for (int i = 0; i < s2.size(); i++) {
        bool consonant = true;
        for (int j = 0; j < vowels.size() && consonant; j++) {
            if (s2[i] == vowels[j])
                consonant = false;
        }
        if (consonant)
            result += "@";
        else
            result += s2[i];
    }
    for (int i = 0; i < s3.size(); i++) {
        if (s3[i] >= 97) {
            int diff = s3[i] - 'a';
            result += char('A' + diff);
        }
        else
            result += s3[i];
    }
    cout << result << endl;
}
