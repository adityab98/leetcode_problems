#given target word and list of words return true if target can be constructed by concatenating the words in the wordbank
def breakdown(word, prefix):
    if (word[0:len(prefix)] == prefix):
        return word[len(prefix):]
    elif (word[len(word)-len(prefix):] == prefix):
        return word[:len(word)-len(prefix)]
    else: return word

def canconstruct(word, bank, memo = {}):
    if (word in memo): return memo[word]
    if (word == ''): return True
    for w in bank:
        broken = breakdown(word, w)
        if (broken != word):
            if (canconstruct(broken, bank)):
                memo[word] = True
                return True
    memo[word] = False
    return memo[word]

print (canconstruct('', ['cat', 'dog', 'mouse']))
print (canconstruct("abcdef", ['ab', 'cd', 'ef', 'abcd', 'acd', 'acfgdhgxx']))
print (canconstruct('skateboard', ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar']))
print (canconstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeex", ["e", "ee", "eee", "eeeee", "eeeeee", "eeeeeeee"]))
