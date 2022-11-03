// БИНАРНЫЙ ПОИСК
using System;
using System.Collections.Generic;

namespace AlgorithmTestCSharp
{
    internal class Program
    {
        static int BinarySearch(List<int> list, int k)
        {
            int l = 0, r = list.Count - 1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (list[m] == k)
                    return m + 1;
                else if (list[m] > k)
                    r = m - 1;
                else
                    l = m + 1;
            }
            return -1;
        }
        static void Main(string[] args)
        {
            int n, temp;
            n = int.Parse(Console.ReadLine());
            string[] str = Console.ReadLine().Split(' ');
            List<int> list = new List<int>(n);
            for (int i = 0; i < n; i++)
                list.Add(int.Parse(str[i]));
            list.Sort();


            temp = int.Parse(Console.ReadLine());
            str = Console.ReadLine().Split(' ');
            for (int i = 0; i < temp; i++)
                Console.Write(BinarySearch(list, int.Parse(str[i])) + " ");

            Console.ReadKey();
        }
    }
}