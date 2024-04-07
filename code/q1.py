def draw_pattern(num: int):
    for i in range(1, 2*num):
        if i <= num:
            print('*' * i)
        else:
            print('*' * (2*num - i))


draw_pattern(5)
