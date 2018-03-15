namespace Assignment
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.mkAll = new System.Windows.Forms.Button();
            this.mkSep = new System.Windows.Forms.Button();
            this.mkbtn = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // mkAll
            // 
            this.mkAll.Location = new System.Drawing.Point(12, 12);
            this.mkAll.Name = "mkAll";
            this.mkAll.Size = new System.Drawing.Size(75, 23);
            this.mkAll.TabIndex = 0;
            this.mkAll.Text = "한방에";
            this.mkAll.UseVisualStyleBackColor = true;
            this.mkAll.Click += new System.EventHandler(this.button1_Click);
            // 
            // mkSep
            // 
            this.mkSep.Location = new System.Drawing.Point(178, 12);
            this.mkSep.Name = "mkSep";
            this.mkSep.Size = new System.Drawing.Size(75, 23);
            this.mkSep.TabIndex = 1;
            this.mkSep.Text = "하나씩";
            this.mkSep.UseVisualStyleBackColor = true;
            this.mkSep.Click += new System.EventHandler(this.mkSep_Click);
            // 
            // mkbtn
            // 
            this.mkbtn.Location = new System.Drawing.Point(352, 11);
            this.mkbtn.Name = "mkbtn";
            this.mkbtn.Size = new System.Drawing.Size(75, 23);
            this.mkbtn.TabIndex = 2;
            this.mkbtn.Text = "뉴버튼클릭";
            this.mkbtn.UseVisualStyleBackColor = true;
            this.mkbtn.Click += new System.EventHandler(this.mkbtn_Click);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.mkbtn);
            this.Controls.Add(this.mkAll);
            this.Controls.Add(this.mkSep);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button mkAll;
        private System.Windows.Forms.Button mkSep;
        private System.Windows.Forms.Button mkbtn;
        private System.Windows.Forms.Timer timer1;
    }
}

