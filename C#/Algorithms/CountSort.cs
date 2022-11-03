// Сортировка подсчётом
using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] arr = new int[n];
        int[] b = new int[10000];
        int[] aSort = new int[10000];
        string[] str = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
            arr[i] = int.Parse(str[i]);

        for (int i = 0; i < n; i++)
            b[arr[i]]++;

        for (int i = 1; i < 10000; i++)
            b[i] += b[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            aSort[b[arr[i]]] = arr[i];
            b[arr[i]]--;
        }
        for (int i = 1; i <= n; i++)
            Console.Write(aSort[i] + " ");
    }
}