#! /usr/bin/python
# -*- coding:utf-8 -*-
import operator


# 字母表
ZIMUBIAO = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
# 替换表
TIHUANBIAO = 'WFZEDJVKCXUISYTNMLBRQAHGPOqekfzsajicornyvmhgdwlbpxut'


# 统计字符出现次数
def count_each_char(str1):
    dict1 = {}
    for i in str1:
        if i not in dict1:
            dict1[i] = 1
        else:
            dict1[i] += 1
    dict1 = sorted(dict1.items(), key=operator.itemgetter(1), reverse=True)
    print('统计字符: ')
    print(dict1)
    return dict1


# 字母出现频率表
with open('article.txt', 'r') as f:
    message = f.read()
list_text = count_each_char(message)
dict_text = dict(list_text)


# 加密
def encryption():
    with open('article.txt', 'r') as f:
        message = f.read()
    encrypt_message = ''
    for i in message:
        if i in ZIMUBIAO:
            num = ZIMUBIAO.find(i)
            encrypt_message += TIHUANBIAO[num]
        else:
            encrypt_message += i
    print("加密完成，保存到'article_en.txt'")
    with open('article_en.txt', 'a') as f:
        f.write(encrypt_message)


def get_the_letter(letter, dict_de):
    frequency = dict_de[letter]
    min1 = 1
    lett = letter
    for item, fre in dict_text.items():
        if item in ZIMUBIAO:
            minus = abs(frequency-fre)
            if minus < min1:
                min1 = minus
                lett = item
    return lett


# 解密
def decryption():
    with open('article_en.txt', 'r') as f:
        message = f.read()

    dict_de = count_each_char(message)
    dict_de = dict(dict_de)
    # 计算出现频率
    max2 = 0
    for keys in dict_de:
        max2 += dict_de[keys]
    max2 = float(max2)
    for keys in dict_de:
        dict_de[keys] = float(dict_de[keys]) / max2
    plain_message = ''
    for i in message:
        if i in ZIMUBIAO:
            letter = get_the_letter(i, dict_de)
            plain_message += letter
        else:
            plain_message += i
    print("解密完成，保存到'article_de.txt'")
    with open('article_de.txt', 'a') as f:
        f.write(plain_message)


def main():
    max1 = 0
    for keys in dict_text:
        max1 += dict_text[keys]
    max1 = float(max1)
    for keys in dict_text:
        dict_text[keys] = float(dict_text[keys])/max1
    print('字符频率表:')
    print(dict_text)
    print("1. 加密操作")
    print("2. 解密操作")
    choice = int(input("输入要执行的操作:"))
    if choice == 1:
        encryption()
    elif choice == 2:
        decryption()
    else:
        print("输入错误!")


if __name__ == '__main__':
    main()
