#! /usr/bin/python
# -*- coding:utf-8 -*-


def encrypt_text(s1, s2, key):
    encrypt = ''
    for i in range(0, 4):
        temp = ord(s1[i]) ^ ord(s2[i]) ^ ord(key[i])    # 按位异或
        encrypt += chr(temp)
    return encrypt


def encode(plainText, key_list):
    cipherText = ''
    for i in range(0, len(plainText) // 8):
        temp = plainText[i * 8:(i + 1) * 8]  # 每8个字符划分成一组加密
        left = temp[:4]    # 取前四个
        right = temp[4:]    # 从第五个开始取完
        for key in key_list:
            temp2 = right
            right = encrypt_text(left, right, key)
            left = temp2
        cipherText += right + left
    return cipherText


def main():
    key = []
    a = input('请输入要加密的字符串:')    # 输入8的倍数个字符
    keynum = input('循环次数:')
    for i in range(0, int(keynum)):
        temp = input('请输入第' + str(i) + '组密钥（4个字符）')
        key.append(temp)
    print('要加密的明文为:', a)
    a = encode(a, key)
    print('加密后的密文:', a)

    # 解密
    key.reverse()   # 列表元素取反
    a = encode(a, key)
    print('解密后的明文:', a)


if __name__ == '__main__':
    main()
