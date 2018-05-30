using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_10_3
{
    public partial class Form1 : Form
    {
        delegate void MyDelegate();
        public Form1()
        {
            InitializeComponent();
            this.Click += new EventHandler(clickReceive);
        }
        private void clickReceive(object sender, EventArgs e)
        {
            MessageBox.Show("hello world");
        }
        public class EventFormTest
        {
            static void Main()
            {
                Application.Run(new Form1());
            }
        }
    }
}
