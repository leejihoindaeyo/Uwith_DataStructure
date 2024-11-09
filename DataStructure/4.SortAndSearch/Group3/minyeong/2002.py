n = int(input())   
in_cars = {}
out_cars = []

for i in range(n):
  in_cars[input().strip()] = i
for _ in range(n):
  out_cars.append(input().strip())

cnt = 0  

for i in range(n-1):
  for j in range(i+1, n):
    if in_cars[out_cars[i]] > in_cars[out_cars[j]]:
      cnt += 1
      break
print(cnt)
