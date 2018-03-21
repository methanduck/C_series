using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_2
{
    public partial class New_Window : Form
    {
        Main_Window main ;
        class CustomForm : Form
        {
           public CustomForm(Main_Window input)
            {
                input.setCount_plus();
                Button Btn_Mkform = new Button();
                Btn_Mkform.Text = input.getCount()+"번째입니다.";
                Btn_Mkform.Click += new System.EventHandler(this.Btn_Click);
                Btn_Mkform.Width = 150;
                this.Controls.Add(Btn_Mkform);
                input.addStack(this);
            }
                
            private void Btn_Click(object sender, EventArgs e)
            {
                MessageBox.Show("마지막 폼의 버튼입니다.", "다중 폼 테스트", MessageBoxButtons.OK);
            }
        }
        public New_Window(Main_Window input)
        {
            main = input;
            InitializeComponent();
            main.addStack(this);
            Btn_New.Text = main.getCount() + "번째 입니다.";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            main.setCount_plus();
            CustomForm New_Window2 = new CustomForm(main);
            New_Window2.Show();
        }
        
    }
}
