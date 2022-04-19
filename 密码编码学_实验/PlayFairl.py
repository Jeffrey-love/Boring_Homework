#! /usr/bin/python
# -*- coding:utf-8 -*-


def matrix(key1):
    matrix1 = []
    for e in key1.upper():
        if e not in matrix1:
            matrix1.append(e)
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    for e in alphabet:
        if e not in matrix1:
            matrix1.append(e)
    matrix_group = []
    for e in range(5):
        matrix_group.append('')
    matrix_group[0] = matrix1[0:5]
    matrix_group[1] = matrix1[5:10]
    matrix_group[2] = matrix1[10:15]
    matrix_group[3] = matrix1[15:20]
    matrix_group[4] = matrix1[20:25]
    return matrix_group


def message_to_digraphs(message_original):
    # 转换为列表
    message1 = []
    for e in message_original:
        message1.append(e)
    for unused in range(len(message1)):
        if " " in message1:
            message1.remove(" ")

    # 两位数相同则加一个X
    i = 0
    for e in range(int(len(message1) / 2)):
        if message1[i] == message1[i + 1]:
            message1.insert(i + 1, 'X')
        i = i + 2

    # 奇数位加X
    if len(message1) % 2 == 1:
        message1.append("X")
    i = 0
    new = []
    for x in range(1, int(len(message1) / 2 + 1)):
        new.append(message1[i:i + 2])   # 两两分组
        i = i + 2
    return new


def find_position(key_matrix, letter):
    x = y = 0
    for i in range(5):
        for j in range(5):
            if key_matrix[i][j] == letter:
                x = i
                y = j
    return x, y


def encrypt(message2):
    message2 = message_to_digraphs(message2)
    key_matrix = matrix(key)
    cipher2 = []
    for e in message2:  # p, q 分别是行和列
        p1, q1 = find_position(key_matrix, e[0])
        p2, q2 = find_position(key_matrix, e[1])
        if p1 == p2:
            if q1 == 4:
                q1 = -1
            if q2 == 4:
                q2 = -1
            cipher2.append(key_matrix[p1][q1 + 1])
            cipher2.append(key_matrix[p2][q2 + 1])
        elif q1 == q2:
            if p1 == 4:
                p1 = -1
            if p2 == 4:
                p2 = -1
            cipher2.append(key_matrix[p1 + 1][q1])
            cipher2.append(key_matrix[p2 + 1][q2])
        else:
            cipher2.append(key_matrix[p1][q2])
            cipher2.append(key_matrix[p2][q1])
    return cipher2


def cipher_to_digraphs(cipher3):
    i = 0
    new = []
    for x in range(int(len(cipher3) / 2)):
        new.append(cipher3[i:i + 2])
        i = i + 2
    return new


def decrypt(cipher4):
    cipher4 = cipher_to_digraphs(cipher4)
    key_matrix = matrix(key)
    plaintext = []
    for e in cipher4:
        p1, q1 = find_position(key_matrix, e[0])
        p2, q2 = find_position(key_matrix, e[1])
        if p1 == p2:
            if q1 == 4:
                q1 = -1
            if q2 == 4:
                q2 = -1
            plaintext.append(key_matrix[p1][q1 - 1])
            plaintext.append(key_matrix[p1][q2 - 1])
        elif q1 == q2:
            if p1 == 4:
                p1 = -1
            if p2 == 4:
                p2 = -1
            plaintext.append(key_matrix[p1 - 1][q1])
            plaintext.append(key_matrix[p2 - 1][q2])
        else:
            plaintext.append(key_matrix[p1][q2])
            plaintext.append(key_matrix[p2][q1])

    for unused in range(len(plaintext)):
        if "X" in plaintext:
            plaintext.remove("X")

    output = ""
    for e in plaintext:
        output += e
    return output.lower()


if __name__ == '__main__':
    order = input("1,Encrypting \n2,Decrypting\nInput:")
    if order == '1':
        key = "JEFFREY"
        message = input("Input plain text:")
        print("Encrypting: \n" + "Message: " + message)
        # print("Break the message into digraphs: ", end='')
        # print(message_to_digraphs(message))
        # print("Matrix: ", end='')
        # print(matrix(key))
        cipher_t = ''.join(encrypt(message))
        print("Cipher: " + cipher_t)

    elif order == '2':
        key = "JEFFREY"
        cipher = input("Input cipher text: ")
        print("\nDecrypting: \n" + "Cipher: " + cipher)
        print("Plaintext:" + decrypt(cipher))
    else:
        print("Error")
