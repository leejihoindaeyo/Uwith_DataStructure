def reverse_words(S):
    stack = []
    answer = ''
    inside_tag = False

    for char in S:
        if char == '<':
            while stack:
                answer += stack.pop()
            inside_tag = True
            answer += char
        elif char == '>':
            inside_tag = False
            answer += char
        elif inside_tag:
            answer += char
        elif char == ' ':
            while stack:
                answer += stack.pop()
            answer += ' '
        else:
            stack.append(char)

    while stack:
        answer += stack.pop()

    return answer

S = input()
print(reverse_words(S))
