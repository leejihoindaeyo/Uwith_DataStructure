n = int(input())
incar={}
outcar={}
for i in range(n):
    car = input()
    incar[car] = i  #해당 car는 i번째로 들어옴
for i in range(n):
    car = input()
    outcar[car] = i

num = 0
out_key = list(outcar.keys())
for i in range(0, len(out_key)-1):
    now_in = incar[out_key[i]]
    for j in range(i+1, len(out_key)):
        next_in = incar[out_key[j]]
        if next_in < now_in:
            num +=1
            break
print(num)