def longest_palindrome(s: str) -> str:
    longest = ''
    curr = [s[0]]
    for i in range(1, len(s)):
        print (curr, longes)
        if (s[i] == s[i-1]):
            curr.append(s[i])
        else:
            if (len(curr) > len(longest)):
                longest = curr.copy()
            curr = [s[i]]
    if (len(curr) > len(longest)):
        longest = curr.copy()
    return longest

print (longest_palindrome('babad'))
