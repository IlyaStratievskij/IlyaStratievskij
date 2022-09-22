using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Lesson_4_Lists
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList list = new ArrayList();
            list.Add(1);
            list.Add(3.14);
            list.Add("String");
            list.Add(new int[] { 1, 2, 3 });
            foreach (object element in list)
                Console.WriteLine(element);
            foreach (var el in (int[])list[3])
                Console.WriteLine(el);
            #region ExampleDictionary
            var dict = new Dictionary<char, string>();

            dict.Add('r', "Roman");
            dict.Add('i', "Ivan");
            dict.Add('v', "Viktor");

            foreach (KeyValuePair<char, string> user in dict)
                Console.WriteLine($"{user.Key} - {user.Value}");

            dict['i'] = "Roman";
            dict['t'] = "Roman";

            foreach (KeyValuePair<char, string> user in dict)
                Console.WriteLine($"{user.Key} - {user.Value}");

            dict.Remove('i');

            if (dict.ContainsKey('i'))
            {
                var tempUser = dict['i'];
            }
            // перебор ключей
            foreach (var user in dict.Keys)
            {
                Console.WriteLine($"{user}");
            }
            // Перебор по значениям
            foreach (var p in dict.Values)
            {
                Console.WriteLine(p);
            }
            #endregion ExampleDictionary
            #region C# 6
            Dictionary<int, string> dictionary2 = new Dictionary<int, string>
            {
                [1] = "Roman",
                [2] = "Roman",
                [3] = "Roman",
                [4] = "Roman"
            };
            #endregion
            #region Queue
            var arr = new Queue<int>(4);
            arr.Enqueue(1); // 1
            arr.Enqueue(1); // 1 1
            arr.Enqueue(5); // 1 1 5
            arr.Enqueue(2); // 1 1 5 2
            Console.WriteLine(arr.Peek()); // 1 1 5 2
            Console.WriteLine(arr.Dequeue());// 1 5 2
            #endregion
            #region Stack
            var arr2 = new Stack<int>(4);
            arr2.Push(1);
            arr2.Push(5);
            arr2.Push(2);
            Console.WriteLine(arr2.Pop()); // извлекает и возвращает 1 элемент
            Console.WriteLine(arr2.Peek()); // возвращает 1 элемент без его удаления
            Console.WriteLine(arr2.Pop()); // извлекает и возвращает 1 элемент
            #endregion
            #region Lambda
            List<int> list2 = new List<int>();
            list2.AddRange(new int[] { 20, 1, 4, 8, 9, 4, 6 });
            Predicate<int> predicate = new Predicate<int>(IsEvenNumber);
            List<int> evenNumber = list2.FindAll(predicate);
            List<int> evenNumber2 = list2.FindAll(delegate (int i) { return (i % 2) == 0; });
            List<int> evenNumber3 = list2.FindAll(i => (i % 2) == 0);
            Console.WriteLine("Только чётные числа:");
            foreach (int even in evenNumber3)
                Console.Write("{0}\t", even);

            Console.WriteLine();
            #endregion
            #region Linq
            int[] nums = { 19, -2, 3, 0, -4, 5, 1 };
            var pos = from n in nums
                      where n > 0
                      select n;
            Console.Write("Положительные числа: ");
            foreach (int i in pos) Console.Write(i + " ");
            var pos2 = from n in nums
                       where n > 0
                       orderby n ascending
                       select n;
            Console.Write("\nПоложительные числа отсортированные: ");
            foreach (int i in pos2) Console.Write(i + " ");
            #endregion
        }

        private static bool IsEvenNumber(int obj)
        {
            return (obj % 2) == 0;
        }
    }
}
