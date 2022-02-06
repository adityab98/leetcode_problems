def isValidSudoku(board):
    # rows and cols:
    for i in range(10):
        row_digits = []
        col_digits = []
        for j in range(10):
            if (board[i][j] not in row_digits):
                row_digits.append(board[i][j])
            else:
                return False
            if (board[j][i] not in col_digits):
                col_digits.append(board[j][i])
            else:
                return False
    # sectors/squares:
    for i in range(3, 10, 3):
        for j in range(i-3, i):
            for k in range(i-3, i):
    # base case: passed all tests
    return True
