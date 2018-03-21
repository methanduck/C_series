namespace Assignment_2
{
    partial class Main_Window
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.폼생성ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.두번째폼열기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.폼제거ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.폼생성ToolStripMenuItem,
            this.폼제거ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 25);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 폼생성ToolStripMenuItem
            // 
            this.폼생성ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.두번째폼열기ToolStripMenuItem});
            this.폼생성ToolStripMenuItem.Name = "폼생성ToolStripMenuItem";
            this.폼생성ToolStripMenuItem.Size = new System.Drawing.Size(59, 21);
            this.폼생성ToolStripMenuItem.Text = "폼생성";
            // 
            // 두번째폼열기ToolStripMenuItem
            // 
            this.두번째폼열기ToolStripMenuItem.Name = "두번째폼열기ToolStripMenuItem";
            this.두번째폼열기ToolStripMenuItem.Size = new System.Drawing.Size(164, 22);
            this.두번째폼열기ToolStripMenuItem.Text = "두번째 폼 열기";
            this.두번째폼열기ToolStripMenuItem.Click += new System.EventHandler(this.두번째폼열기ToolStripMenuItem_Click);
            // 
            // 폼제거ToolStripMenuItem
            // 
            this.폼제거ToolStripMenuItem.Name = "폼제거ToolStripMenuItem";
            this.폼제거ToolStripMenuItem.Size = new System.Drawing.Size(59, 21);
            this.폼제거ToolStripMenuItem.Text = "폼제거";
            this.폼제거ToolStripMenuItem.Click += new System.EventHandler(this.폼제거ToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 폼생성ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 두번째폼열기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 폼제거ToolStripMenuItem;
    }
}

