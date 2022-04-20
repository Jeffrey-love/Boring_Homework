#! /usr/bin/python
# -*- coding:utf-8 -*-


def gcd(m, n):
    if n != 0:
        return gcd(n, m % n)
    else:
        return m


def gcdex(m, n):
    while n:
        temp = m % n
        m = n
        n = temp
    return m


def main():
    str1 = input("输入两个数:")
    m, n = str1.split()
    m = int(m)
    n = int(n)
    print("最大公约数为:" + str(gcdex(m, n)))


if __name__ == '__main__':
    main()
