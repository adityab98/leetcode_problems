#given target word and list of words return true if target can be constructed by concatenating the words in the wordbank
def can_construct(target, bank):
    table = [False] * (len(target) + 1)
    table[0] = True

print (can_construct('purple', ['purp', 'p', 'ur', 'le', 'purpl']))
print (can_construct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd']))
print (can_construct('skateboard', ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar']))
print (can_construct('enterapotentpot', ['a', 'p', 'ent', 'enter', 'ot', 'o', 't']))
print (can_construct('eeeeeeeeeeeeeeeeeeeeef', ['e', 'ee', 'eee', 'eeee', 'eeeee', 'eeeeee', 'eeeeeee']))
