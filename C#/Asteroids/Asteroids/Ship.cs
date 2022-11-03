using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Asteroids
{
    class Ship : BaseObject
    {
        Image img = Image.FromFile("..\\..\\..\\image/flyboat.png");

        public static event Message MessageDie;
        int energy = 100;
        int score = 0;
        public int Energy {  get { return energy; } }
        public int Score { get { return score; } }
        public void Energylow (int n) { energy -= n; }
        public void Scoreplus (int n) { score += n; }

        public Ship(Point pos, Point dir, Size size) : base (pos, dir, size)
        {
        }
        public override void Draw()
        {
            Game.buffer.Graphics.DrawImage(img, pos.X, pos.Y, size.Width * 3, size.Height * 3);
        }
        public override void Update()
        {

        }
        public void Up()
        {
            if (pos.Y > 0) pos.Y = pos.Y - dir.Y;
        }
        public void Down()
        {
            if (pos.Y < Game.Height - 50) pos.Y = pos.Y + dir.Y;
        }
        public void Left ()
        {
            if (pos.X > 0) pos.X = pos.X - dir.X;
        }
        public void Right ()
        {
            if (pos.X < Game.Width - 50) pos.X = pos.X + dir.X;
        }
        public void Die()
        {
            MessageDie?.Invoke();
        }
    }
}
