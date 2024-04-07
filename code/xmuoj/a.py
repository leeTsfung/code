def correct_ranking(n, wealth):
    sorted_wealth = sorted(wealth)  # 对财产总值进行排序
    correct_rankings = 0

    for i in range(n):
        if wealth[i] == sorted_wealth[i]:  # 如果当前玩家的财产总值和排序后的财产总值相等，说明排名正确
            correct_rankings += 1

    return correct_rankings


# 读取输入
n = int(input())
wealth = list(map(int, input().split()))

# 输出结果
print(correct_ranking(n, wealth))
