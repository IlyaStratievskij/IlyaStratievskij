using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Khendys.Controls;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Threading;


namespace Client
{
    public partial class Client : System.Windows.Forms.Form
    {
        static private Socket client;
        private IPAddress ip = null;
        private int port = 0;
        private Thread th;
        string myS = "";
        int k = 0;

        private System.Windows.Forms.FontDialog fdlg_SendMessage;
        private System.Windows.Forms.ContextMenu cmenu_Emoticons;
        private Image[] emoticons;
        private RtfCodes frm_RtfCodes;
        private ToolBar tbar_SendMessage;
        private ToolBarButton tbBtn_Font;
        private ToolBarButton tbBtn_Emoticons;
        private Panel pnl_SendMessage;
        private CheckBox chBox_ShowRtf;
        private ExRichTextBox rtbox_SendMessage;
        private Button btn_SendMessage;
        private Panel pnl_MessageHistory;
        private ExRichTextBox rtbox_MessageHistory;
        private Label lbl_MessageHistory;

        public Client()
        {

            InitializeComponent();

            pnl_MessageHistory.Enabled = false;
            pnl_SendMessage.Enabled = false;
            btn_SendMessage.Enabled = false;

            this.StartPosition = FormStartPosition.Manual;
            this.Location = new Point((SystemInformation.PrimaryMonitorMaximizedWindowSize.Width - this.DesktopBounds.Width) / 2,
                (SystemInformation.PrimaryMonitorMaximizedWindowSize.Height - this.DesktopBounds.Height) / 2);

            // Удалить выпадающий список с панели инструментов
            tbar_SendMessage.DropDownArrows = false;
            try
            {
                var sr = new StreamReader(@"Client_info\data_info.txt");
                string buf = sr.ReadToEnd();
                sr.Close();
                string[] connect_info = buf.Split(':');
                ip = IPAddress.Parse(connect_info[0]);
                port = int.Parse(connect_info[1]);

                label2.ForeColor = Color.Green;
                label2.Text = "Настройки:\nIP сервера: " + connect_info[0] + "\nPort Сервера: " + connect_info[1];
                label3.Text = "";
            }
            catch (Exception ex)
            {
                label2.ForeColor = Color.Red;
                label2.Text = "Настройки не найден";
                Form2 form = new Form2();
                form.Show();
            }

            // загружаем картинки эмоций
            emoticons = new Image[9];
            emoticons[0] = new Bitmap(Properties.Resources.AngelSmile);
            emoticons[1] = new Bitmap(Properties.Resources.AngrySmile);
            emoticons[2] = new Bitmap(Properties.Resources.Beer);
            emoticons[3] = new Bitmap(Properties.Resources.BrokenHeart);
            emoticons[4] = new Bitmap(Properties.Resources.ConfusedSmile);
            emoticons[5] = new Bitmap(Properties.Resources.CrySmile);
            emoticons[6] = new Bitmap(Properties.Resources.DevilSmile);
            emoticons[7] = new Bitmap(Properties.Resources.EmbarassedSmile);
            emoticons[8] = new Bitmap(Properties.Resources.ThumbsUp);

            // Создание меню эмоции
            EmoticonMenuItem _menuItem;
            int _count = 0;
            foreach (Image _emoticon in emoticons)
            {
                _menuItem = new EmoticonMenuItem(_emoticon);
                _menuItem.Click += new EventHandler(cmenu_Emoticons_Click);
                if (_count % 3 == 0)
                    _menuItem.BarBreak = true;

                cmenu_Emoticons.MenuItems.Add(_menuItem);
                ++_count;
            }
        }
        void SendMessage(string s)
        {

            byte[] buf = new byte[4096];
            buf = Encoding.UTF8.GetBytes(s);
            client.Send(buf);
        }
        void RecvMessage()
        {
            byte[] buf = new byte[4096];
            for (int i = 0; i < buf.Length; i++) buf[i] = 0;
            try
            {
                for (; ;)  {
                    client.Receive(buf);
                    string message = Encoding.UTF8.GetString(buf);
                    
                    int count = message.IndexOf(";;;S");
                    if (count == -1) continue;

                    string Clear_Message = "";
                    for (int i = 0; i < count; i++) Clear_Message += message[i];
                    for (int i = 0; i < buf.Length; i++) buf[i] = 0;
                    this.Invoke((MethodInvoker)delegate ()
                    {
                        ExRichTextBox rtf = new ExRichTextBox();
                        for (int i = 0; i < Clear_Message.Length; i++)
                        {
                            if (Clear_Message[i] == '=' && Clear_Message[i + 1] == '0') {
                                rtf.InsertImage((Bitmap)Properties.Resources.AngelSmile);
                                i++;
                            }
                            else if (Clear_Message[i] == '#' && Clear_Message[i + 1] == '|') {
                                rtf.InsertImage((Bitmap)Properties.Resources.AngrySmile);
                                i++;
                            }
                            else if (Clear_Message[i] == '=' && Clear_Message[i + 1] == '|') {
                                rtf.InsertImage((Bitmap)Properties.Resources.Beer);
                                i++;
                            }
                            else if (Clear_Message[i] == '>' && Clear_Message[i + 1] == '3') {
                                rtf.InsertImage((Bitmap)Properties.Resources.BrokenHeart);
                                i++;
                            }
                            else if (Clear_Message[i] == ':' && Clear_Message[i + 1] == '/') {
                                rtf.InsertImage((Bitmap)Properties.Resources.ConfusedSmile);
                                i++;
                            }
                            else if (Clear_Message[i] == ';' && Clear_Message[i + 1] == '(') {
                                rtf.InsertImage((Bitmap)Properties.Resources.CrySmile);
                                i++;
                            }
                            else if (Clear_Message[i] == '$' && Clear_Message[i + 1] == ')') {
                                rtf.InsertImage((Bitmap)Properties.Resources.DevilSmile);
                                i++;
                            }
                            else if (Clear_Message[i] == ':' && Clear_Message[i + 1] == '|') {
                                rtf.InsertImage((Bitmap)Properties.Resources.EmbarassedSmile);
                                i++;
                            }
                            else if (Clear_Message[i] == '+' && Clear_Message[i + 1] == ')') {
                                rtf.InsertImage((Bitmap)Properties.Resources.ThumbsUp);
                                i++;
                            }
                            else rtf.AppendText("" + Clear_Message[i]);
                        }
                        rtf.Font = fdlg_SendMessage.Font;
                        rtf.ForeColor = fdlg_SendMessage.Color;

                        rtbox_MessageHistory.AppendRtf(rtf.Rtf);
                        rtbox_MessageHistory.Select(rtbox_MessageHistory.TextLength, 0);
                        rtbox_MessageHistory.ScrollToCaret();
                    });

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Server Disconnect!");
                Environment.Exit(1);
            }
        }

        
        // При нажатии на смайлик вставьте его изображение в формат RTF
        private void cmenu_Emoticons_Click(object _sender, EventArgs _args)
        {
            EmoticonMenuItem _item = (EmoticonMenuItem)_sender;
            try
            {
                while (k < rtbox_SendMessage.Text.Length)
                {
                    myS += rtbox_SendMessage.Text[k];
                    k++;
                }
                
                if (_item.Image == emoticons[0]) myS += "=0";
                else if (_item.Image == emoticons[1]) myS += "#|";
                else if (_item.Image == emoticons[2]) myS += "=|";
                else if (_item.Image == emoticons[3]) myS += ">3";
                else if (_item.Image == emoticons[4]) myS += ":/";
                else if (_item.Image == emoticons[5]) myS += ";(";
                else if (_item.Image == emoticons[6]) myS += "$)";
                else if (_item.Image == emoticons[7]) myS += ":|";
                else if (_item.Image == emoticons[8]) myS += "+)";
                k++;
                rtbox_SendMessage.InsertImage(_item.Image);
            }
            catch (Exception _e)
            {
                MessageBox.Show("Rtf Image Insert Error\n\n" + _e.ToString());
            }
        }
        private void chBox_ShowRtf_CheckedChanged(object sender, System.EventArgs e)
        {
            if (chBox_ShowRtf.Checked)
                frm_RtfCodes.Show();
            else
                frm_RtfCodes.Hide();
        }

        private void Client_Load(object sender, EventArgs e)
        {
            frm_RtfCodes = new RtfCodes(this);
            frm_RtfCodes.Show();
        }
        private void btn_SendMessage_Click(object sender, System.EventArgs e)
        {
            try
            {
                // Добавьте владельца поддельного сообщения с помощью вставки
                //rtbox_MessageHistory.AppendTextAsRtf("Local User Said\n\n", new Font(this.Font, FontStyle.Underline | FontStyle.Bold), RtfColor.Blue, RtfColor.Yellow);
                if (k == 0 || rtbox_SendMessage.Text.Length - k > 0)
                {
                    while (k < rtbox_SendMessage.Text.Length)
                    {
                        myS += rtbox_SendMessage.Text[k];
                        k++;
                    }
                }
                
                if (rtbox_SendMessage.Text.Length > 0) SendMessage("\n[" + textBox1.Text + "]: " + myS.Trim() + ";;;S");
                myS = ""; 
                k = 0; 

                // Добавьте коды Rtf в окно RTF-кода
                frm_RtfCodes.AppendText(rtbox_SendMessage.Rtf);

                // Очищаем SendMessage box.
                rtbox_SendMessage.Text = String.Empty;
            }
            catch (Exception _e)
            {
                MessageBox.Show("An error occured when \"sending\" :\n\n" +
                    _e.Message, "Send Error");
            }
        }

        private void tbar_SendMessage_ButtonClick(object sender, System.Windows.Forms.ToolBarButtonClickEventArgs e)
        {
            if (e.Button == this.tbBtn_Font)
            {
                if (DialogResult.OK == fdlg_SendMessage.ShowDialog())
                {
                    rtbox_MessageHistory.Font = fdlg_SendMessage.Font;
                    rtbox_MessageHistory.ForeColor = fdlg_SendMessage.Color;
                    rtbox_SendMessage.Font = fdlg_SendMessage.Font;
                    rtbox_SendMessage.ForeColor = fdlg_SendMessage.Color;
                }
            }

        }
        
        private void авторToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("By Stratievskiji Ilya \n2021 year \nKKMT");
        }
        private void cmenu_Emoticons_Popup(object sender, EventArgs e) {}
        private void fdlg_SendMessage_Apply(object sender, EventArgs e){}
        private void rtbox_SendMessage_TextChanged(object sender, EventArgs e){ }
        private void rtbox_SendMessage_TextChanged(object sender, KeyEventArgs e) 
        {
            if (e.KeyCode == Keys.Back && rtbox_SendMessage.Text.Length != 0)
            {
                if (k == 0 || rtbox_SendMessage.Text.Length - k > 0)
                {
                    while (k < rtbox_SendMessage.Text.Length)
                    {
                        myS += rtbox_SendMessage.Text[k];
                        k++;
                    }
                }
                try
                {
                    if (myS[myS.Length - 2] == '=' && myS[myS.Length - 1] == '0' ||
                        myS[myS.Length - 2] == '#' && myS[myS.Length - 1] == '|' || myS[myS.Length - 2] == '=' && myS[myS.Length - 1] == '|' ||
                        myS[myS.Length - 2] == '>' && myS[myS.Length - 1] == '3' || myS[myS.Length - 2] == ':' && myS[myS.Length - 1] == '/' ||
                        myS[myS.Length - 2] == ';' && myS[myS.Length - 1] == '(' || myS[myS.Length - 2] == '$' && myS[myS.Length - 1] == ')' ||
                        myS[myS.Length - 2] == ':' && myS[myS.Length - 1] == '|' || myS[myS.Length - 2] == '+' && myS[myS.Length - 1] == ')') myS = myS.Remove(myS.Length - 2, 2);
                    else myS = myS.Remove(myS.Length - 1, 1);
                    k--;
                }
                catch (Exception ex)
                {
                    rtbox_SendMessage.Text = String.Empty;
                    myS = "";
                    k = 0;
                }
            }
        }
        private void rtbox_MessageHistory_TextChanged(object sender, EventArgs e) {}
        private void lbl_MessageHistory_Click(object sender, EventArgs e) {}
        private void label1_Click(object sender, EventArgs e) {}

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (th != null)
                th.Abort();
            if (client != null)
                client.Close();
            Application.Exit();
        }

        private void настройкиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 form = new Form2();
            form.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                textBox1.Text = textBox1.Text.Trim();
                bool b = true;
                for (int i = 0; i < textBox1.Text.Length; i++)
                    if (!Char.IsLetter(textBox1.Text, i) && !Char.IsWhiteSpace(textBox1.Text, i)) b = false;
                if (textBox1.Text.Length <= 15 && textBox1.Text.Length >= 1 && b)
                {
                    pnl_MessageHistory.Enabled = true;
                    pnl_SendMessage.Enabled = true;
                    btn_SendMessage.Enabled = true;
                    textBox1.Enabled = false;
                    button1.Enabled = false;
                    
                    client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                    if (ip != null)
                    {
                        label3.Hide();
                        client.Connect(ip, port);
                        SendMessage(textBox1.Text + ";;;S");
                        th = new Thread(delegate () { RecvMessage(); });
                        th.Start();
                    }
                }
                else
                {
                    label3.ForeColor = Color.Blue;
                    label3.Text = "Имя имеет только буквы и длина = 15";
                    textBox1.Clear();
                }
            }
            catch (Exception ex)
            {
                label2.ForeColor = Color.Red;
                label2.Text = "Настройки не найден";
                Form2 form = new Form2();
                form.Show();
            }
        }
    }
}
