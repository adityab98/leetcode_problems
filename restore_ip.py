def valid(ip):
    groups = ip.split('.')
    print(groups)
    if (len(groups) > 4):
        return False
    for group in groups:
        if (len(group) > 1 and group[0] == '0'):
            return False
        if (int(group) > 255):
            return False
    return True

def generateIp(s, i):
    if (i >= len(s)):
        return ''
    ip = s[0 : i] + '.' + generateIp(s[i + 1:], i + 1)
    if (valid(ip)):
        return ip

def restoreIpAddresses(s, k = 0):
    if (s == None):
        return ''
    for i in range(len(s)):
        ip = s[i : k] + '.' + restoreIpAddresses(s[i + 1:], i)
        if (valid(ip)):
            return ip
    return ''

print(restoreIpAddresses("25525511135"))
