N=int(input())
stack=[ ]
for i in range(N):
	order=input().split()
	if order[0]=='push':
		stack.append(order[1])
	elif order[0]=='pop':
		print(stack.pop() if len(stack)>0 else -1) 
	elif order[0]=='size':
		print(len(stack))
	elif order[0]=='empty':
		print(int(len(stack)==0))
	elif order[0]=='top':
		print(stack[-1] if len(stack)>0 else -1)