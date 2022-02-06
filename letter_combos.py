def letterCombinations(digits: str) -> list[str]:
    res = []
    letters = {'0': '_', '1': '', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
    for digit in digits:
        if (len(res) == 0):
            for letter in letters[digit]:
                res.append(letter)
        else:
            res_len = len(res)
            for i in range(res_len):
                for letter in letters[digit]:
                    res.append(res[0] + letter)
                del res[0]
    return res

print(letterCombinations('23'))
print(letterCombinations(''))
print(letterCombinations('2'))
