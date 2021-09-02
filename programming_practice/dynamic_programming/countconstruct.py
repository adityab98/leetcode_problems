#given target word and list of words return true if target can be constructed by concatenating the words in the wordbank
def breakdown(word, prefix):
    if (word[0:len(prefix)] == prefix):
        return word[len(prefix):]
    else: return None

def countconstruct(word, bank, memo = {}):
    if (word in memo): return memo[word]
    if (word == ''): return 1
    num = 0
    for w in bank:
        broken = breakdown(word, w)
        if (broken is not None):
            num += countconstruct(broken, bank, memo)
    memo[word] = num
    return memo[word]

print (countconstruct('purple', ['purp', 'p', 'ur', 'le', 'purpl']))
print (countconstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd']))
print (countconstruct('skateboard', ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar']))
print (countconstruct('enterapotentpot', ['a', 'p', 'ent', 'enter', 'ot', 'o', 't']))
print (countconstruct('eeeeeeeeeeeeeeeeeeeeef', ['e', 'ee', 'eee', 'eeee', 'eeeee', 'eeeeee', 'eeeeeee']))
