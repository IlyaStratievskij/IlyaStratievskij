using System;
using System.Windows.Forms;

namespace Asteroids
{
    class Program
    {
        static void Main()
        {
            
            Form form = new Form();
            form.Width = 800;
            form.Height = 600;
            form.Show();
            Game.Init(form);
            Game.Draw();
            Application.Run(form);
        }
    }
}