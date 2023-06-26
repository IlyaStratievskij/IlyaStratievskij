def is_prime(a):
    temp = 0
    for i in range(2, a // 2+1):
        if (a % i == 0):
            temp = temp + 1
    if (temp <= 0):
        return True
    else:
        return False
        
print('Введите число:')
a = int(input())
print(is_prime(a))