from random import randint
from datetime import datetime


def simple():
    while True:
        sushu = randint(100, 1000)
        if judge(sushu):
            return sushu


def judge(sushu):
    for i in range(2, sushu):
        if sushu % i == 0:
            return False
    return True


def judge_husu(int_min, int_max):
    for i in range(2, int_min+1):
        if int_min % i == 0 and int_max % i == 0:
            return False
    return True


def finde(oula):
    top = oula
    while True:
        i = randint(2, top)
        for e in range(i, top):
            if judge_husu(e, oula):
                return e
        top = i


def main():
    time_start = datetime.now()
    p = simple()
    q = p
    while p == q:
        q = simple()
    n = p * q
    oula = (p-1)*(q-1)
    e = finde(oula)

    k = 1
    while (k * oula + 1) % e != 0:
        k += 1
    d = int((k*oula+1)/e)
    time_end = datetime.now()
    print("计算用时" + str(time_end - time_start))
    print("n=" + str(n) + " , e=" + str(e) + " , d=" + str(d))
    m = input('输入文本:')
    time_start = datetime.now()
    m_list = []
    for item in m:
        m_list.append(ord(item))
    c_list = []
    for m in m_list:
        c = m**e % n
        c_list.append(c)
    time_end = datetime.now()
    print("密文:" + str(c_list))
    print("加密用时" + str(time_end - time_start))
    time_start = datetime.now()
    decode_messages = []
    for c in c_list:
        decode_message = c**d % n
        decode_messages.append(chr(decode_message))
    plain = ''.join(decode_messages)
    time_end = datetime.now()
    print("解密后的明文:" + plain)
    print("解密用时" + str(time_end - time_start))


if __name__ == '__main__':
    main()
