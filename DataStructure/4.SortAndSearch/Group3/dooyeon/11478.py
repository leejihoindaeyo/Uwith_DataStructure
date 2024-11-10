S = input().strip()
result = set()

n = len(S)
for i in range(n):
    for j in range(i + 1, n + 1):
        result.add(S[i:j])

print(len(result))