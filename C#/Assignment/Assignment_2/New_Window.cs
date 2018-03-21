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
            New_Window New_Win = new New_Window(main);
            
            New_Win.Show();
        }
    }
}
