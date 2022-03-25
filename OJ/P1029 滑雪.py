#! /usr/bin/python
# -*- coding:UTF-8 -*-
def findmax(q, p):
    if b[q][p] != 0:
        return b[q][p]
    max2 = 0
    for k in range(4):
        x = q+c1[k][0]
        y = p+c1[k][1]
        if 0 <= x < c and 0 <= y < r and a[x][y] < a[q][p]:
            s = findmax(x, y)
            if s > max2:
                max2 = s
    b[q][p] = max2+1
    return max2+1


def main():
    max1 = 0
    for d1 in range(c):
        for d2 in range(r):
            b[d1][d2] = findmax(d1, d2)
            if b[d1][d2] > max1:
                max1 = b[d1][d2]
    print(max1)


if __name__ == '__main__':
    str1 = input()
    r, c = str1.split()
    r = int(r)
    c = int(c)
    b = [[0 for m in range(102)] for n in range(102)]
    a = [[0 for m in range(102)] for n in range(102)]
    for i in range(r):
        str2 = input()
        count = int(0)
        for item in str2.split():
            a[i][count] = int(item)
            count += 1
    c1 = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    main()
