n = int(input())
s = input()
l = int(n/2)
r = int(n/2 + 1)
while s[l] == '0' and l >= 0 :
    l -= 1
while s[r] == '0' and r <= n :
    r += 1
res = int(s)
if l > 0:
    a = int(s[0:l])
    b = int(s[l:n])
    res = min(res,a+b)
if r < n:
    a = int(s[0:r])
    b = int(s[r:n])
    res = min(res,a+b)
print(res)