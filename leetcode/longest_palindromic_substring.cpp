#include <bits/stdc++.h>
using namespace std;

void find_longest(string s, map<string, string> &longest_palindromes) {
	// B A B A D
	int n = s.length(), i, j;
	if (n % 2 == 0) {
		j = n / 2;
		i = j - 1;
	}
	else {
		j = n / 2 + 1;
		i = n / 2 - 1;
		string tmp = s.substr(n / 2, 1);
		if (longest_palindromes.find(tmp) == longest_palindromes.end())
			longest_palindromes.insert(pair<string, string>(tmp, tmp));
	}
	for (bool pal = true; i >= 0 && j < n && pal; i--, j++) {
		pal = s[i] == s[j];
		if (pal) {
			string tmp = s.substr(i, j-i+1);
			if (longest_palindromes.find(tmp) == longest_palindromes.end())
				longest_palindromes.insert(pair<string, string>(tmp, tmp));
		}
	}
	string tmp = s.substr(i+1, j-i);
	for (; i >= 0 && j < n; i--, j++) {
		string tmp2 = s.substr(i, j-i+1);
		if (longest_palindromes.find(tmp) == longest_palindromes.end())
			longest_palindromes.insert(pair<string, string>(tmp2, tmp));
	}
}

string longestPalindrome(string s) {
	map<string, string> longest_palindromes;
	for (int i = 0; i < s.length(); i++) {
		for (int j = s.length() - 1; j >= i; j--) {
			string tmp = s.substr(i, j-i+1);
			if (longest_palindromes.find(tmp) == longest_palindromes.end())
				find_longest(tmp, longest_palindromes);
		}
	}
	map<string, string>::iterator i;
	for (i = longest_palindromes.begin(); i != longest_palindromes.end(); i++)
		cout << i->first << "\t" << i->second << endl;
	return longest_palindromes[s];
}

int main() {
	string str1 = "babad", str2 = "cbbd";
	cout << longestPalindrome(str1) << endl;
	//cout << longestPalindrome(str2) << endl;
	//cout << str1.substr(1, 3) << endl;
	return 0;
}
