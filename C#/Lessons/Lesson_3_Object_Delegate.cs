using System;
using System.Collections;
using System.Collections.Generic;

namespace Lesson_3_Object_Delegate
{
    public delegate void MyGenericDelegate<T>(T arg);
    delegate void OpStroke(ref int[] arr);

    // Паттерн Наблюдатель
    public delegate void MyDelegate(object o);
    class Source
    {
        MyDelegate functions;
        public void Add(MyDelegate f)
        {
            functions += f;
        }
        public void Remove(MyDelegate f)
        {
            functions -= f;
        }
        public void Run()
        {
            Console.WriteLine("RUNS!");
            if (functions != null) functions(this);
        }
    }
    class Observer1 // Наблюдатель 1
    {
        public void Do(object o)
        {
            Console.WriteLine("Первый. Принял, что объект {0} побежал", o);
        }
    }
    class Observer2 // Наблюдатель 2
    {
        public void Do(object o)
        {
            Console.WriteLine("Второй. Принял, что объект {0} побежал", o);
        }
    }

    public class RemoveUserEventArgs : EventArgs
    {
        public string Message { get; }
        // Можем дописать сколько угодно свойств
        public RemoveUserEventArgs(string message)
        {
            Message = message;
        }
    }
    class SourceNew
    {
        // Добавили новый параметр
        //public delegate void Message(object obj, string message);
        //private event Message _message;
        private event EventHandler<RemoveUserEventArgs> _message;
        private List<string> _user = new List<string>();
        public SourceNew()
        {
            _user.AddRange(new[] { "Ivan", "Roman", "Stepan" });
        }
        public void RemoveUser(string nameUser, EventHandler<RemoveUserEventArgs> message)
        {
            _message = message;
            if (_user.Contains(nameUser))
            {
                _user.Remove(nameUser);
                // Изменился вызов события
                _message?.Invoke(this, new RemoveUserEventArgs($"Пользователь {nameUser} удален"));
            }
            else
            {
                _message?.Invoke(this, new RemoveUserEventArgs($"Пользователь {nameUser} не найден"));
                // Изменился вызов события
            }
        }
    }

    public class ArrOperation
    {
        public static void WriteArray(ref int[] arr)
        {
            Console.WriteLine("Исходный массив: ");
            foreach (int i in arr)
                Console.Write("{0}\t", i);
            Console.WriteLine();
        }
            // Сортировка массива
        public static void IncSort(ref int[] arr)
        {
            int j, k;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                j = 0;
                do
                {
                    if (arr[j] > arr[j + 1])
                    {
                        k = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = k;
                    }
                    j++;
                }
                while (j < arr.Length - 1);
            }
            Console.WriteLine("Отсортированный массив в большую сторону: ");
            foreach (int i in arr)
                Console.Write("{0}\t", i);
            Console.WriteLine();
        }
        public static void DecSort(ref int[] arr)
        {
            int j, k;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                j = 0;
                do
                {
                    if (arr[j] < arr[j + 1])
                    {
                        k = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = k;
                    }
                    j++;
                }
                while (j < arr.Length - 1);
            }
            Console.WriteLine("Отсортированный массив в меньшую сторону: ");
            foreach (int i in arr)
                Console.Write("{0}\t", i);
            Console.WriteLine();
        }
            // Заменяем нечетные числа четными и наоборот
        public static void ChetArr(ref int[] arr)
        {
            Console.WriteLine("Четный массив: ");
            for (int i = 0; i < arr.Length; i++)
                if (arr[i] % 2 != 0)
                    arr[i] += 1;
            foreach (int i in arr)
                Console.Write("{0}\t", i);
            Console.WriteLine();
        }
        public static void NeChetArr(ref int[] arr)
        {
            Console.WriteLine("Нечетный массив: ");
            for (int i = 0; i < arr.Length; i++)
                if (arr[i] % 2 == 0)
                    arr[i] += 1;
            foreach (int i in arr)
                Console.Write("{0}\t", i);
            Console.WriteLine();
        }
    }
    class Program
    {
        // Это цель для делегата Action<>.
        static void DisplayMessage(string msg, ConsoleColor txtColor, int printCount)
        {
            // Установить цвет текста консоли
            ConsoleColor previous = Console.ForegroundColor;
            Console.ForegroundColor = txtColor;
            for (int i = 0; i < printCount; i++)
            {
                Console.WriteLine(msg);
            }
            // Восстановить цвет
            Console.ForegroundColor = previous;
        }

        // Цель для делегата Func<>.
        static int Add(int x, int у) => x + у;
        static string SumToString(int x, int y) => (x + y).ToString();
        static void Main()
        {
            int[] myArr = new int[6] { 2, -4, 10, 5, -6, 9 };
            // Структурируем делегаты
            OpStroke Del;
            OpStroke Wr = ArrOperation.WriteArray;
            OpStroke OnSortArr = ArrOperation.IncSort;
            OpStroke OffSortArr = ArrOperation.DecSort;
            OpStroke ChArr = ArrOperation.ChetArr;
            OpStroke NeChArr = ArrOperation.NeChetArr;
             // Групповая адресация
            Del = Wr;
            Del += OnSortArr;
            Del += ChArr;
            Del += OffSortArr;
            Del += NeChArr;
            // Выполняем делегат
            Del?.Invoke(ref myArr);

            // Обобщённые делегаты
            Console.WriteLine("***** Generic Delegates *****\n");
            // Зарегистрировать цели

            MyGenericDelegate<string> strTarget = new MyGenericDelegate<string>(StringTarget);
            strTarget("Some string data");

            // А можно просто указать метод
            MyGenericDelegate<int> intTarget = IntTarget;
            intTarget(9);

            Action <string, ConsoleColor, int> ActionTarget = new Action<string, ConsoleColor, int>(DisplayMessage);
            ActionTarget("Hello Action delegate", ConsoleColor.Yellow, 5);

            Func<int, int, int> funcTarget = Add;
            int result = funcTarget(40, 40);
            Console.WriteLine($"40 + 40 = {result}");
            Func<int, int, string> funcTarget2 = SumToString;
            string sum = funcTarget2(90, 300);
            Console.WriteLine(sum);

            Source s = new Source();
            Observer1 o1 = new Observer1();
            Observer2 o2 = new Observer2();
            MyDelegate d1 = new MyDelegate(o1.Do);
            s.Add(d1);
            s.Add(o2.Do);
            s.Run();
            s.Remove(o1.Do);
            s.Run();

            SourceNew source = new SourceNew();
            source.RemoveUser("Ivan", MessageMain);
        }
        static void StringTarget(string arg)
        {
            Console.WriteLine("arg in uppercase is: {0}", arg.ToUpper());
        }
        static void IntTarget(int arg)
        {
            Console.WriteLine("++arg is: {0}", ++arg);
        }
        private static void MessageMain(object o, RemoveUserEventArgs message)
        {
            Console.WriteLine(message.Message);
        }
        
    }
}
