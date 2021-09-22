/* Калькулятор, работающий с большими числами, знаки операций(+ -) */


#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

int summa_numbers[50];

int main()
{
    setlocale(LC_ALL, "RUS");
    char znak;
    cout << "Введите знак: ";
    cin >> znak;

    int len_1, len_2, len_dubl_1, len_dubl_2;

    bool firstN, znak_first = false, znak_second = false;

    string number_1, number_2;

    cout << "Введите 2 числа: ";

    cin >> number_1 >> number_2 ;

    len_1 = number_1.length();
    len_2 = number_2.length();

    int array_numb_1[50];
    int array_numb_2[50];
    array_numb_2[0] = 0;
    array_numb_1[0] = 0;

    // преобразование первой строки в число

    int i = 0;
    if (number_1[i] == '-') {i++; znak_first = true; len_1--;
        while (number_1[i] >= 0x30 && number_1[i] <= 0x39)
    {
        array_numb_1[i - 1] = (number_1[i] & 0x0F);
        i++;
    }

    }

    else while (number_1[i] >= 0x30 && number_1[i] <= 0x39)
    {
        array_numb_1[i] = (number_1[i] & 0x0F);
        i++;
    }


    // преобразование второго числа

    i = 0;
    if (number_2[i] == '-') {i++; znak_second = true; len_2--;
        while (number_2[i] >= 0x30 && number_2[i] <= 0x39)
    {
        array_numb_2[i - 1] = (number_2[i] & 0x0F);
        i++;
    }

    }

    else while (number_2[i] >= 0x30 && number_2[i] <= 0x39)
    {
        array_numb_2[i] = (number_2[i] & 0x0F);
        i++;
    }

    len_dubl_1 = len_1;
    len_dubl_2 = len_2;

    // вывод первого числа в массиве

    cout << endl << "Первое число = ";

    for (int i = 0; i < len_1; i++)
        cout << array_numb_1[i];

    // вывод второго числа в массиве

    cout << endl << "Второе число = ";

    for (int i = 0; i < len_2; i++)
        cout << array_numb_2[i];

    // преобразование длины числа, чтобы удобнее выполнять действия

    if (len_1 > len_2)
    {
        while (len_2 != len_1)
        {
            for (int i = len_2; i > 0; i--)
            array_numb_2[i] = array_numb_2[i - 1];

            array_numb_2[0] = 0;
            len_2++;

        }
    }

    else if (len_2 > len_1)
    {
        while (len_1 != len_2)
        {
            for (int i = len_1; i > 0; i--)
            array_numb_1[i] = array_numb_1[i - 1];

            array_numb_1[0] = 0;
            len_1++;
        }

    }


    // вывод первого числа в массиве

    cout << endl << "Первое число после обработки = ";

    for (int i = 0; i < len_1; i++)
    {
        cout << array_numb_1[i];
    }


    // вывод второго числа в массиве

    cout << endl << "Второе число после обработки = ";

    for (int i = 0; i < len_2; i++)
    {
        cout << array_numb_2[i];
    }

    int len = 1;

    switch (znak) {

        case '-' :

        if (znak_first == 0 && znak_second == 0 || znak_first == 1 && znak_second == 1) {
            if (len_dubl_2 > len_dubl_1) {
                    for (i = len_1 - 1; i >= 0; i--) {
                    if (array_numb_1[i] > array_numb_2[i] && i == 0) array_numb_2[i] += 10;
                    else if (array_numb_1[i] > array_numb_2[i]) { array_numb_2[i] += 10; array_numb_2[i - 1] -= 1; }

                    summa_numbers[i] = array_numb_2[i] - array_numb_1[i];
                    len++;
                }
            }
            else {
                for (i = len_1 - 1; i >= 0; i--) {
                    if (array_numb_2[i] > array_numb_1[i] && i == 0) array_numb_1[i] += 10;
                    else if (array_numb_2[i] > array_numb_1[i]) { array_numb_1[i] += 10; array_numb_1[i - 1] -= 1; }

                    summa_numbers[i] = array_numb_1[i] - array_numb_2[i];
                    len++;
                }
            }
            cout << endl << "Сумма чисел впринципе = ";

            int sum = 0;
            for (i = 0; i < len; i++) sum += summa_numbers[i];
            if (sum == 0) cout << "0";
            else {
                while (summa_numbers[0] == 0) {
                    for (int i = 0; i < len ; i++) summa_numbers[i] = summa_numbers[i + 1];
                    len--;
                }

                if ((znak_second && znak_first && len_dubl_1 > len_dubl_2) || !(znak_first && znak_second) && len_dubl_2 > len_dubl_1) cout << "-";
                for (int i = 0; i < len - 1; i++)
                {
                    cout << summa_numbers[i];
                }
            }
        }
        else if ((znak_first == 1 && znak_second == 0) || (znak_first == 0 && znak_second == 1)) {
            for (int i = len_2; i > 0; i--)
            {
                summa_numbers[i] = (array_numb_2[i - 1] + array_numb_1[i - 1]) % 10;

                if (array_numb_1[i - 1] + array_numb_2[i - 1] > 9 && i > 1) array_numb_1[i - 2] += 1;
                len++;
            }

            cout << endl << "Сумма чисел впринципе = ";

            if ((array_numb_1[0] + array_numb_2[0]) > 9)summa_numbers[0] = ((array_numb_2[0] + array_numb_1[0]) / 10);

            int sum = 0;
            for (i = 0; i < len; i++) sum += summa_numbers[i];
            if (sum == 0) cout << "0";
            else {

                if (summa_numbers[0] == 0) {
                    for (int i = 0; i < len ; i++) summa_numbers[i] = summa_numbers[i + 1];
                    len--;
                }

                if ( znak_first == 1 && znak_second == 0 ) cout << "-";
                for (int i = 0; i < len ; i++)
                {
                    cout << summa_numbers[i];
                }
            }
        }
        break;

        case '+' :
        // Сумма этих чисел

        if (znak_first == 0 && znak_second == 0 || znak_first == 1 && znak_second == 1) {
            for (int i = len_2; i > 0; i--)
            {
                summa_numbers[i] = (array_numb_2[i - 1] + array_numb_1[i - 1]) % 10;
                if (array_numb_1[i - 1] + array_numb_2[i - 1] > 9 && i > 1) array_numb_1[i - 2] += 1;
                len++;
            }

            cout << endl << "Сумма чисел впринципе = ";

            if ((array_numb_1[0] + array_numb_2[0]) > 9)summa_numbers[0] = ((array_numb_2[0] + array_numb_1[0]) / 10);

            int sum = 0;
            for (i = 0; i < len; i++) sum += summa_numbers[i];
            if (sum == 0) cout << "0";
            else {
                if (summa_numbers[0] == 0) {
                for (int i = 0; i < len ; i++) summa_numbers[i] = summa_numbers[i + 1];
                len--;
                }

                if (znak_second && znak_first) cout << "-";
                for (int i = 0; i < len ; i++)
                {
                    cout << summa_numbers[i];
                }
            }
        }
        else if ((znak_first == 1 && znak_second == 0) || (znak_first == 0 && znak_second == 1)) {
            if (len_dubl_2 > len_dubl_1) {
                for (i = len_1 - 1; i >= 0; i--) {
                    if (array_numb_1[i] > array_numb_2[i] && i == 0) array_numb_2[i] += 10;
                    else if (array_numb_1[i] > array_numb_2[i]) { array_numb_2[i] += 10; array_numb_2[i - 1] -= 1; }

                    summa_numbers[i] = array_numb_2[i] - array_numb_1[i];
                    len++;
                }
            }
            else {
                for (i = len_1 - 1; i >= 0; i--) {
                    if (array_numb_2[i] > array_numb_1[i] && i == 0) array_numb_1[i] += 10;
                    else if (array_numb_2[i] > array_numb_1[i]) { array_numb_1[i] += 10; array_numb_1[i - 1] -= 1; }

                    summa_numbers[i] = array_numb_1[i] - array_numb_2[i];
                    len++;
                }
            }
            cout << endl << "Сумма чисел впринципе = ";

            int sum = 0;
            for (i = 0; i < len; i++) sum += summa_numbers[i];
            if (sum == 0) cout << "0";
            else {
                while (summa_numbers[0] == 0) {
                for (int i = 0; i < len ; i++) summa_numbers[i] = summa_numbers[i + 1];
                len--;
                }

                if ( znak_first == 1 && znak_second == 0 && len_dubl_1 > len_dubl_2 || znak_first == 0 && znak_second == 1 && len_dubl_1 < len_dubl_2) cout << "-";
                for (int i = 0; i < len - 1; i++)
                {
                    cout << summa_numbers[i];
                }
            }
        }
        break;
    }
}
