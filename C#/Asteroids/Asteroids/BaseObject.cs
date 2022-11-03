using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace Asteroids
{
    delegate void Message();
    abstract class BaseObject : ICollision
    {
        protected Point pos;
        protected Point dir;
        protected Size size;

        public BaseObject() { }

        protected BaseObject(Point pos, Point dir, Size size)
        {
            this.pos = pos;
            this.dir = dir;
            this.size = size;
        }

        public Rectangle Rect => new Rectangle(pos, size);

        public bool Collision(ICollision obj)
        {
            if (obj.Rect.IntersectsWith(this.Rect)) return true;
            else return false;
        }

        public abstract void Draw();


        public abstract void Update();
    }

    class Star : BaseObject
    {
        Image img = Image.FromFile("..\\..\\..\\image/star6.png");
        Pen color;
        public Star(Point pos, Point dir, Size size, Pen color) : base (pos, dir, size)
        {
            this.color = color;
        }
        public override void Draw()
        {
            Game.buffer.Graphics.DrawEllipse(color, pos.X, pos.Y, size.Width / 2, size.Height / 2);
            //Game.buffer.Graphics.DrawImage(img, pos.X, pos.Y, size.Width / 2, size.Height/ 2);
        }
        public override void Update()
        {
            pos.X += dir.X;
            if (pos.X < 0) pos.X = Game.Width + size.Width;
        }
    }
}
