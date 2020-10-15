t, x = input().split(' ')
t = int(t)
x = int(x)
num = 0
add = x
year = 0
while (num < t):
    num += add
    year += 1
    add *= 3
print(year)