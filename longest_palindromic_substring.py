def find_longest(s, longest_palindromes):
    pal = True;
    n = len(s)
    if (n % 2 == 0):
        j = n // 2;
        i = j - 1;
    else:
        j = n // 2 + 1;
        i = n // 2 - 1;
        tmp = s(n//2, n//2 + 1);
        if (longest_palindromes.find(tmp) == longest_palindromes.end())
            longest_palindromes.insert(pair<string, string>(tmp, tmp));
    # M A L A Y A L A M
    for (; i >= 0 && j < n && pal; i--, j++) {
        pal = s[i] == s[j];
        if (pal) {
            string tmp = s.substr(i, j+1);
            if (longest_palindromes.find(tmp) == longest_palindromes.end())
                longest_palindromes.insert(pair<string, string>(tmp, tmp));
    string tmp = s.substr(i+1, j);
    for (; i >= 0 && j < n; i--, j++) {
        string tmp2 = s.substr(i, j+1);
        if (longest_palindromes.find(tmp) == longest_palindromes.end())
            longest_palindromes.insert(pair<string, string>(tmp2, tmp));

def longestPalindrome(s):
    longest_palindromes = {}
    for i in range(len(s)):
        for j in range(len(s)-1, i, -1):
            find_longest(s[i:j-1+1], longest_palindromes)
    print(longest_palindromes)
    return longest_palindromes[s]

print(longestPalindrome("babad"))
print(longestPalindrome("cbbd"))
