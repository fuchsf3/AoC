stones = list(map(int, open("input.txt").readline().strip().split()))

# def resolveStone(number, blinks):
#     if blinks == 0:
#         return 1
#     if number == 0:
#         return resolveStone(1, blinks - 1)
#     # I did't now that you can assign a value in if statement like this
#     if len(str_stone := str(number)) % 2 == 0:
#         mid = len(str_stone) // 2
#         return resolveStone(int(str_stone[:mid]), blinks - 1) + resolveStone(
#             int(str_stone[mid:]), blinks - 1
#         )
#     return resolveStone(number * 2024, blinks - 1)

# crazy that just adding this to the program makes it 10x faster
memory = {}


def resolveStone(number, blinks):
    if blinks == 0:
        return 1
    elif (number, blinks) in memory:
        return memory[(number, blinks)]
    elif number == 0:
        tmp = resolveStone(1, blinks - 1)
    # I did't now that you can assign a value in if statement like this
    elif len(str_stone := str(number)) % 2 == 0:
        mid = len(str_stone) // 2
        tmp = resolveStone(int(str_stone[:mid]), blinks - 1) + resolveStone(
            int(str_stone[mid:]), blinks - 1
        )
    else:
        tmp = resolveStone(number * 2024, blinks - 1)
    memory[(number, blinks)] = tmp
    return tmp


print(sum(resolveStone(stone, 25) for stone in stones))
print(sum(resolveStone(stone, 75) for stone in stones))
