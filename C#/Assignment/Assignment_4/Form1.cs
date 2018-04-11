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
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Btn_Lshift_Click(object sender, EventArgs e)
        {
            
            DialogResult res = MessageBox.Show(Txtbox_input.Text + "을" + TxtBox_bitInput.Text + "만큼 비트이동합니다","안내", MessageBoxButtons.OKCancel);
            if(res == DialogResult.OK)
            {
               var tmp = Convert. .Parse(TxtBox_bitInput.Text.ToString()) << byte.Parse(Txtbox_input.Text.ToString());
                Txtbox_binOrigin.Text = Convert.ToString(tmp, 2);
                Txtbox_hexOrigin.Text = Convert.ToString(tmp, 16);
                Txtbox_deciOrigin.Text = Convert.ToString(tmp, 10);
            }
            
        }

        private void Btn_Rshift_Click(object sender, EventArgs e)
        {

        }
    }
}
