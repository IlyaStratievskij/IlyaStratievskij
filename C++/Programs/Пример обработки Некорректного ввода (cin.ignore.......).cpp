/*#include <iostream>
#include <string>
 
int main()
{
    std::string hello = "Hello, world!";
    int index;
 
    do
    {
        std::cout << "Enter an index: ";
        std::cin >> index;
 
        // Обрабатываем случай, когда пользователь ввел нецелочисленное значение
        if (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(32767, '\n'); 
            index = -1; // убеждаемся, что index имеет недопустимое значение, чтобы цикл продолжался
            continue; // этот continue может показаться здесь лишним, но он явно указывает на готовность прекратить выполнение этой итерации цикла
        }
 
    } while (index <= 0 || index >= hello.size()); // обрабатываем случай, когда пользователь ввел значение вне диапазона
 
    std::cout << "Letter #" << index << " is " << hello [index] << std::endl;
 
    return 0;
}*/

#include <iostream>
 
double getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Enter a double value: ";
        double a;
        std::cin >> a;
 
        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767,'\n'); // удаляем лишние значения
 
            return a;
        }
    }
}
 
char getOperator()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        std::cin >> sm;
 
        // Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения
 
        std::cin.ignore(32767,'\n'); // удаляем лишний балласт
 
        // Выполняем проверку пользовательского ввода
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/')    
            return sm; // возвращаем обратно в caller
        else // в противном случае, сообщаем пользователю что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } 
}
 
void printResult(double a, char sm, double b)
{
    if (sm == '+')
        std::cout << a << " + " << b << " is " << a + b << '\n';
    else if (sm == '-')
        std::cout << a << " - " << b << " is " << a - b << '\n';
    else if (sm == '*')
        std::cout << a << " * " << b << " is " << a * b << '\n';
    else if (sm == '/')
        std::cout << a << " / " << b << " is " << a / b << '\n';
    else 
        std::cout << "Something went wrong: printResult() got an invalid operator.";
 
}
 
int main()
{
    double a = getValue();
    char sm = getOperator();
    double b = getValue();
 
    printResult(a, sm, b);
 
    return 0;
}