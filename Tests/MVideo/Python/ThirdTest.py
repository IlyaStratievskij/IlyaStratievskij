def bank(a, year):
    if year == 1:
        return a + a * 0.1
    else:
        return bank(a + a * 0.1, year - 1)
    
print('Ввудите сумму:')
a = int(input())
print('Ввeдите год:')
year = int(input())
print(f"Сумма вклада через {year} лет = {bank(a, year):.3f} рублей")