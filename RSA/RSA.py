import random

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def quickPowMod(a, b, c):
    res = 1
    a = a%c
    while b != 0:
        if b&1 == 1:
            res = (res * a)%c
        a = (a * a)%c
        b = b >> 1
    return res

def quickPow(a, b):
    res = 1
    k = a
    while b != 0:
        if b&1 == 1:
            res = res * k
        k = k * k
        b = b >> 1
    return res

print('正在计算相关参数...')

# 使用欧拉素数筛离线计算一千万以内的素数
_prime_range = ['一万以内的素数.txt', '十万以内的素数.txt', '一百万以内的素数.txt', '一千万以内的素数.txt', '一亿以内的素数.txt']

# 用下标管理prime_range
_range = 1

# 读取打好的素数表
with open(_prime_range[_range], 'r') as f:
    prime = f.read().split(',')

# 获取素数表的长度
prime_num = len(prime)

# 随机p，q
p = 0
q = 0
while q == p:
    p = int(prime[random.randint(0, prime_num-1)])
    q = int(prime[random.randint(0, prime_num-1)])
n = p*q
fn = (p - 1)*(q - 1)
print('p=',p)
print('q=',q)
print('n=',n)
print('fn=',fn)


# # 随机求e
# while True:
#     e = random.randint(2, fn-1)
#     if(gcd(e ,fn) == 1):
#         break

# 顺序求e
e = -1
for i in range(2, fn):
    e = i
    if(gcd(e ,fn) == 1):
        break

print('e=', e)

d = -1
for i in range(2, 2<<32):
    # print(i)
    if (fn*i+1) % e == 0:
        d = (fn*i+1) // e
        break

print('d=', d)

# 获取输入并转换为大写
plaintext = input('计算结束，请输入待加密明文:').upper()

# 明文分组，单位bit
step = 16

# 明文分组补位
if len(plaintext) % (step // 8) != 0:
    for i in range(0, (step//8)-(len(plaintext)%(step//8))):
        plaintext += ' '

ciphertext = []

# 计算密文
for i in range(0, len(plaintext), (step//8)):
    group = ''
    for j in range(i, i+(step//8)):
        group += str(ord(plaintext[j]))
    ciphertext.append(quickPowMod(int(group), e, n))

print('密文为:', ciphertext)

# 反推明文
ans = []
for group in ciphertext:
    temp = quickPowMod(group, d, n)
    ans.append(chr(temp//100))
    if chr(temp%100) == ' ':
        continue
    ans.append(chr(temp%100))

print('尝试转换为明文以验证加密过程是否正确:', ans)