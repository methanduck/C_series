namespace Assignment_4
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
            this.Txtbox_input = new System.Windows.Forms.TextBox();
            this.TxtBox_bitInput = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Txtbox_deciOrigin = new System.Windows.Forms.TextBox();
            this.Txtbox_hexOrigin = new System.Windows.Forms.TextBox();
            this.Txtbox_binOrigin = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.Txtbox_deciRes = new System.Windows.Forms.TextBox();
            this.Txtbox_hexRes = new System.Windows.Forms.TextBox();
            this.Txtbox_binRes = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.Btn_Lshift = new System.Windows.Forms.Button();
            this.Btn_Rshift = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // Txtbox_input
            // 
            this.Txtbox_input.Location = new System.Drawing.Point(321, 8);
            this.Txtbox_input.Name = "Txtbox_input";
            this.Txtbox_input.Size = new System.Drawing.Size(100, 21);
            this.Txtbox_input.TabIndex = 0;
            // 
            // TxtBox_bitInput
            // 
            this.TxtBox_bitInput.Location = new System.Drawing.Point(494, 8);
            this.TxtBox_bitInput.Name = "TxtBox_bitInput";
            this.TxtBox_bitInput.Size = new System.Drawing.Size(100, 21);
            this.TxtBox_bitInput.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("굴림", 12F);
            this.label1.Location = new System.Drawing.Point(254, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 16);
            this.label1.TabIndex = 2;
            this.label1.Text = "원래 수";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("굴림", 12F);
            this.label2.Location = new System.Drawing.Point(427, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "몇 비트";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Txtbox_deciOrigin);
            this.groupBox1.Controls.Add(this.Txtbox_hexOrigin);
            this.groupBox1.Controls.Add(this.Txtbox_binOrigin);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Font = new System.Drawing.Font("굴림", 13F);
            this.groupBox1.Location = new System.Drawing.Point(241, 197);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(247, 186);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "원래 수";
            // 
            // Txtbox_deciOrigin
            // 
            this.Txtbox_deciOrigin.Location = new System.Drawing.Point(113, 142);
            this.Txtbox_deciOrigin.Name = "Txtbox_deciOrigin";
            this.Txtbox_deciOrigin.Size = new System.Drawing.Size(100, 27);
            this.Txtbox_deciOrigin.TabIndex = 5;
            // 
            // Txtbox_hexOrigin
            // 
            this.Txtbox_hexOrigin.Location = new System.Drawing.Point(113, 78);
            this.Txtbox_hexOrigin.Name = "Txtbox_hexOrigin";
            this.Txtbox_hexOrigin.Size = new System.Drawing.Size(100, 27);
            this.Txtbox_hexOrigin.TabIndex = 4;
            // 
            // Txtbox_binOrigin
            // 
            this.Txtbox_binOrigin.Location = new System.Drawing.Point(113, 33);
            this.Txtbox_binOrigin.Name = "Txtbox_binOrigin";
            this.Txtbox_binOrigin.Size = new System.Drawing.Size(100, 27);
            this.Txtbox_binOrigin.TabIndex = 3;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(39, 151);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(62, 18);
            this.label5.TabIndex = 2;
            this.label5.Text = "십진수";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(39, 87);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(64, 18);
            this.label4.TabIndex = 1;
            this.label4.Text = "16진수";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(39, 42);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(62, 18);
            this.label3.TabIndex = 0;
            this.label3.Text = "이진수";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.Txtbox_deciRes);
            this.groupBox2.Controls.Add(this.Txtbox_hexRes);
            this.groupBox2.Controls.Add(this.Txtbox_binRes);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Font = new System.Drawing.Font("굴림", 13F);
            this.groupBox2.Location = new System.Drawing.Point(494, 197);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(247, 186);
            this.groupBox2.TabIndex = 6;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "결과";
            // 
            // Txtbox_deciRes
            // 
            this.Txtbox_deciRes.Location = new System.Drawing.Point(113, 142);
            this.Txtbox_deciRes.Name = "Txtbox_deciRes";
            this.Txtbox_deciRes.Size = new System.Drawing.Size(100, 27);
            this.Txtbox_deciRes.TabIndex = 5;
            // 
            // Txtbox_hexRes
            // 
            this.Txtbox_hexRes.Location = new System.Drawing.Point(113, 78);
            this.Txtbox_hexRes.Name = "Txtbox_hexRes";
            this.Txtbox_hexRes.Size = new System.Drawing.Size(100, 27);
            this.Txtbox_hexRes.TabIndex = 4;
            // 
            // Txtbox_binRes
            // 
            this.Txtbox_binRes.Location = new System.Drawing.Point(113, 33);
            this.Txtbox_binRes.Name = "Txtbox_binRes";
            this.Txtbox_binRes.Size = new System.Drawing.Size(100, 27);
            this.Txtbox_binRes.TabIndex = 3;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(39, 151);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(62, 18);
            this.label6.TabIndex = 2;
            this.label6.Text = "십진수";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(39, 87);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(64, 18);
            this.label7.TabIndex = 1;
            this.label7.Text = "16진수";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(39, 42);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(62, 18);
            this.label8.TabIndex = 0;
            this.label8.Text = "이진수";
            // 
            // Btn_Lshift
            // 
            this.Btn_Lshift.Location = new System.Drawing.Point(607, 8);
            this.Btn_Lshift.Name = "Btn_Lshift";
            this.Btn_Lshift.Size = new System.Drawing.Size(75, 23);
            this.Btn_Lshift.TabIndex = 7;
            this.Btn_Lshift.Text = "<<";
            this.Btn_Lshift.UseVisualStyleBackColor = true;
            this.Btn_Lshift.Click += new System.EventHandler(this.Btn_Lshift_Click);
            // 
            // Btn_Rshift
            // 
            this.Btn_Rshift.Location = new System.Drawing.Point(607, 37);
            this.Btn_Rshift.Name = "Btn_Rshift";
            this.Btn_Rshift.Size = new System.Drawing.Size(75, 23);
            this.Btn_Rshift.TabIndex = 8;
            this.Btn_Rshift.Text = ">>";
            this.Btn_Rshift.UseVisualStyleBackColor = true;
            this.Btn_Rshift.Click += new System.EventHandler(this.Btn_Rshift_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Btn_Rshift);
            this.Controls.Add(this.Btn_Lshift);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.TxtBox_bitInput);
            this.Controls.Add(this.Txtbox_input);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Txtbox_input;
        private System.Windows.Forms.TextBox TxtBox_bitInput;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox Txtbox_deciOrigin;
        private System.Windows.Forms.TextBox Txtbox_hexOrigin;
        private System.Windows.Forms.TextBox Txtbox_binOrigin;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox Txtbox_deciRes;
        private System.Windows.Forms.TextBox Txtbox_hexRes;
        private System.Windows.Forms.TextBox Txtbox_binRes;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button Btn_Lshift;
        private System.Windows.Forms.Button Btn_Rshift;
    }
}

