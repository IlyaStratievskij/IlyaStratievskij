// БЫСТРАЯ СОРТИРОВКА
using System;

class Program
{
    static public int[] QuickSort(int[] arr, int left, int right)
    {
        var i = left;
        var j = right;
        var mid = arr[left];
        do
        {
            while (arr[i] < mid) i++;
            while (arr[j] > mid) j--;
            if (i <= j)
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i++; j--;
            }
        } while (i <= j);
        if (j > left) QuickSort(arr, left, j);
        if (i < right) QuickSort(arr, i, right);

        return arr;
    }

    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] arr = new int[n];
        string[] str = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
            arr[i] = int.Parse(str[i]);

        arr = QuickSort(arr, 0, arr.Length - 1);

        for (int i = 0; i < n; i++)
            Console.Write(arr[i] + " ");

        Console.ReadKey();
    }
}