def count_odd_even(numbers):
    odd_count = 0
    even_count = 0

    for num in numbers:
        if num % 2 == 0:
            even_count += 1
        else:
            odd_count += 1

    return odd_count, even_count


# 例子
numbers = (1, 2, 3, 4, 5, 6, 7, 8, 9)
odd_count, even_count = count_odd_even(numbers)
print("奇数个数:", odd_count)
print("偶数个数:", even_count)
