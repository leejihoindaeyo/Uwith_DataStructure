while True:
    str1 = input().strip()
    if str1 == ".":
        break
    st = []
    valid = True
    for ch in str1:
        if ch == '(' or ch == '[':
            st.append(ch)
        elif ch == ')':
            if st and st[-1] == '(':
                st.pop()
            else:
                valid = False
                break
        elif ch == ']':
            if st and st[-1] == '[':
                st.pop()
            else:
                valid = False
                break
    print("yes" if valid and not st else "no")