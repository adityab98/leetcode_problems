"""
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
"""
def len_longest_substr(s: str) -> int:
    longest = 0
    repeated_chars = {}
    curr_len = 0
    substr_start = 0
    for i in range(len(s)):
        if (s[i] in repeated_chars):
            if (curr_len > longest):
                longest = curr_len
            old_i_of_si = repeated_chars[s[i]]
            substr_start = repeated_chars[s[i]] + 1
            curr_len = i - substr_start
            repeated_chars = {key:val for key, val in repeated_chars.items()
                                if val > old_i_of_si}
        repeated_chars[s[i]] = i
        curr_len += 1
    if (curr_len > longest):
        longest = curr_len
    return longest

"""O(n) solution"""
def lengthOfLongestSubstring(s: str) -> int:
    n = len(s)
    d = {} 
    res = 0
    start = 0
    for i in range(n):
        if s[i] in d and start <= d[s[i]]:
            start = d[s[i]] + 1 
        else:
            res = max(res, i-start+1)
        d[s[i]] = i
        
    return res

print(len_longest_substr("abba"))
