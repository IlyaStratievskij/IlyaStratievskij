// СОРТИРОВКА СЛИЯНИЕМ
using System;
using System.Collections.Generic;
class Program
{
    static List<int> Merge(List<int> a, List<int> b)
    {
        List<int> res = new List<int>();
        int ita = 0, itb = 0, lena = a.Count, lenb = b.Count;
        while (res.Count != (lena + lenb))
        {
            if (ita < lena && itb < lenb)
            {
                if (a[ita] > b[itb])
                {
                    res.Add(b[itb]);
                    itb++;
                }
                else
                {
                    res.Add(a[ita]);
                    ita++;
                }
            }
            else
            {
                if (ita < lena)
                {
                    res.Add(a[ita]);
                    ita++;
                }
                else
                {
                    res.Add(b[itb]);
                    itb++;
                }
            }
        }
        return res;
    }

    static List<int> MergeSort(List<int> arr, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            return Merge(MergeSort(arr, l, m), MergeSort(arr, m + 1, r));
        }
        else
        {
            List<int> a = new List<int>();
            a.Add(arr[l]);
            return a;
        }
    }

    static void Main()
    {
        List<int> arr = new List<int>();
        int n = int.Parse(Console.ReadLine());
        Random rnd = new Random();
        for (int i = 0; i < n; i++)
            arr.Add(rnd.Next(0, 100));

        for (int i = 0; i < n; i++)
            Console.Write(arr[i] + " ");

        Console.WriteLine("\n------------------------");
        arr = MergeSort(arr, 0, (arr.Count - 1));
        for (int i = 0; i < n; i++)
            Console.Write(arr[i] + " ");
        Console.ReadKey();
    }
}