#! /usr/bin/python
# -*- coding:utf-8 -*-


def gogogo(li, i):
    sum = 0
    count = 0
    for item in range(i, len(li)):
        sum += int(li[item])
        if sum > 7:
            return count
        count += 1
    return count


def main():
    str1 = input("输入数字:")
    li = str1.split()
    cou = 0
    while cou < len(li):
        add = gogogo(li, cou)
        cou += add
        print("在第" + str(cou) + "个加油站停一次")

    return True


if __name__ == '__main__':
    main()
