using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_3
{
    public partial class Form1 : Form
    {
        float tmp_Num,tmp_newNum, res_Num;
        string tmp_arg;
        bool Used = false;
        bool Ck_add = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Num_8_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Used == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("8");
                }
                else
                    this.Txt_input.AppendText("8");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "8";
            }
        }

        private void Btn_plus_Click(object sender, EventArgs e)
        {
            if (Used == false)
            {
                tmp_Num = float.Parse(Txt_input.Text);
                Txt_show.Text += "+";
                Used = true;
                this.Txt_input.Text = "";
                this.tmp_arg = "+";
            }
            else
            {
                tmp_newNum = float.Parse(Txt_input.Text);
                this.Txt_input.Text = "";
                 this.tmp_Num = this.Mid_Calc(tmp_Num, tmp_newNum, this.tmp_arg);
                Txt_input.Text = Convert.ToString(this.tmp_Num);
                Txt_show.Text = "";
                Txt_show.Text += "+";
            }
        }

        private void Num_1_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {   if (Ck_add == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("1");
                    Ck_add = false;
                }
            else
                    this.Txt_input.AppendText("1");}
              
            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "1";
            }
        }

        private void Btn_dot_Click(object sender, EventArgs e)
        {
            this.Txt_input.AppendText(".");
        }

        private void Num_3_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Ck_add == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("3");
                    Ck_add = false;
                }
                else
                    this.Txt_input.AppendText("3");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "3";
            }
        }

        private void Btn_sub_Click(object sender, EventArgs e)
        {
            if (Used == false)
            {
                tmp_Num = float.Parse(Txt_input.Text);
                Txt_show.Text += "-";
                Used = true;
                this.Txt_input.Text = "";
                this.tmp_arg = "-";
            }
            else
            {
                tmp_newNum = float.Parse(Txt_input.Text);
                this.Txt_input.Text = "";
                this.tmp_Num = this.Mid_Calc(tmp_Num, tmp_newNum, this.tmp_arg);
                Txt_input.Text = Convert.ToString(this.tmp_Num);
                Txt_show.Text = "";
                Txt_show.Text += "-";
            }
        }

        private void Btn_res_Click(object sender, EventArgs e)
        {
                this.tmp_newNum = float.Parse(this.Txt_input.Text);
            this.Txt_input.Text = "";
            this.Txt_input.Text += this.Mid_Calc(tmp_Num, tmp_newNum, this.Txt_show.Text);
            this.Txt_show.Text += "=";
        }

        private void Btn_mul_Click(object sender, EventArgs e)
        {
            if (Used == false)
            {
                tmp_Num = float.Parse(Txt_input.Text);
                Txt_show.Text += "*";
                Used = true;
                this.Txt_input.Text = "";
                this.tmp_arg = "*";
            }
            else
            {
                tmp_newNum = float.Parse(Txt_input.Text);
                this.Txt_input.Text = "";
                this.tmp_Num = this.Mid_Calc(tmp_Num, tmp_newNum, this.tmp_arg);
                Txt_input.Text = Convert.ToString(this.tmp_Num);
                Txt_show.Text += "*";
                this.Txt_show.Text = "";
            }

        }

        private void Num_6_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Used == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("6");
                }
                else
                    this.Txt_input.AppendText("6");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "6";
            }
        }

        private void Btn_CE_Click(object sender, EventArgs e)
        {
            this.Txt_input.Text.TrimEnd();
        }

        private void Btn_C_Click(object sender, EventArgs e)
        {
            this.Txt_input.Text = "0";
            this.Txt_show.Text = "";
        }

        private void Num_7_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Used == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("7");
                }
                else
                    this.Txt_input.AppendText("7");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "7";
            }
        }

        private void Num_9_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Used == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("9");
                }
                else
                    this.Txt_input.AppendText("9");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "9";
            }
        }

        private void Btn_div_Click(object sender, EventArgs e)
        {

            if (Used == false)
            {
                tmp_Num = float.Parse(Txt_input.Text);
                Txt_show.Text += "/";
                Used = true;
                this.Txt_input.Text = "";
                this.tmp_arg = "/";
            }
            else
            {
                tmp_newNum = float.Parse(Txt_input.Text);
                this.Txt_input.Text = "";
                this.tmp_Num = this.Mid_Calc(tmp_Num, tmp_newNum, this.tmp_arg);
                Txt_input.Text = Convert.ToString(this.tmp_Num);
                this.Txt_show.Text = "";
                Txt_show.Text += "/";
            }


        }

        private void Num_4_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Used == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("4");
                }
                else
                    this.Txt_input.AppendText("4");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "4";
            }
        }

        private void Num_5_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Used == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("5");
                }
                else
                    this.Txt_input.AppendText("5");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "5";
            }
        }

        private void Btn_div1_Click(object sender, EventArgs e)
        {
            if(Used == false)
            {
                tmp_Num = float.Parse(Txt_input.Text);
                Txt_show.Text += "1/x";
                Txt_input.Text += 0;
                Used = true;
            }
            else
            {
            tmp_newNum = float.Parse(Txt_input.Text);
            Txt_input.Text+= this.tmp_Num = this.Mid_Calc(tmp_Num, tmp_newNum, "/");
            Txt_show.Text += "1/x";
            }
        }

        private void Num_2_Click(object sender, EventArgs e)
        {
            if (!Txt_input.Equals("0"))
            {
                if (Ck_add == true)
                {
                    this.Txt_input.Text = "";
                    this.Txt_input.AppendText("2");
                    Ck_add = false;
                }
                else
                    this.Txt_input.AppendText("2");
            }

            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "2";
            }
        }

        private void Num_0_Click(object sender, EventArgs e)
        {
            if (float.Parse(this.Txt_input.Text) > 0)
            {
                this.Txt_input.AppendText("0");
            }
            else
            {
                this.Txt_input.Text = "";
                this.Txt_input.Text += "0";
            }

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private float Mid_Calc(float input1,float input2,string param)
        {
            float result=0;
            switch(param)
            {
                case "+":
                    result= input1 + input2;
                    break;
                case "-":
                    result= input1 - input2;
                    break;
                case "/":
                    result= input1 / input2;
                    break;
                case "*":
                    result= input1 * input2;
                    break;
            }
            Ck_add = true;
            return result;
        }
    }
}
