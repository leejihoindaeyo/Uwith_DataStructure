
N = int(input())

# 대근: 차 터널에 들어가는 순서
# 영식: 차 터널에서 나오는 순서

cars_In = []
cars_out = []

for i in range(N):
    cars_In.append(input())

for i in range(N):
    cars_out.append(input())

count = 0

for i in range(N):
    if cars_In[i] == cars_out[i]:
        pass
    else:
        temp = cars_In.pop(cars_In.index(cars_out[i]))
        cars_In.insert(i, temp)
        count+=1

print(count)
# n(인덱스)값이 다르면 count +1이 되도록
# 같은 거 있으면 삭제 
# 이미 나온 차는 삭제하기






