using System;
using System.Collections.Generic;
using System.Text;

namespace Lesson_Begin
{
    class Fractions
    {
        int numerator, denominator;
        public int Numerator
        {
            get { return numerator; }
            set { numerator = value; }
        }
        public int Denominator
        {
            get { return denominator; }
            set
            {
                if (value > 0) denominator = value;
            }
        }
        public Fractions()
        {
            numerator = 1;
            denominator = 1;
        }
        public Fractions(int numerator, int denominator)
        {
            this.numerator = numerator;
            this.denominator = denominator;
        }

        public void Enter()
        {
            int s;
            bool flag = false;
            Console.Write("Введите числитель: ");
            numerator = Convert.ToInt32(Console.ReadLine());
            do
            {
                Console.Write("Введите знаменатель: ");
                s = Convert.ToInt32(Console.ReadLine());
                if (s > 0) flag = true;
                else Console.WriteLine("Повторите попытку!");
            } while (!flag);
            denominator = s;
        }

        public Fractions Plus(Fractions x)
        {
            Fractions y = new Fractions();
            if (denominator == x.denominator)
            {
                y.numerator = numerator + x.numerator;
                y.denominator = denominator;
            }
            else
            {
                y.numerator = numerator * x.denominator + x.numerator * denominator;
                y.denominator = denominator * x.denominator;
            }
            return y;
        }
        public Fractions Minus(Fractions x)
        {
            Fractions y = new Fractions();
            if (denominator == x.denominator)
            {
                y.numerator = numerator + x.numerator;
                y.denominator = denominator;
            }
            else
            {
                y.numerator = numerator * x.denominator - x.numerator * denominator;
                y.denominator = denominator * x.denominator;
            }
            return y;
        }
        public Fractions Multiplications(Fractions x)
        {
            Fractions y = new Fractions();
            y.numerator = numerator * x.numerator;
            y.denominator = denominator * x.denominator;
            return y;
        }

        public string Output()
        {
            return numerator + "/" + denominator;
        }
    }
}
