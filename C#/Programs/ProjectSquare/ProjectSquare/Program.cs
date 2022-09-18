using System;
using Square;

namespace ProjectSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            SquareLow a = new SquareLow() ;
            Console.WriteLine("Площадь круга = {0:F3}", a.Square(55));
            Console.WriteLine("Площадь треугольница равна = {0:f1}", a.Square(4, 3, 5));
        }
    }
}
