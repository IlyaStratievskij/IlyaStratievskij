"""
Известная компания Тындекс в очередной раз проводит набор стажёров.
Заботясь о персональных данных соискателей, компания придумала хитрый алгоритм шифрования:

Подсчитывается количество различных символов в ФИО (регистр важен, А и а — разные символы).
Берётся сумма цифр в дне и месяце рождения, умноженная на 64.
Для первой (по позиции в слове) буквы фамилии определяется её номер в алфавите (в  1-индексации),
умноженный на 256 (регистр буквы не важен).
Полученные числа суммируются.
Результат переводится в 16-чную систему счисления (в верхнем регистре).
У результата сохраняются только 3 младших разряда (если значимых разрядов меньше, то шифр дополняется до
3-х разрядов ведущими нулями).
Ваша задача — помочь вычислить для каждого кандидата его шифр.

Формат ввода
В первой строке вводится число N(1≤N≤10000) — количество кандидатов и шифров.
Далее следует N строк в формате CSV (fj,ij,oj,dj,mj,yj) — информация о кандидатах:
Фамилия fj, имя ij и отчество oj(1≤∣∣fj∣∣,∣∣ij∣∣,∣∣oj∣∣≤15)
 — строки, состоящие из латинских букв верхнего и нижнего регистра;
день рождения dj, месяц рождения mj и год рождения yj
 — целые числа, задающие корректную дату в промежутке от 1 января 1950 года до 31 декабря 2021 года.
Формат вывода
В единственной строке выведите N строк k1, k2, …, kN, где kj — шифр j-го кандидата (в верхнем регистре).
Кандидаты нумеруются с 1 до N в порядке ввода.

Пример
Ввод
2
Volozh,Arcady,Yurievich,11,2,1964
Segalovich,Ilya,Valentinovich,13,9,1964
Выыод
710 64F
"""

n = int(input())
hexArray = []
for i in range(n):
    #tempLine = "Volozh,Arcady,Yurievich,11,2,1964"
    tempLine = input()
    arrayLine = tempLine.split(',')
    day = int(arrayLine[len(arrayLine)-3])
    month = int(arrayLine[len(arrayLine)-2])
    year = int(arrayLine[len(arrayLine)-1])

    arrayLetter = []
    for i in range(len(arrayLine[0])):
        if not(arrayLine[0][i] in arrayLetter): arrayLetter.append(arrayLine[0][i])
    if (len(arrayLine) >= 5):
        for i in range(len (arrayLine[1])):
            if not(arrayLine[1][i] in arrayLetter): arrayLetter.append(arrayLine[1][i])
    if (len(arrayLine) == 6):
        for i in range(len(arrayLine[2])):
            if not(arrayLine[2][i] in arrayLetter): arrayLetter.append(arrayLine[2][i])

    sumDayMonth = 0
    while day != 0:
        sumDayMonth += int(day % 10);
        day /= 10
    while month != 0:
        sumDayMonth += int(month % 10);
        month /= 10

    numberOfLetter = len(arrayLetter)    
    firstLetter =  ord(arrayLine[0][0]) - 64  if arrayLine[0][0].isupper() else ord(arrayLine[0][0]) - 96

    sumForHex = numberOfLetter + sumDayMonth * 64 + firstLetter * 256
    myHex = hex(sumForHex)
    threeHex = ''
    if len(myHex) == 3:
        temp = myHex[len(myHex)-1]
        threeHex = "00" + str(temp if temp.isdigit() else temp.upper())
    if len(myHex) == 4:
        temp1 = myHex[len(myHex)-1]
        temp2 = myHex[len(myHex)-2]
        threeHex = "0" + str(temp2 if temp2.isdigit() else temp2.upper()) + str(temp1 if temp1.isdigit() else temp1.upper())
    if len(myHex) > 4:
        temp1 = myHex[len(myHex)-1]
        temp2 = myHex[len(myHex)-2]
        temp3 = myHex[len(myHex)-3]
        threeHex = str(temp3 if temp3.isdigit() else temp3.upper()) + str(temp2 if temp2.isdigit() else temp2.upper()) + str(temp1 if temp1.isdigit() else temp1.upper())
    
    hexArray.append(threeHex)
    
for i in range(len(hexArray)):
    print(hexArray[i], end = ' ')