n = int(input())
num_cards = list(map(int,input().split()))
m = int(input())
check_cards = list(map(int,input().split()))

card_count = {}
for card in num_cards:
    if card in card_count:
        card_count[card] += 1
    else:
        card_count[card] = 1

result = []
for card in check_cards:
    result.append(card_count.get(card, 0))

print(" ".join(map(str, result)))