# numways to travel from bottom right to top left, 
# only allowed to move up and left
# O(mn) time and space
def grid_traveller(m, n):
    arr = [[0 for j in range(n+1)] for i in range(m+1)]
    arr[1][1] = 1
    for i in range(m+1):
        for j in range(n+1):
            if (i != m):
                arr[i+1][j] += arr[i][j]
            if (j != n):
                arr[i][j+1] += arr[i][j]
    return arr[m][n]

print(grid_traveller(1, 1))
print(grid_traveller(3, 3))
print(grid_traveller(2, 3))
print(grid_traveller(3, 2))
print(grid_traveller(18, 18))
