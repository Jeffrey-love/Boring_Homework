#! /usr/bin/python
# -*- coding:UTF-8 -*-


def main():
    n = int(input())
    st = input()
    li = [int(x) for x in st.split()]
    ans = -60000
    for i in range(n):
        ans = max(ans, li[i])
    if ans <= 0:
        print(ans)
    else:
        sum1 = 0
        for i in range(n):
            if sum1 + li[i] < 0:
                sum1 = 0
            else:
                sum1 += li[i]
            ans = max(ans, sum1)
        print(ans)


if __name__ == '__main__':
    main()
