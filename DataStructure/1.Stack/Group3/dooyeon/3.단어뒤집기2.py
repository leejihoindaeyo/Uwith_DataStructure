S=list(input())
temp,answer,tag = '','',False
for letter in S:
	if letter == ' ':
		if len(temp)>0: answer += temp; temp=''
		answer += letter
	elif letter == '<':
		if len(temp)>0: answer += temp;temp=''
		answer += letter; tag = True
	elif letter == '>': tag = False; answer+='>'
	elif not tag : temp = letter+temp
	elif tag : answer+=letter
if len(temp)>0:
	answer += temp
print(answer)