s = input()
count = set()

for i in range(len(s)):
    for j in range(i,len(s)):
        count.add(s[i:j+1])
print(len(count))
