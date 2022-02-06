def strStr(haystack: str, needle: str) -> int:
    if (needle == ''):
        return 0
    for i in range(len(haystack) - len(needle) + 1):
        for j in range(len(needle)):
            if (needle[j] != haystack[i+j]):
                break
            if (j == len(needle)-1):
                return i
    return -1

print(strStr("hello", "ll"))
print(strStr("abc", "c"))
print(strStr("suckmydickinmyballsassholelol", "dick"))
print(strStr("brooolmaoooooooooo69", "oooo"))
