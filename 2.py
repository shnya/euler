a1 = 2
a2 = 1
sum = a1
for x in range(3, 100000):
    tmp = a1
    a1 = tmp + a2
    a2 = tmp
    print a1
    if a1 > 4000000:
        break
    if a1 % 2 == 0:
        sum += a1
print sum
