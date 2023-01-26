
namespace Client
{
    partial class Client
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.cmenu_Emoticons = new System.Windows.Forms.ContextMenu();
            this.fdlg_SendMessage = new System.Windows.Forms.FontDialog();
            this.tbar_SendMessage = new System.Windows.Forms.ToolBar();
            this.tbBtn_Font = new System.Windows.Forms.ToolBarButton();
            this.tbBtn_Emoticons = new System.Windows.Forms.ToolBarButton();
            this.pnl_SendMessage = new System.Windows.Forms.Panel();
            this.chBox_ShowRtf = new System.Windows.Forms.CheckBox();
            this.rtbox_SendMessage = new Khendys.Controls.ExRichTextBox();
            this.btn_SendMessage = new System.Windows.Forms.Button();
            this.pnl_MessageHistory = new System.Windows.Forms.Panel();
            this.rtbox_MessageHistory = new Khendys.Controls.ExRichTextBox();
            this.lbl_MessageHistory = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.менюToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.настройкиToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.выходToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.авторToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.pnl_SendMessage.SuspendLayout();
            this.pnl_MessageHistory.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // cmenu_Emoticons
            // 
            this.cmenu_Emoticons.Popup += new System.EventHandler(this.cmenu_Emoticons_Popup);
            // 
            // fdlg_SendMessage
            // 
            this.fdlg_SendMessage.ShowColor = true;
            this.fdlg_SendMessage.Apply += new System.EventHandler(this.fdlg_SendMessage_Apply);
            // 
            // tbar_SendMessage
            // 
            this.tbar_SendMessage.Buttons.AddRange(new System.Windows.Forms.ToolBarButton[] {
            this.tbBtn_Font,
            this.tbBtn_Emoticons});
            this.tbar_SendMessage.DropDownArrows = true;
            this.tbar_SendMessage.Location = new System.Drawing.Point(0, 0);
            this.tbar_SendMessage.Name = "tbar_SendMessage";
            this.tbar_SendMessage.ShowToolTips = true;
            this.tbar_SendMessage.Size = new System.Drawing.Size(600, 53);
            this.tbar_SendMessage.TabIndex = 2;
            this.tbar_SendMessage.ButtonClick += new System.Windows.Forms.ToolBarButtonClickEventHandler(this.tbar_SendMessage_ButtonClick);
            // 
            // tbBtn_Font
            // 
            this.tbBtn_Font.Name = "tbBtn_Font";
            this.tbBtn_Font.Text = "Шрифт";
            this.tbBtn_Font.ToolTipText = "Измените шрифт для вашего сообщения";
            // 
            // tbBtn_Emoticons
            // 
            this.tbBtn_Emoticons.DropDownMenu = this.cmenu_Emoticons;
            this.tbBtn_Emoticons.Name = "tbBtn_Emoticons";
            this.tbBtn_Emoticons.Style = System.Windows.Forms.ToolBarButtonStyle.DropDownButton;
            this.tbBtn_Emoticons.Text = "Эмоции";
            this.tbBtn_Emoticons.ToolTipText = "Вставьте смайлик";
            // 
            // pnl_SendMessage
            // 
            this.pnl_SendMessage.Controls.Add(this.chBox_ShowRtf);
            this.pnl_SendMessage.Controls.Add(this.rtbox_SendMessage);
            this.pnl_SendMessage.Controls.Add(this.btn_SendMessage);
            this.pnl_SendMessage.Controls.Add(this.tbar_SendMessage);
            this.pnl_SendMessage.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnl_SendMessage.Location = new System.Drawing.Point(0, 374);
            this.pnl_SendMessage.Name = "pnl_SendMessage";
            this.pnl_SendMessage.Size = new System.Drawing.Size(600, 148);
            this.pnl_SendMessage.TabIndex = 3;
            // 
            // chBox_ShowRtf
            // 
            this.chBox_ShowRtf.Checked = true;
            this.chBox_ShowRtf.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chBox_ShowRtf.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.chBox_ShowRtf.Location = new System.Drawing.Point(388, 9);
            this.chBox_ShowRtf.Name = "chBox_ShowRtf";
            this.chBox_ShowRtf.Size = new System.Drawing.Size(164, 28);
            this.chBox_ShowRtf.TabIndex = 4;
            this.chBox_ShowRtf.Text = "Показать RTF код";
            this.chBox_ShowRtf.CheckedChanged += new System.EventHandler(this.chBox_ShowRtf_CheckedChanged);
            // 
            // rtbox_SendMessage
            // 
            this.rtbox_SendMessage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.rtbox_SendMessage.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rtbox_SendMessage.HiglightColor = Khendys.Controls.RtfColor.White;
            this.rtbox_SendMessage.Location = new System.Drawing.Point(0, 53);
            this.rtbox_SendMessage.Name = "rtbox_SendMessage";
            this.rtbox_SendMessage.Size = new System.Drawing.Size(501, 95);
            this.rtbox_SendMessage.TabIndex = 1;
            this.rtbox_SendMessage.Text = "";
            this.rtbox_SendMessage.TextColor = Khendys.Controls.RtfColor.Black;
            this.rtbox_SendMessage.TextChanged += new System.EventHandler(this.rtbox_SendMessage_TextChanged);
            this.rtbox_SendMessage.KeyDown += new System.Windows.Forms.KeyEventHandler(this.rtbox_SendMessage_TextChanged);
            // 
            // btn_SendMessage
            // 
            this.btn_SendMessage.Dock = System.Windows.Forms.DockStyle.Right;
            this.btn_SendMessage.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_SendMessage.Location = new System.Drawing.Point(501, 53);
            this.btn_SendMessage.Name = "btn_SendMessage";
            this.btn_SendMessage.Size = new System.Drawing.Size(99, 95);
            this.btn_SendMessage.TabIndex = 3;
            this.btn_SendMessage.Text = "Отправить";
            this.btn_SendMessage.Click += new System.EventHandler(this.btn_SendMessage_Click);
            // 
            // pnl_MessageHistory
            // 
            this.pnl_MessageHistory.Controls.Add(this.rtbox_MessageHistory);
            this.pnl_MessageHistory.Controls.Add(this.lbl_MessageHistory);
            this.pnl_MessageHistory.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnl_MessageHistory.Location = new System.Drawing.Point(0, 139);
            this.pnl_MessageHistory.Name = "pnl_MessageHistory";
            this.pnl_MessageHistory.Size = new System.Drawing.Size(600, 235);
            this.pnl_MessageHistory.TabIndex = 4;
            // 
            // rtbox_MessageHistory
            // 
            this.rtbox_MessageHistory.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.rtbox_MessageHistory.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.rtbox_MessageHistory.HiglightColor = Khendys.Controls.RtfColor.White;
            this.rtbox_MessageHistory.Location = new System.Drawing.Point(0, 40);
            this.rtbox_MessageHistory.Name = "rtbox_MessageHistory";
            this.rtbox_MessageHistory.ReadOnly = true;
            this.rtbox_MessageHistory.Size = new System.Drawing.Size(600, 195);
            this.rtbox_MessageHistory.TabIndex = 0;
            this.rtbox_MessageHistory.Text = "";
            this.rtbox_MessageHistory.TextColor = Khendys.Controls.RtfColor.Black;
            this.rtbox_MessageHistory.TextChanged += new System.EventHandler(this.rtbox_MessageHistory_TextChanged);
            // 
            // lbl_MessageHistory
            // 
            this.lbl_MessageHistory.Location = new System.Drawing.Point(4, 14);
            this.lbl_MessageHistory.Name = "lbl_MessageHistory";
            this.lbl_MessageHistory.Size = new System.Drawing.Size(499, 24);
            this.lbl_MessageHistory.TabIndex = 2;
            this.lbl_MessageHistory.Text = "История чата";
            this.lbl_MessageHistory.Click += new System.EventHandler(this.lbl_MessageHistory_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.менюToolStripMenuItem,
            this.авторToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(600, 28);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // менюToolStripMenuItem
            // 
            this.менюToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.настройкиToolStripMenuItem,
            this.выходToolStripMenuItem});
            this.менюToolStripMenuItem.Name = "менюToolStripMenuItem";
            this.менюToolStripMenuItem.Size = new System.Drawing.Size(65, 24);
            this.менюToolStripMenuItem.Text = "Меню";
            // 
            // настройкиToolStripMenuItem
            // 
            this.настройкиToolStripMenuItem.Name = "настройкиToolStripMenuItem";
            this.настройкиToolStripMenuItem.Size = new System.Drawing.Size(167, 26);
            this.настройкиToolStripMenuItem.Text = "Настройки";
            this.настройкиToolStripMenuItem.Click += new System.EventHandler(this.настройкиToolStripMenuItem_Click);
            // 
            // выходToolStripMenuItem
            // 
            this.выходToolStripMenuItem.Name = "выходToolStripMenuItem";
            this.выходToolStripMenuItem.Size = new System.Drawing.Size(167, 26);
            this.выходToolStripMenuItem.Text = "Выход";
            this.выходToolStripMenuItem.Click += new System.EventHandler(this.выходToolStripMenuItem_Click);
            // 
            // авторToolStripMenuItem
            // 
            this.авторToolStripMenuItem.Name = "авторToolStripMenuItem";
            this.авторToolStripMenuItem.Size = new System.Drawing.Size(65, 24);
            this.авторToolStripMenuItem.Text = "Автор";
            this.авторToolStripMenuItem.Click += new System.EventHandler(this.авторToolStripMenuItem_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 57);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(96, 17);
            this.label1.TabIndex = 6;
            this.label1.Text = "Введите имя:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(385, 49);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 17);
            this.label2.TabIndex = 7;
            this.label2.Text = "label2";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(335, 122);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 17);
            this.label3.TabIndex = 8;
            this.label3.Text = "label3";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(10, 78);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(197, 22);
            this.textBox1.TabIndex = 9;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(213, 49);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(116, 87);
            this.button1.TabIndex = 10;
            this.button1.Text = "Вход";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Client
            // 
            this.AcceptButton = this.btn_SendMessage;
            this.AutoScaleBaseSize = new System.Drawing.Size(6, 15);
            this.ClientSize = new System.Drawing.Size(600, 522);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pnl_MessageHistory);
            this.Controls.Add(this.pnl_SendMessage);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Client";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Client";
            this.Load += new System.EventHandler(this.Client_Load);
            this.pnl_SendMessage.ResumeLayout(false);
            this.pnl_SendMessage.PerformLayout();
            this.pnl_MessageHistory.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem менюToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem настройкиToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem выходToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem авторToolStripMenuItem;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
    }
}

