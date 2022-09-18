using System;

namespace Square
{
    public class SquareLow
    {
        static private bool examination(double a, double b, double c)
        {
            return Math.Pow(a, 2.0) == Math.Pow(b, 2.0) + Math.Pow(c, 2.0);
        }
        static SquareLow() { }
        public double Square(double temp)
        {
            if (temp <= 0)
                throw new ArgumentException("Радиус окружности не может быть меньше 0!");
            if (Double.IsNaN(temp))
                throw new ArgumentException("Радиус окружности должен быть числом!");

            return (Math.PI * Math.Pow(temp, 2.0));
        }
        public double Square(double a, double b, double c)
        {
            if (a <= 0 || b <= 0 || c <= 0)
                throw new ArgumentException("Все строны треугольника должны быть больше нуля!");
            if (a + b < c || a + c < b || b + c < a)
                throw new ArithmeticException("Заданные стороны не образуют треугольник!");

            if (examination(a, b, c) || examination(b, a, c) || examination(c, a, b))
                Console.Write("Треугольник Прямоугольный. ");

            double p = (a + b + c) / 2.0;
            return (Math.Sqrt(p * (p - a) * (p - b) * (p - c)));
        }
    }
}
