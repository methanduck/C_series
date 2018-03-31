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
        float tmp_Num=0,tmp_newNum=0;
        string tmp_oper = string.Empty;
        bool Used = false, Ck_add = false , txt_Append = true; 
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Num_8_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(8);
        }

        private void Btn_plus_Click(object sender, EventArgs e)
        {
            this.btn_Opclick("+");
        }

        private void Num_1_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(1);
        }

        private void Btn_dot_Click(object sender, EventArgs e)
        {
            this.Txt_input.AppendText(".");
        }

        private void Num_3_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(3);
        }

        private void Btn_sub_Click(object sender, EventArgs e)
        {
            this.btn_Opclick("-");
        }

        private void Btn_res_Click(object sender, EventArgs e)
        {
            if(Used && (this.Txt_input.Text.Equals(string.Empty)||this.Txt_input.Text.Equals("0")))
            {
                Txt_input.Text = "피연산자 값이 부족합니다.";
            }
            else
            {
                tmp_newNum = float.Parse(this.Txt_input.Text);
             this.Mid_Calc(tmp_Num, tmp_newNum, this.Txt_show.Text);
            }
            this.tmp_newNum = 0;
             this.Txt_show.Text = "=";
        }

        private void Btn_mul_Click(object sender, EventArgs e)
        {
            this.btn_Opclick("*");
        }

        private void Num_6_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(6);
        }

        private void Btn_CE_Click(object sender, EventArgs e)
        {
            this.Txt_input.Text.TrimEnd();
        }

        private void Btn_C_Click(object sender, EventArgs e)
        {
            this.Txt_input.Text = "0";
            this.Txt_show.Text = "";
            this.tmp_newNum = 0;
            this.tmp_Num = 0;
            this.Used = false;
            this.Ck_add = false;
            this.txt_Append = true;
        }

        private void Num_7_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(7);
        }

        private void Num_9_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(9);
        }

        private void Btn_div_Click(object sender, EventArgs e)
        {
            this.btn_Opclick("/");
        }

        private void Num_4_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(4);
        }

        private void Num_5_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(5);
        }

        private void Btn_div1_Click(object sender, EventArgs e)
        {

        }

        private void Num_2_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(2);
        }

        private void Num_0_Click(object sender, EventArgs e)
        {
            this.btn_Numclick(0);
        }

        private void Mid_Calc(float input1,float input2,string param)
        {
            switch(param)
            {
                case "+":
                    this.tmp_Num= input1 + input2;
                    Txt_input.Text = Convert.ToString(this.tmp_Num);
                    break;
                case "-":
                    this.tmp_Num= input1 - input2;
                    Txt_input.Text = Convert.ToString(this.tmp_Num);
                    break;
                case "/":
                    if(input1 == 0)
                    {
                        Txt_input.Text = "0을 나눌 수 없습니다.";
                    }
                    else
                    {
                    this.tmp_Num= input1 / input2;
                        Txt_input.Text = Convert.ToString(this.tmp_Num);
                    }
                    break;
                case "*":
                    this.tmp_Num= input1 * input2;
                    Txt_input.Text = Convert.ToString(this.tmp_Num);
                    break;
            }
            Ck_add = true;
            txt_Append = true;
        }

        private void btn_Numclick(int Num)
        {
            if((Txt_input.Text.Equals("0") || Ck_add )&& txt_Append)
            {
                    this.Txt_input.Text = string.Empty;
                    this.Txt_input.Text = Convert.ToString(Num);
                    txt_Append = false;
                
            }
            else
            this.Txt_input.Text += Convert.ToString(Num);
        }

        private void btn_Opclick(string Operator)
        {
            if (Used == false)
            {
                tmp_Num = float.Parse(Txt_input.Text);
                Txt_show.Text = Operator;
                this.Txt_input.Text = Convert.ToString(0);
                this.tmp_oper = Operator;
                Used = true;
                txt_Append = true;
            }
            else
            {

                tmp_newNum = float.Parse(Txt_input.Text);
                    this.tmp_oper = this.Txt_show.Text;
                this.Mid_Calc(tmp_Num, tmp_newNum, this.tmp_oper);
                this.tmp_newNum = 0;
                Txt_show.Text = Operator;
            }
        }
    }
}
