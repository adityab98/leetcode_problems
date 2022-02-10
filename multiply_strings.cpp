#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
    string rev_num1 = "", rev_num2 = "", res = "";
	for (int i = num1.length() - 1; i >= 0; i--)
		rev_num1 = rev_num1 + num1[i];
	for (int i = num2.length() - 1; i >= 0; i--)
		rev_num2 = rev_num2 + num2[i];
	//cout << rev_num1 << " " << rev_num2 << endl;
	char oflow = 0;
	for (int i = 0; i < rev_num1.length(); i++) {
		for (int j = 0; j < rev_num2.length(); j++) {
			if (i >= rev_num1.length()) {
				reverse(res.begin(), res.end());
				return num2.substr(0, num2.length() - i - 1) + res;
			}
			else if (i >= rev_num2.length()) {
				reverse(res.begin(), res.end());
				return num1.substr(0, num1.length() - i - 1) + res;
			}
			char prod = ((rev_num1[i] - '0') * (rev_num2[i] - '0')) + oflow;
			char c_right = prod % 10;
			char oflow = prod / 10;
			cout << +c_right << " " << +oflow << endl;
			res += (c_right + '0');
		}
	}
	return res;
}

int main() {
	cout << multiply("123", "456") << endl;
}
