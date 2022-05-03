#! /usr/bin/python
# -*- coding:utf-8 -*-


def main():
    str1 = input("输入数字:")
    li = str1.split()
    li.sort()
    i = li[0]
    max_count = 0
    min_num = 999999
    count = 1
    for item in li:
        item = int(item)
        if i == item:
            count += 1
        else:
            if count > max_count:
                max_count = count
                min_num = i
            count = 1
            i = item
    print("最小数字" + str(min_num))
    print("出现次数" + str(max_count))
    return True


if __name__ == '__main__':
    main()
