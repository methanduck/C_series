using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_4
{
    public partial class Form1 : Form
    {

        int temp, input_Num;
        public Form1()
        {
            InitializeComponent();
        }

        private void Btn_Lshift_Click(object sender, EventArgs e)
        {
            this.set_Result("<<");
        }

        private void Btn_Rshift_Click(object sender, EventArgs e)
        {
            this.set_Result(">>");
        }

        private void set_Result(string oper)
        {
            DialogResult res = MessageBox.Show(Txtbox_input.Text + "을" + TxtBox_bitInput.Text + "만큼"+oper+"비트이동합니다", "안내", MessageBoxButtons.OKCancel);
            if (res == DialogResult.OK)
            {
                input_Num = int.Parse(Txtbox_input.Text.ToString());
                if (oper.Equals("<<"))
                {
                    temp = int.Parse(Txtbox_input.Text.ToString()) << int.Parse(TxtBox_bitInput.Text.ToString());
                }
                else
                {
                    temp = int.Parse(Txtbox_input.Text.ToString()) >> int.Parse(TxtBox_bitInput.Text.ToString());
                }
                Txtbox_binOrigin.Text = Convert.ToString(input_Num, 2);
                Txtbox_deciOrigin.Text = Convert.ToString(input_Num, 10);
                Txtbox_hexOrigin.Text = Convert.ToString(input_Num, 16);
                Txtbox_binRes.Text = Convert.ToString(temp, 2);
                Txtbox_deciRes.Text = Convert.ToString(temp, 10);
                Txtbox_hexRes.Text = Convert.ToString(temp, 16);
            }
        }
    }
}
