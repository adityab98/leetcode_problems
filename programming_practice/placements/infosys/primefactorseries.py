import time
num = [1]
c2 = c3 = c5 = 0

while True:
  next = min(2*num[c2], 3*num[c3], 5*num[c5])
  num.append(next)
  print num
  if next == 2*num[c2]: c2 += 1
  if next == 3*num[c3]: c3 += 1
  if next == 5*num[c5]: c5 += 1
  time.sleep(0.5)
