using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Text;
using System.Windows.Forms;

namespace Client
{
    public partial class RtfCodes : System.Windows.Forms.Form
    {
        private System.Windows.Forms.TextBox tbox_RtfCodes;
        private int line;
        StringBuilder appendText;

        //private System.ComponentModel.Container components = null;
        public RtfCodes()
        {
            InitializeComponent();
            tbox_RtfCodes.Font = new Font(FontFamily.GenericMonospace, 8.2f);
            tbox_RtfCodes.ScrollBars = ScrollBars.Both;
            tbox_RtfCodes.WordWrap = false;
            tbox_RtfCodes.AcceptsReturn = true;
            line = 0;
        }
        public RtfCodes(Form _owner) : this()
        {
            this.Owner = _owner;
            this.Width = _owner.Width;
            this.Height = _owner.Height / 2;
            this.StartPosition = FormStartPosition.Manual;
            this.Location = new Point(this.Owner.Location.X, this.Owner.Location.Y - this.Height - SystemInformation.CaptionHeight);
        }
        public void AppendText(string _text)
        {
            ++line;
            appendText = new StringBuilder();
            appendText.Append("<");
            appendText.Append("Line ");
            appendText.Append(line);
            appendText.Append(">");
            appendText.Append(" ");
            appendText.Append(_text);
            tbox_RtfCodes.Text += appendText.ToString();
        }
        private void tbox_RtfCodes_TextChanged(object sender, EventArgs e) {}

        private void RtfCodes_Load(object sender, EventArgs e) {}
    }
}
