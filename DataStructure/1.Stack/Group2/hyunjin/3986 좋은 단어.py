def is_good_word(word):
    stack = []

    for char in word:
        if stack and stack[-1] == char:
            stack.pop()
        else:
            stack.append(char)

    return len(stack) == 0

n = int(input())
good_word_count = 0

for _ in range(n):
    word = input().strip()
    if is_good_word(word):
        good_word_count += 1

print(good_word_count)
