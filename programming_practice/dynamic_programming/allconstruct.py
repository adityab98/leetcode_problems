#given target word and list of words return true if target can be constructed by concatenating the words in the wordbank
def all_construct(target, bank, memo = {}):
    if (target in memo): return memo[target]
    if (target == ""): return [[]]
    ways = []
    for word in bank:
        if (len(target) >= len(word) and target[:len(word)] == word):
            suffix = target[len(word):]
            suffix_ways = all_construct(suffix, bank)
            suffix_ways = [[word] + way for way in suffix_ways]
            ways.extend(suffix_ways)
    memo[target] = ways
    return memo[target]

print (all_construct('purple', ['purp', 'p', 'ur', 'le', 'purpl']))
print (all_construct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd']))
print (all_construct('skateboard', ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar']))
print (all_construct('enterapotentpot', ['a', 'p', 'ent', 'enter', 'ot', 'o', 't']))
print (all_construct('eeeeeeeeeeeeeeeeeeeeef', ['e', 'ee', 'eee', 'eeee', 'eeeee', 'eeeeee', 'eeeeeee']))
