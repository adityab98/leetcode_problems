"""
Abhi and Ramu want to play 'The Word Game'. Game Rules Both players are given the same string. Both players have to make substrings using the letters of the string. Abhi has to make words starting with consonants. Ramu has to make words starting with vowels. The game ends when both players have made all possible substrings. Scoring A player gets +1 point for each occurrence of the substring in the string. Your task is to determine the winner of the game and their score. Explanation: If input string is 'MANGO' Abhi's score : 10 Ramu's score: 5 Input format First line of input containing the string. Note: The string will contain only uppercase letters. [A - Z] Output format Print one line: the name of the winner and their score separated by a space. If the game is a draw, print Draw. Code constraints The string will contain only uppercase letters. 0 < len(S) <= 10^6 Sample testcases Input 1 MANGO Output 1 Abhi 10 Input 2 ETIO Output 2 Ramu 7
"""

def substrings(s):
    substrs = []
    for i in range(len(s)):
        for ln in range(i+1, len(s)+1):
            substrs.append(s[i:ln])
    return substrs
    
s = input()
subs = substrings(s)
vowels = ['A', 'E', 'I', 'O', 'U']
ramu = 0
abhi = 0
for sub in subs:
    if (sub[0] in vowels):
        ramu += 1
    else:
        abhi += 1

if (abhi > ramu):
    print("Abhi " + str(abhi))
else:
    print("Ramu " + str(ramu))
