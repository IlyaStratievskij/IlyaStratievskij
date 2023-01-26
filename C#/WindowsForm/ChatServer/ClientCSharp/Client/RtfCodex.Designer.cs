
namespace Client
{
    partial class RtfCodes : System.Windows.Forms.Form
    {
        
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tbox_RtfCodes = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // tbox_RtfCodes
            // 
            this.tbox_RtfCodes.BackColor = System.Drawing.SystemColors.Window;
            this.tbox_RtfCodes.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tbox_RtfCodes.Location = new System.Drawing.Point(0, 0);
            this.tbox_RtfCodes.Multiline = true;
            this.tbox_RtfCodes.Name = "tbox_RtfCodes";
            this.tbox_RtfCodes.ReadOnly = true;
            this.tbox_RtfCodes.Size = new System.Drawing.Size(504, 149);
            this.tbox_RtfCodes.TabIndex = 0;
            this.tbox_RtfCodes.TextChanged += new System.EventHandler(this.tbox_RtfCodes_TextChanged);
            // 
            // RtfCodes
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(6, 15);
            this.ClientSize = new System.Drawing.Size(504, 149);
            this.ControlBox = false;
            this.Controls.Add(this.tbox_RtfCodes);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "RtfCodes";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Rtf Codes";
            this.Load += new System.EventHandler(this.RtfCodes_Load);
            this.ResumeLayout(false);
            this.PerformLayout();


        }

        #endregion
        private void tbox_RtfCodes_TextChanged(object sender) {}

        private void RtfCodes_Load(object sender) {}
  
    }
}