n = int(input())
car_in = [input() for i in range(n)]

answer = 0
for _ in range(n):
    car = input()
    if car_in[0] != car:
        answer += 1
    car_in.remove(car)
print(answer)