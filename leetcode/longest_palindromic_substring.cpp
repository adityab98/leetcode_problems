#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s) {
	bool pal = true;
	int n = s.length();
	for (int i = 0; i < n/2 && pal; i++) {
		pal = s[i] == s[n-i-1];
	}
	return pal;
}

string longestPalindrome(string s) {
	string longest = s.substr(0, 1);
	for (int i = 0; i < s.length(); i++) {
		for (int j = s.length() - 1; j > i; j--) {
			string tmp = s.substr(i, j-i+1);
			if (is_palindrome(tmp) && tmp.length() > longest.length())
				longest = tmp;
		}
	}
	return longest;
}

int main() {
	cout << longestPalindrome("babad") << endl;
	cout << longestPalindrome("cbbd") << endl;
	return 0;
}
