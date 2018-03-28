namespace Assignment_3
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
            this.Txt_input = new System.Windows.Forms.TextBox();
            this.Txt_show = new System.Windows.Forms.TextBox();
            this.Btn_CE = new System.Windows.Forms.Button();
            this.Btn_C = new System.Windows.Forms.Button();
            this.Num_7 = new System.Windows.Forms.Button();
            this.Num_8 = new System.Windows.Forms.Button();
            this.Num_9 = new System.Windows.Forms.Button();
            this.Num_4 = new System.Windows.Forms.Button();
            this.Num_5 = new System.Windows.Forms.Button();
            this.Num_6 = new System.Windows.Forms.Button();
            this.Num_1 = new System.Windows.Forms.Button();
            this.Num_2 = new System.Windows.Forms.Button();
            this.Num_3 = new System.Windows.Forms.Button();
            this.Num_0 = new System.Windows.Forms.Button();
            this.Btn_dot = new System.Windows.Forms.Button();
            this.Btn_div = new System.Windows.Forms.Button();
            this.Btn_mul = new System.Windows.Forms.Button();
            this.Btn_sub = new System.Windows.Forms.Button();
            this.Btn_plus = new System.Windows.Forms.Button();
            this.Btn_div1 = new System.Windows.Forms.Button();
            this.Btn_res = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Txt_input
            // 
            this.Txt_input.Location = new System.Drawing.Point(12, 12);
            this.Txt_input.Multiline = true;
            this.Txt_input.Name = "Txt_input";
            this.Txt_input.Size = new System.Drawing.Size(406, 40);
            this.Txt_input.TabIndex = 0;
            this.Txt_input.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Txt_show
            // 
            this.Txt_show.Location = new System.Drawing.Point(12, 58);
            this.Txt_show.Multiline = true;
            this.Txt_show.Name = "Txt_show";
            this.Txt_show.Size = new System.Drawing.Size(406, 41);
            this.Txt_show.TabIndex = 1;
            this.Txt_show.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // Btn_CE
            // 
            this.Btn_CE.Location = new System.Drawing.Point(12, 120);
            this.Btn_CE.Name = "Btn_CE";
            this.Btn_CE.Size = new System.Drawing.Size(77, 26);
            this.Btn_CE.TabIndex = 2;
            this.Btn_CE.Text = "CE";
            this.Btn_CE.UseVisualStyleBackColor = true;
            this.Btn_CE.Click += new System.EventHandler(this.Btn_CE_Click);
            // 
            // Btn_C
            // 
            this.Btn_C.Location = new System.Drawing.Point(95, 120);
            this.Btn_C.Name = "Btn_C";
            this.Btn_C.Size = new System.Drawing.Size(77, 26);
            this.Btn_C.TabIndex = 3;
            this.Btn_C.Text = "C";
            this.Btn_C.UseVisualStyleBackColor = true;
            this.Btn_C.Click += new System.EventHandler(this.Btn_C_Click);
            // 
            // Num_7
            // 
            this.Num_7.Location = new System.Drawing.Point(12, 149);
            this.Num_7.Name = "Num_7";
            this.Num_7.Size = new System.Drawing.Size(77, 26);
            this.Num_7.TabIndex = 4;
            this.Num_7.Text = "7";
            this.Num_7.UseVisualStyleBackColor = true;
            this.Num_7.Click += new System.EventHandler(this.Num_7_Click);
            // 
            // Num_8
            // 
            this.Num_8.Location = new System.Drawing.Point(95, 149);
            this.Num_8.Name = "Num_8";
            this.Num_8.Size = new System.Drawing.Size(77, 26);
            this.Num_8.TabIndex = 5;
            this.Num_8.Text = "8";
            this.Num_8.UseVisualStyleBackColor = true;
            this.Num_8.Click += new System.EventHandler(this.Num_8_Click);
            // 
            // Num_9
            // 
            this.Num_9.Location = new System.Drawing.Point(178, 149);
            this.Num_9.Name = "Num_9";
            this.Num_9.Size = new System.Drawing.Size(77, 26);
            this.Num_9.TabIndex = 6;
            this.Num_9.Text = "9";
            this.Num_9.UseVisualStyleBackColor = true;
            this.Num_9.Click += new System.EventHandler(this.Num_9_Click);
            // 
            // Num_4
            // 
            this.Num_4.Location = new System.Drawing.Point(12, 181);
            this.Num_4.Name = "Num_4";
            this.Num_4.Size = new System.Drawing.Size(77, 26);
            this.Num_4.TabIndex = 7;
            this.Num_4.Text = "4";
            this.Num_4.UseVisualStyleBackColor = true;
            this.Num_4.Click += new System.EventHandler(this.Num_4_Click);
            // 
            // Num_5
            // 
            this.Num_5.Location = new System.Drawing.Point(95, 181);
            this.Num_5.Name = "Num_5";
            this.Num_5.Size = new System.Drawing.Size(77, 26);
            this.Num_5.TabIndex = 8;
            this.Num_5.Text = "5";
            this.Num_5.UseVisualStyleBackColor = true;
            this.Num_5.Click += new System.EventHandler(this.Num_5_Click);
            // 
            // Num_6
            // 
            this.Num_6.Location = new System.Drawing.Point(178, 181);
            this.Num_6.Name = "Num_6";
            this.Num_6.Size = new System.Drawing.Size(77, 26);
            this.Num_6.TabIndex = 9;
            this.Num_6.Text = "6";
            this.Num_6.UseVisualStyleBackColor = true;
            this.Num_6.Click += new System.EventHandler(this.Num_6_Click);
            // 
            // Num_1
            // 
            this.Num_1.Location = new System.Drawing.Point(12, 213);
            this.Num_1.Name = "Num_1";
            this.Num_1.Size = new System.Drawing.Size(77, 26);
            this.Num_1.TabIndex = 10;
            this.Num_1.Text = "1";
            this.Num_1.UseVisualStyleBackColor = true;
            this.Num_1.Click += new System.EventHandler(this.Num_1_Click);
            // 
            // Num_2
            // 
            this.Num_2.Location = new System.Drawing.Point(95, 213);
            this.Num_2.Name = "Num_2";
            this.Num_2.Size = new System.Drawing.Size(77, 26);
            this.Num_2.TabIndex = 11;
            this.Num_2.Text = "2";
            this.Num_2.UseVisualStyleBackColor = true;
            this.Num_2.Click += new System.EventHandler(this.Num_2_Click);
            // 
            // Num_3
            // 
            this.Num_3.Location = new System.Drawing.Point(178, 213);
            this.Num_3.Name = "Num_3";
            this.Num_3.Size = new System.Drawing.Size(77, 26);
            this.Num_3.TabIndex = 12;
            this.Num_3.Text = "3";
            this.Num_3.UseVisualStyleBackColor = true;
            this.Num_3.Click += new System.EventHandler(this.Num_3_Click);
            // 
            // Num_0
            // 
            this.Num_0.Location = new System.Drawing.Point(12, 245);
            this.Num_0.Name = "Num_0";
            this.Num_0.Size = new System.Drawing.Size(160, 26);
            this.Num_0.TabIndex = 13;
            this.Num_0.Text = "0";
            this.Num_0.UseVisualStyleBackColor = true;
            this.Num_0.Click += new System.EventHandler(this.Num_0_Click);
            // 
            // Btn_dot
            // 
            this.Btn_dot.Location = new System.Drawing.Point(178, 245);
            this.Btn_dot.Name = "Btn_dot";
            this.Btn_dot.Size = new System.Drawing.Size(77, 26);
            this.Btn_dot.TabIndex = 14;
            this.Btn_dot.Text = ".";
            this.Btn_dot.UseVisualStyleBackColor = true;
            this.Btn_dot.Click += new System.EventHandler(this.Btn_dot_Click);
            // 
            // Btn_div
            // 
            this.Btn_div.Location = new System.Drawing.Point(258, 149);
            this.Btn_div.Name = "Btn_div";
            this.Btn_div.Size = new System.Drawing.Size(77, 26);
            this.Btn_div.TabIndex = 15;
            this.Btn_div.Text = "/";
            this.Btn_div.UseVisualStyleBackColor = true;
            this.Btn_div.Click += new System.EventHandler(this.Btn_div_Click);
            // 
            // Btn_mul
            // 
            this.Btn_mul.Location = new System.Drawing.Point(258, 181);
            this.Btn_mul.Name = "Btn_mul";
            this.Btn_mul.Size = new System.Drawing.Size(77, 26);
            this.Btn_mul.TabIndex = 16;
            this.Btn_mul.Text = "*";
            this.Btn_mul.UseVisualStyleBackColor = true;
            this.Btn_mul.Click += new System.EventHandler(this.Btn_mul_Click);
            // 
            // Btn_sub
            // 
            this.Btn_sub.Location = new System.Drawing.Point(258, 213);
            this.Btn_sub.Name = "Btn_sub";
            this.Btn_sub.Size = new System.Drawing.Size(77, 26);
            this.Btn_sub.TabIndex = 17;
            this.Btn_sub.Text = "-";
            this.Btn_sub.UseVisualStyleBackColor = true;
            this.Btn_sub.Click += new System.EventHandler(this.Btn_sub_Click);
            // 
            // Btn_plus
            // 
            this.Btn_plus.Location = new System.Drawing.Point(258, 245);
            this.Btn_plus.Name = "Btn_plus";
            this.Btn_plus.Size = new System.Drawing.Size(77, 26);
            this.Btn_plus.TabIndex = 18;
            this.Btn_plus.Text = "+";
            this.Btn_plus.UseVisualStyleBackColor = true;
            this.Btn_plus.Click += new System.EventHandler(this.Btn_plus_Click);
            // 
            // Btn_div1
            // 
            this.Btn_div1.Location = new System.Drawing.Point(341, 181);
            this.Btn_div1.Name = "Btn_div1";
            this.Btn_div1.Size = new System.Drawing.Size(77, 26);
            this.Btn_div1.TabIndex = 19;
            this.Btn_div1.Text = "1/x";
            this.Btn_div1.UseVisualStyleBackColor = true;
            this.Btn_div1.Click += new System.EventHandler(this.Btn_div1_Click);
            // 
            // Btn_res
            // 
            this.Btn_res.Location = new System.Drawing.Point(341, 213);
            this.Btn_res.Name = "Btn_res";
            this.Btn_res.Size = new System.Drawing.Size(77, 58);
            this.Btn_res.TabIndex = 20;
            this.Btn_res.Text = "=";
            this.Btn_res.UseVisualStyleBackColor = true;
            this.Btn_res.Click += new System.EventHandler(this.Btn_res_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(427, 294);
            this.Controls.Add(this.Btn_res);
            this.Controls.Add(this.Btn_div1);
            this.Controls.Add(this.Btn_plus);
            this.Controls.Add(this.Btn_sub);
            this.Controls.Add(this.Btn_mul);
            this.Controls.Add(this.Btn_div);
            this.Controls.Add(this.Btn_dot);
            this.Controls.Add(this.Num_0);
            this.Controls.Add(this.Num_3);
            this.Controls.Add(this.Num_2);
            this.Controls.Add(this.Num_1);
            this.Controls.Add(this.Num_6);
            this.Controls.Add(this.Num_5);
            this.Controls.Add(this.Num_4);
            this.Controls.Add(this.Num_9);
            this.Controls.Add(this.Num_8);
            this.Controls.Add(this.Num_7);
            this.Controls.Add(this.Btn_C);
            this.Controls.Add(this.Btn_CE);
            this.Controls.Add(this.Txt_show);
            this.Controls.Add(this.Txt_input);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Txt_input;
        private System.Windows.Forms.TextBox Txt_show;
        private System.Windows.Forms.Button Btn_CE;
        private System.Windows.Forms.Button Btn_C;
        private System.Windows.Forms.Button Num_7;
        private System.Windows.Forms.Button Num_8;
        private System.Windows.Forms.Button Num_9;
        private System.Windows.Forms.Button Num_4;
        private System.Windows.Forms.Button Num_5;
        private System.Windows.Forms.Button Num_6;
        private System.Windows.Forms.Button Num_1;
        private System.Windows.Forms.Button Num_2;
        private System.Windows.Forms.Button Num_3;
        private System.Windows.Forms.Button Num_0;
        private System.Windows.Forms.Button Btn_dot;
        private System.Windows.Forms.Button Btn_div;
        private System.Windows.Forms.Button Btn_mul;
        private System.Windows.Forms.Button Btn_sub;
        private System.Windows.Forms.Button Btn_plus;
        private System.Windows.Forms.Button Btn_div1;
        private System.Windows.Forms.Button Btn_res;
    }
}

