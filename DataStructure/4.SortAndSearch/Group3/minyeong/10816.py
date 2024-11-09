import sys
input = sys.stdin.readline

n = int(input())
card = list(map(int, input().split()))
m = int(input())
mine = list(map(int, input().split()))

card.sort()

dic = {}

for x in card:
  if x in dic :
    dic[x] += 1
  else:
    dic[x] = 1

for x in mine:
  if x in dic:
    print(dic[x], end=' ')
  else:
    print('0', end= ' ') #주석 달아보기