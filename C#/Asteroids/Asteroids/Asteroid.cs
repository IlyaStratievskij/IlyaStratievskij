using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Asteroids
{
    class Asteroid : BaseObject
    {
        Image img = Image.FromFile("..\\..\\..\\image/asteroid2.png");
        public int Power { get; set; }

        public Asteroid(Point pos, Point dir, Size size) : base (pos, dir, size)
        {
            Power = 1;
        }

        public override void Draw()
        {
            Game.buffer.Graphics.DrawImage(img, pos.X, pos.Y, size.Width , size.Height );
        }

        public override void Update()
        {
            pos.X += dir.X;
            if (pos.X < 0 )
            {
                pos.X = Game.Width + 20;
                pos.Y = Game.rnd.Next(0, Game.Height);
            }
        }
    }
}
