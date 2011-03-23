target = 600851475143
prime = 1
for x in xrange(1,target):
    for y in xrange(2,target+1):
        if target % y == 0:
            if y > prime:
                prime = y
            target /= y
            break
    if target == 1:
        break
print prime
