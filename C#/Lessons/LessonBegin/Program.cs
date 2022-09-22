using System;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace Lesson_Begin
{
    #region StructComplex
    struct ComplexStruct
    {
        public double im, re;
        public ComplexStruct Plus(ComplexStruct x)
        {
            ComplexStruct y;
            y.im = im + x.im;
            y.re = re + x.re;
            return y;
        }
        public ComplexStruct Multi (ComplexStruct x)
        {
            ComplexStruct y;
            y.im = re * x.im + im * x.re;
            y.re = re * x.re - im * x.im;
            return y;
        }
        public string ToString()
        {
            return re + "+" + im + "i";
        }
    }
    #endregion StructComplex
    #region ClassComplex
    class Complex
    {
        double im, re;
        public Complex()
        {
            im = 0;
            re = 0;
        }
        public Complex (double im, double re)
        {
            this.im = im;
            this.re = re;
        }

        public Complex Plus(Complex x)
        {
            Complex y = new Complex();
            y.im = im + x.im;
            y.re = re + x.re;
            return y;
        }
        public Complex Multi(Complex x)
        {
            Complex y = new Complex();
            y.im = re * x.im + im * x.re;
            y.re = re * x.re - im * x.im;
            return y;
        }
        public Complex Minus(Complex x)
        {
            Complex y = new Complex();
            y.im = im - x.im;
            y.re = re - x.re;
            return y;
        }
        public double Im
        {
            get { return im; }
            set
            {
                if (value >= 0) im = value;
            }
        }
        public string ToString()
        {
            return re + "+" + im + "i";
        }
    }
    #endregion ClassComplex
    #region StructElement
    struct Element
    {
        public string tag, str;
        public Element(string tag, string str)
        {
            this.tag = tag;
            this.str = str;
        }
    }
    #endregion StructElement
    class Program
    {
        #region Name
        //static void HelloWorld(string str)
        //{
        //    Console.WriteLine("Привет " + str);
        //}
        //static void Main(string[] args)
        //{
        //    Console.Write("Введите имя: ");
        //    string str = Console.ReadLine();
        //    HelloWorld(str);
        //}
        #endregion Name
        #region Discriminant
        //static bool Odd(double n)
        //{
        //    return n % 2 == 0;
        //}
        //static void Main(string[] args)
        //{
        //    double a = 1, b = 1, c = 1, x;
        //    Console.Write("Enter x: ");
        //    x = Convert.ToDouble(Console.ReadLine());
        //    double f = a * Math.Pow(x, 2) + b * x + c;
        //    Console.WriteLine("{0} * {1}^2 + {2} * {1} + {3} = {4}", a, x, b, c, f);
        //    Console.WriteLine(Odd(f) ? "Число чётное" : "Число нечётное");
        //}
        #endregion Discriminant
        #region Console
        //static void Print(string msg, int x, int y)
        //{
        //    // Установим позицию курсора на экране
        //    Console.SetCursorPosition(x, y);
        //    Console.WriteLine(msg);
        //}
        //static void Print(string msg, ConsoleColor foregroundcolor)
        //{

        //    // Установим цвет символов
        //    Console.ForegroundColor = foregroundcolor;
        //    Console.WriteLine(msg);
        //}

        //// Создайте перегрузку функции, в которой будет указана позиция и цвет
        //static void Main()
        //{
        //    Print("Привет!\n", 10, 10);
        //    Print("Привет еще раз!", ConsoleColor.Red);
        //    Console.ReadLine();
        //}
        #endregion Console
        #region HomeWork1
        //static double IndexWeight (double m, double h)
        //{
        //    return m / (h * h);
        //}
        //static void Main()
        //{
        //    Console.WriteLine("Введите: ");
        //    Console.Write("Имя: ");
        //    string name = Console.ReadLine();
        //    Console.Write("Фамилия: ");
        //    string surname = Console.ReadLine();
        //    Console.Write("Возраст: ");
        //    int age = Convert.ToInt32(Console.ReadLine());
        //    Console.Write("Рост: ");
        //    double height = Convert.ToDouble(Console.ReadLine());
        //    Console.Write("Вес: ");
        //    double weight = Convert.ToDouble(Console.ReadLine());
        //    double indexWeight = IndexWeight(weight, height/100);

        //    Console.SetCursorPosition(50, 10);
        //    Console.ForegroundColor = ConsoleColor.Green;

        //    Console.WriteLine("{0} {1} \n\t\t\t age = {2} \n\t\t\t height = {3} weight = {4} \n\t\t\t index = {5}", 
        //        name, surname, age, height, weight, indexWeight);
        //}
        #endregion HomeWork1
        #region NOD
        //static int Nod (int a, int b)
        //{
        //    while (a != b)
        //        if (a > b) a = a - b; else b = b - a;
        //    return a;
        //}
        //static void Main()
        //{
        //    Console.WriteLine("Enter a and b: ");
        //    int a = Convert.ToInt32(Console.ReadLine());
        //    int b = Convert.ToInt32(Console.ReadLine());
        //    Console.WriteLine("Nod = " + Nod(a, b));
        //}
        #endregion NOD
        #region Arifmetic
        //static void Main()
        //{
        //    int k = 0, s = 0;
        //    int a = int.Parse(Console.ReadLine());

        //    while (a != 0)
        //    {
        //        if (a > 0 && a % 8 == 0) { k++; s += a; }
        //        a = int.Parse(Console.ReadLine());
        //    }
        //    Console.WriteLine("Среднее чисел кратных 8 = {0:F1}", (double)s / k);
        //}
        #endregion Arifmetic
        #region TimeProgram
        //static bool IsSimple(int n)
        //{
        //    for (int i = 2; i <= n / 2; i++)
        //        if (n % i == 0) return false;
        //    return true;
        //}
        //static void Main(string[] args)
        //{
        //    DateTime start = DateTime.Now;
        //    int k = 0;
        //    for (int i = 2; i< 1000000; i++)
        //    if (IsSimple(i))
        //    {
        //        k++;
        //        Console.WriteLine("{0} {1}",k,i);
        //    }
        //    Console.WriteLine(k);
        //    Console.WriteLine(DateTime.Now - start);
        //}
        #endregion TimeProgram
        #region Factorial
        //static uint Factorial (uint n)
        //{
        //    if (n == 0) return 1;
        //    else return Factorial(n - 1) * n;
        //}
        //static void Main()
        //{
        //    Console.Write("Введите число: ");
        //    uint n = Convert.ToUInt32(Console.ReadLine());
        //    Console.WriteLine("Факториал = " + Factorial(n));
        //}
        #endregion Factorial
        #region Homework2
        //static uint Sum(uint n)
        //{
        //    uint sum = 0;
        //    while (n != 0)
        //    {
        //        sum = sum + (n % 10);
        //        n /= 10;
        //    }
        //    return sum;
        //}
        //static void Main(string[] args)
        //{
        //    DateTime start = DateTime.Now;
        //    uint k = 0;
        //    for (uint i = 1; i < 100000; i++)
        //        if (i % Sum(i) == 0)
        //        {
        //            k++;
        //            Console.WriteLine(i);
        //        }

        //    Console.WriteLine(k);
        //    Console.WriteLine(DateTime.Now - start);
        //}
        #endregion Homework2
        #region ComplexStruct
        //static void Main(string[] args)
        //{
        //    ComplexStruct complex1;
        //    complex1.re = 1;
        //    complex1.im = 1;
        //    ComplexStruct complex2;
        //    complex2.re = 2;
        //    complex2.im = 2;

        //    ComplexStruct result = complex1.Plus(complex2);
        //    Console.WriteLine(result.ToString());

        //    result = complex1.Multi(complex2);
        //    Console.WriteLine(result.ToString());
        //}
        #endregion ComplexStruct
        #region ComplexClass
        //static void Main(string[] args)
        //{
        //    Complex complex1 = new Complex(1, 1);
        //    Complex complex2 = new Complex(1, 2);
        //    complex2.Im = 2;

        //    Complex result = complex1.Plus(complex2);
        //    Console.WriteLine(result.ToString());

        //    result = complex1.Multi(complex2);
        //    Console.WriteLine(result.ToString());
        //}
        #endregion ComplexClass
        #region Fractions
        //static void Main()
        //{
        //    Fractions number1 = new Fractions() ;
        //    number1.Enter();
        //    Console.WriteLine(number1.Output());

        //    Fractions number2 = new Fractions();
        //    number2.Enter();

        //    Fractions result = number1.Plus(number2);
        //    Console.WriteLine(result.Output());

        //    result = number1.Multiplications(number2);
        //    Console.WriteLine(result.Output());
        //}
        #endregion Fractions
        #region Homework4
        //static void Main()
        //{
        //    StaticClass array1 = new StaticClass();
        //    StaticClass array2 = new StaticClass(15);
        //    StaticClass array3 = new StaticClass("..\\..\\..\\data4.txt");

        //    Console.Write("\nArray 1: ");
        //    array1.OutPut();
        //    Console.Write("\nArray 2: ");
        //    array2.OutPut();
        //    Console.Write("\nArray 3: ");
        //    array3.OutPut();

        //    Console.Write("\nArray 4: ");
        //    StaticClass array4 = array3.Inverse();
        //    array4.OutPut();

        //    Console.Write("\nArray 5: ");
        //    StaticClass array5 = array3.Multi(2);
        //    array5.OutPut();

        //    Console.WriteLine("\nArray 3 Frequency: ");
        //    array3.Frequency();
        //}
        #endregion Homework4
        #region String
        //static void Main()
        //{
        //    string str1 = "Первая строка";
        //    string str2 = string.Copy(str1);
        //    string str3 = "Вторая строка";
        //    string str4 = "ВТОРАЯ строка";
        //    string strUp, strLow;
        //    int result, idx;
        //    Console.WriteLine("str1: " + str1);
        //    Console.WriteLine("Длина строки str1: " + str1.Length);
        //    // создаем прописную и строчную версии строки str1.
        //    strLow = str1.ToLower();
        //    strUp = str1.ToUpper();
        //    Console.WriteLine("Строчная версия строки str1: " + strLow);
        //    Console.WriteLine("Прописная версия строки str1: " + strUp);
        //    Console.WriteLine();
        //    // сравниваем строки
        //    result = str1.CompareTo(str3);
        //    if (result == 0) Console.WriteLine("str1 и str3 равны.");
        //    else if (result < 0) Console.WriteLine("str1 меньше, чем str3");
        //    else Console.WriteLine("str1 больше, чем str3");
        //    Console.WriteLine();

        //    // сравниваем строки без учета регистра
        //    result = String.Compare(str3, str4, true);
        //    if (result == 0) Console.WriteLine("str3 и str4 равны без учета регистра.");
        //    else Console.WriteLine("str3 и str4 не равны без учета регистра.");
        //    Console.WriteLine();
        //    // сравниваем части строк
        //    result = String.Compare(str1, 4, str2, 4, 2);
        //    if (result == 0) Console.WriteLine("часть str1 и str2 равны");
        //    else Console.WriteLine("часть str1 и str2 не равны");
        //    Console.WriteLine();

        //    // поиск строк
        //    idx = str2.IndexOf("строка");
        //    Console.WriteLine("Индекс первого вхождения подстроки сторка: " + idx);
        //    idx = str2.LastIndexOf("о");
        //    Console.WriteLine("Индекс последнего вхождения символа о: " + idx);
        //    // конкатенация
        //    string str = String.Concat(str1, str2, str3, str4);
        //    Console.WriteLine(str);
        //    // удаление подстроки
        //    str = str.Remove(0, str1.Length);
        //    Console.WriteLine(str);
        //    // замена подстроки "строка" на пустую подстроку
        //    str = str.Replace("строка", "");
        //    Console.WriteLine(str);
        //}
        #endregion String
        #region AmountLetters
        //static void Main()
        //{
        //    int[] count = new int[26];
        //    int i, k, code;
        //    char symbol;
        //    code = (int)('a');
        //    for (i = 0; i < 26; i++) count[i] = 0;
        //    string s = Console.ReadLine();
        //    s = s + '.';
        //    i = 0;
        //    do
        //    {
        //        symbol = s[i];
        //        k = (int)symbol;

        //        if (symbol >= 'a' && symbol <= 'z')
        //            count[k - code]++;

        //        i++;
        //    } while (symbol != '.');

        //    for (i = 0; i < 26; i++)
        //    {
        //        if (count[i] > 0) Console.WriteLine("{0} = {1}", (char)(code + i), count[i]);
        //    }
        //}
        #endregion AmountLetters
        #region Statement
        //static void Main()
        //{
        //    string s = File.ReadAllText("..\\..\\..\\pattern.txt");

        //    Element[] elem = new Element[8] {
        //        new Element("name1","ООО 'Одевайся'"),
        //        new Element("name2","Стратиевскому И.Б."),
        //        new Element("name3","менеджера по продажам"),
        //        new Element("name4","Сидорова А.А."),
        //        new Element("name5","Сидоров А.А."),
        //        new Element("data1","01.06.23"),
        //        new Element("data2","14.06.23"),
        //        new Element("data3","20.04.23"),
        //    };

        //    foreach(var el in elem)
        //    {
        //        Regex reg = new Regex("<" + el.tag + ">");
        //        s = reg.Replace(s, el.str);
        //    }
        //    Console.WriteLine(s);
        //}
        #endregion Statement
        #region Homework5
        //static string mySort(string s)
        //{
        //    char[] a = s.ToCharArray();
        //    Array.Sort(a);
        //    return new string(a);
        //}
        //static bool permutation(string s1, string s2)
        //{
        //    if (s1.Length != s2.Length)
        //        return false;
        //    else return mySort(s1).Equals(mySort(s2));
        //}
        //static bool permutation2(string s1, string s2)
        //{
        //    if (s1.Length != s2.Length)
        //        return false;

        //    int[] letters = new int[256];
        //    char[] s = s1.ToCharArray();
        //    foreach (char ch in s)
        //        letters[ch]++;

        //    for (int i = 0; i < s2.Length; i++)
        //    {
        //        int c = (int) s2[i];
        //        if (--letters[c] < 0)
        //            return false;
        //    }

        //    return true;
        //}
        //static void Main()
        //{
        //    string s1 = Console.ReadLine();
        //    string s2 = Console.ReadLine();
        //    Console.WriteLine(permutation(s1, s2) ? "Строки идентичны" : "Строки разные");
        //    Console.WriteLine(s1.Select(Char.ToUpper).OrderBy(x => x).SequenceEqual(s2.Select(Char.ToUpper).OrderBy(x => x)) ? "Строки идентичны" : "Строки разные");
        //    // Select позволяет преобразовать объект одного типа в объект другого типа
        //    // OrderBy для сортировки набора данных в LINQ можно применять оператор
        //    // SequenceEqual определяет, совпадают ли две последовательности, используя функцию сравнения на равенство.
        //    Console.WriteLine(permutation2(s1, s2) ? "Строки идентичны" : "Строки разные");
        //}
        #endregion Homework5
        static void Main()
        {
            int countAge = 0, countCourse = 0;
            Dictionary<string, int> student = new Dictionary<string, int>();
            Dictionary<string, int> frequencyAge = new Dictionary<string, int>();
            StreamReader file = new StreamReader("..\\..\\..\\student.txt");
            while (!file.EndOfStream)
            {
                string[] s = file.ReadLine().Split(' ');
                student.Add(s[1] + " " + s[0], int.Parse(s[3]));
                if (int.Parse(s[2]) <= 6 && int.Parse(s[2]) >= 5)
                    countCourse++;
                if (int.Parse(s[3]) <= 20 && int.Parse(s[3]) >= 18)
                {
                    countAge++;
                    if (frequencyAge.ContainsKey(s[3]+" "+s[2]))
                        frequencyAge[(s[3]+" "+s[2])]++;
                    else frequencyAge.Add(s[3] + " " + s[2], 1);
                }
            }
            student = student.OrderBy(pair => pair.Value).ToDictionary(pair => pair.Key, pair => pair.Value);
            
            foreach (var n in frequencyAge)
            {
                Console.WriteLine("{0} - {1}", n.Key, n.Value);
            }
        }
    }
}
