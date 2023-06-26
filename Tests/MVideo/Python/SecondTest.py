from math import sqrt 

def square(a):
    perimetr = a * 4
    square = a * a
    diagonal = sqrt(2 * a)
    return [perimetr, square, diagonal]
        
print('Введите число:')
a = int(input())
print(square(a))