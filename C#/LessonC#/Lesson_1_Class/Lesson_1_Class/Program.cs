using System;

namespace Lesson_1_Class
{

    public class Animals
    {
        private string _name;
        public string Name
        {
            get => _name; private set => _name = value;
        }
        private int _numbPaws;
        public int Paws
        {
            get => _numbPaws; private set => _numbPaws = value;
        }
        public Animals (string _name, int p)
        {
            this._name = _name;
            _numbPaws = p;
        }
        public override string ToString() => $"Name = {_name}, Paws = {_numbPaws}";

    }
    public sealed class Cat : Animals
    {
        private ushort? _length;
        public Cat (string n, int p, ushort? l) : base (n, p)
        {
            _length = l;
        }
        public string ToString() => $"Name = {Name}, Paws = {Paws}, Length = {_length}";
    }
     class Vector
    {
        // Теперь поля приватные
        private double _x;
        private double _y;
        // Переопределим конструктор по умолчанию
        public Vector()
        {
            _x = _y = 0;
        }
        // Конструктор, который будет заполнять поля объекта
        public Vector(double x, double y)
        {
            _x = x;
            _y = y;
        }
        // Свойство X для доступа к полю x
        public double X
        {
            get => _x;
            set => _x = value;
        }
        // Свойство Y для доступа к полю y
        public double Y
        {
            get => _y;
            set => _y = value;
        }

        public static explicit operator Vector(double x) => new Vector(x, x);

        public static implicit operator double(Vector x) => x.X;

        // Переопределение метода ToString
        public override string ToString() => $"X= {X} Y= {Y}";

        public static Vector operator +(Vector v1, Vector v2)
        {
            Vector res = new Vector
            {
                X = v1.X + v2.X,
                Y = v1.Y + v2.Y
            };
            return res;
        }

        // Перегрузка бинарного оператора -

        public static Vector operator -(Vector v1, Vector v2)
        {
            Vector res = new Vector
            {
                X = v1.X - v2.X,
                Y = v1.Y - v2.Y 
            };
            return res;
        }

        // Перегрузка унарного оператора -

        public static Vector operator -(Vector v1)
        {
            Vector res = new Vector
            {
                X = -1 * v1.X,
                Y = -1 * v1.Y
            };
            return res;
        }
    }
    class MyObject
    {
    }
    class MyObject2 : MyObject
    {
    }
    class Program
    {
        static void Main(string[] args)
        {
            Vector v1 = new Vector(10, 5);
            Vector v2;
            v2 = new Vector(-5, -10);
            // Доступ к полям стал более логичным при записи
            v1.Y = 12;
            v2.X = -10;
            Console.WriteLine($"v1: X={v1.X} Y={v1.Y}"); // и при чтении
            Console.WriteLine($"v2: X={v2.X} Y={v2.Y}"); // и при чтении
            Vector v3 = v1 + v2;
            Console.WriteLine($"v1 + v2 = {v3}");
            Console.WriteLine(v3.ToString());
            v3 = v1 - v2;
            Console.WriteLine($"v1 - v2 = {v3.ToString()}");
            v3 = -v3;
            Console.WriteLine($"-(v1 - v2) = {v3.ToString()}");

            Animals dog = new Animals("Bobik", 4);
            Console.WriteLine(dog.ToString());
            Cat cat = new Cat("Pussy", 4, 25);
            Console.WriteLine(cat.ToString());

            MyObject obj1 = new MyObject();
            MyObject2 obj2 = new MyObject2();
            if (obj1 is MyObject) Console.WriteLine("obj1 является объектом класса MyObject");
            else Console.WriteLine("obj1 не является объектом класса MyObject");
            
            if (obj2 is MyObject2) Console.WriteLine("obj2 является объектом класса MyObject2");
            else Console.WriteLine("obj2 не является объектом класса MyObject2");

            // Здесь мы демонстрируем полиморфизм
            // Объекты базовых классов могут ссылаться на объекты производных классов

            MyObject obj3 = new MyObject2();
            if (obj3 is MyObject) Console.WriteLine("obj3 является объектом класса MyObject");
            else Console.WriteLine("obj3 не является объектом класса MyObject");

            MyObject obj = obj1 as MyObject;
            if (obj != null) Console.WriteLine($"Мы теперь можем обращаться к c obj как {obj}");

            obj = obj2 as MyObject2;
            if (obj != null) Console.WriteLine($"Мы теперь можем обращаться к c obj как {obj}");
        }
    }
}
