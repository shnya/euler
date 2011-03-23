from math import * 

def is_palindromic(n):
    a = 0
    b = n
    for x in xrange(0,5):
        a = a * 10 + n % 10
        n /= 10
        if a == n:
            return True
        else:
            if a > n:
                break
    return False

maxa = 0
for x in xrange(100,1000):
    for y in xrange(100, 1000):
        if x*y > maxa and is_palindromic(x*y) :
            maxa = x*y

print maxa
