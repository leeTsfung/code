def generate_matrix(rows, cols):
    matrix = []
    for i in range(1, rows + 1):
        row = []
        for j in range(1, cols + 1):
            row.append(i * j)
        matrix.append(row)
    return matrix


def print_matrix(matrix):
    for row in matrix:
        print(row)


def main():
    try:
        rows = int(input("请输入矩阵的行数："))
        cols = int(input("请输入矩阵的列数："))

        if rows <= 0 or cols <= 0:
            print("行数和列数必须为正整数！")
            return

        result_matrix = generate_matrix(rows, cols)
        print("生成的矩阵为：")
        print_matrix(result_matrix)
    except ValueError:
        print("请输入有效的整数！")


if __name__ == "__main__":
    main()
