# 11478번 서로 다른 부분 문자열의 갯수

string = input()

substrings = set()

for i in range(len(string)):
    for j in range(i + 1, len(string) + 1):
        substrings.add(string[i:j])

print(len(substrings))
    