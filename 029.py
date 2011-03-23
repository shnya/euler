
d = dict();

for i in range(2,101):
    for j in range(2,101):
        d[i**j] = 1

print len(d)    
