S = input()
count = set()

length = len(S)

for i in range(length):
    for j in range(i+1, length+1):
        count.add(S[i:j])

print(len(count))