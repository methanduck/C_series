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
            this.MkAll = new System.Windows.Forms.Button();
            this.MkOne = new System.Windows.Forms.Button();
            this.MkSeperate = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // MkAll
            // 
            this.MkAll.Location = new System.Drawing.Point(12, 12);
            this.MkAll.Name = "MkAll";
            this.MkAll.Size = new System.Drawing.Size(75, 23);
            this.MkAll.TabIndex = 0;
            this.MkAll.Text = "한방에";
            this.MkAll.UseVisualStyleBackColor = true;
            this.MkAll.Click += new System.EventHandler(this.MkAll_Click);
            // 
            // MkOne
            // 
            this.MkOne.Location = new System.Drawing.Point(178, 12);
            this.MkOne.Name = "MkOne";
            this.MkOne.Size = new System.Drawing.Size(75, 23);
            this.MkOne.TabIndex = 1;
            this.MkOne.Text = "하나씩";
            this.MkOne.UseVisualStyleBackColor = true;
            this.MkOne.Click += new System.EventHandler(this.MkOne_Click);
            // 
            // MkSeperate
            // 
            this.MkSeperate.Location = new System.Drawing.Point(352, 11);
            this.MkSeperate.Name = "MkSeperate";
            this.MkSeperate.Size = new System.Drawing.Size(75, 23);
            this.MkSeperate.TabIndex = 2;
            this.MkSeperate.Text = "뉴버튼클릭";
            this.MkSeperate.UseVisualStyleBackColor = true;
            this.MkSeperate.Click += new System.EventHandler(this.MkSeperate_Click);
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
            this.Controls.Add(this.MkSeperate);
            this.Controls.Add(this.MkAll);
            this.Controls.Add(this.MkOne);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button MkAll;
        private System.Windows.Forms.Button MkOne;
        private System.Windows.Forms.Button MkSeperate;
        private System.Windows.Forms.Timer timer1;
    }
}

