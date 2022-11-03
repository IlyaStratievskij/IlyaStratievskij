using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;


namespace Asteroids
{
    class Game
    {
        static BufferedGraphicsContext context;
        static public BufferedGraphics buffer;
        // просто буфферизированный вывод в форме, возможности, что предостовляет Windows
        private static Timer timer = new Timer();
        static public int Width { get; set; }
        static public int Height { get; set; }
        static public BaseObject[] objs;
        private static List<Bullet> bullet = new List<Bullet>();
        private static List<Asteroid> asteroids = new List<Asteroid>();
        static Ship ship = new Ship(new Point(10, 200), new Point(5, 5), new Size(10, 10));
        static public Random rnd = new Random();

        static private Image img = Image.FromFile("..\\..\\..\\image/cosmos2.jpg");

        static Game()
        { }

        static public void Init(Form form)
        {
            Graphics g= form.CreateGraphics();
            context = BufferedGraphicsManager.Current;
            // получаем контекст текущего буффера
            Width = form.Width;
            Height = form.Height;
            buffer = context.Allocate(g, new Rectangle(0, 0, Width, Height));
            Load();
            //timer.Interval = 100;
            timer.Tick += Timer_Tick;
            form.KeyDown += Form_KeyDown; // делегат внутри нашей формы
            timer.Start();
            Ship.MessageDie += Finish;
        }

        private static void Finish()
        {
            timer.Stop();
            buffer.Graphics.DrawString("The End", new Font(FontFamily.GenericSansSerif, 60, FontStyle.Underline), Brushes.White, 200, 100);
            buffer.Render();
        }

        private static void Form_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.ControlKey) bullet.Add(new Bullet(new Point(ship.Rect.X + 25, ship.Rect.Y + 15), new Point(7, 0), new Size(4, 1)));
            if (e.KeyCode == Keys.Up) ship.Up();
            if (e.KeyCode == Keys.Down) ship.Down();
            if (e.KeyCode == Keys.Left) ship.Left();
            if (e.KeyCode == Keys.Right) ship.Right();
        }
        private static void Timer_Tick(object sender, EventArgs e)
        {
            Draw();
            Update();
        }

        static public void Draw()
        {
            buffer.Graphics.Clear(Color.Black);
            buffer.Graphics.DrawImage(img, new Rectangle(0, 0, Width, Height));
            foreach (BaseObject obj in objs)
                obj.Draw();
            
            foreach (Asteroid a in asteroids) a.Draw();

            foreach (Bullet b in bullet) b.Draw();
            ship.Draw();
            buffer.Graphics.DrawString("Energy:" + ship.Energy, SystemFonts.DefaultFont, Brushes.White, 0, 0);
            buffer.Graphics.DrawString("Score:" + ship.Score, SystemFonts.DefaultFont, Brushes.White, 500, 0);
            buffer.Render();
        }
        public static void Update()
        {
            foreach (BaseObject obj in objs)
                obj.Update();
            
            for (int i = 0; i < asteroids.Count; i++)
            {
                asteroids[i].Update();
                for (int j = 0; j < bullet.Count; j++)
                {
                    
                    if (bullet[j].Collision(asteroids[i]))
                    {
                        asteroids.RemoveAt(i);
                        if (i != 0) i--;
                        bullet.RemoveAt(j);
                        if (j != 0) j--;
                        ship.Scoreplus(rnd.Next(1, 10));
                        System.Media.SystemSounds.Hand.Play();
                        Console.WriteLine("Collision!");
                        if (i == 0 && asteroids.Count == 0)
                            break;
                    }

                    else if (bullet[j].Rect.X > Game.Width - 25)
                    {
                        bullet.RemoveAt(j);
                        if (j != 0) j--;
                    }
                }
                if (i == 0 && asteroids.Count == 0) 
                    break;
                if (!ship.Collision(asteroids[i])) continue;
                ship.Energylow(rnd.Next(5, 15));
                asteroids.RemoveAt(i);
                if (i != 0) i--;
                System.Media.SystemSounds.Asterisk.Play();
                if (ship.Energy <= 0) ship?.Die();
            }

            foreach (Bullet b in bullet) b.Update();
        }

        static public void Load()
        {
            objs = new BaseObject[30];

            for (var i = 0; i < objs.Length; i++)
            {
                int r = rnd.Next(5, 50);
                objs[i] = new Star(new Point(rnd.Next(0, Game.Width), rnd.Next(0, Game.Height)), new Point(-r, r), new Size(6, 6), new Pen(Color.White, 2));
            }
            for (var i = 0; i < rnd.Next(15, 25); i++)
            {
                int r = rnd.Next(0, 10);
                asteroids.Add( new Asteroid(new Point(Width, rnd.Next(0, Game.Height)), new Point(r - 15, 0), new Size(r + 15, r + 15)));
            }
        }
    }
}
