word = input()
dan = set() # 집합으로 중복 처리

for i in range(1,len(word)+1):
    for j in range(len(word)):
        dan.add(word[j:j+i])

print(len(dan))