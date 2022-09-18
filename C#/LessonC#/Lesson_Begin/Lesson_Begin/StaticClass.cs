using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Lesson_Begin
{
    class StaticClass
    {
        int[] arr;
        public StaticClass()
        {
            arr = new int[20];
            Random rnd = new Random();
            for (int i = 0; i < 20; i++)
            {
                arr[i] = rnd.Next(-1000, 1000);
            }
        }
        public StaticClass(int myLenght)
        {
            arr = new int[myLenght];
            Random rnd = new Random();
            for (int i = 0; i < myLenght; i++)
            {
                arr[i] = rnd.Next(-1000, 1000);
            }
        }
        public StaticClass(int[] arr)
        {
            this.arr = arr;
        }
        public StaticClass(string filename)
        {
            if (File.Exists(filename))
            {
                int len = 0;
                StreamReader sr = new StreamReader(filename);
                while (!sr.EndOfStream)
                {
                    var a = sr.ReadLine();
                    len++;
                }
                sr.Close();
                sr = new StreamReader(filename);
                arr = new int[len];
                //sr.BaseStream.Seek(0, SeekOrigin.Begin);
                for (int i = 0; i < len; i++)
                {
                    arr[i] = int.Parse(sr.ReadLine());
                }
                sr.Close();
            }
        }

        public void OutPut()
        {
            for (int i = 0; i < arr.Length; i++)
                Console.Write("{0} ", arr[i]);
        }
        public int Sum ()
        {
            int sum = 0;
            for (int i = 0; i < arr.Length; i++)
                sum += arr[i];

            return sum;
        }

        public StaticClass Inverse()
        {
            StaticClass a = new StaticClass(arr.Length);
            for (int i = 0; i < arr.Length; i++)
                a.arr[i] = -this.arr[i];

            return a;
        }
        public StaticClass Multi(int n)
        {
            StaticClass a = new StaticClass(arr.Length);
            for (int i = 0; i < arr.Length; i++)
                a.arr[i] = this.arr[i] * n;

            return a;
        }
        public void Frequency()
        {
            var frequency = new Dictionary<int, int>();
            for (int i = 0; i < arr.Length; i++)
            {
                if (frequency.ContainsKey(arr[i]))
                    frequency[arr[i]]++;
                else
                    frequency.Add(arr[i], 1);
            }
            foreach(var i in frequency)
                Console.WriteLine(i.Key + ": " + i.Value);
        }
    }
}
