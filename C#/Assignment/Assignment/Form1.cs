using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment
{
    public partial class Form1 : Form
    {
        int tmp_location =1 ;
        int tmp_location2 = 1;
        int elapsed=0;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 1; i < 5; i++)
            {
                Button child = new Button();
                Controls.Add(child);
                child.Location = new Point(mkAll.Location.X,mkAll.Location.Y+(23+3)*i);
                child.Text = "동적생성" + i + "번째";
                child.Width = 100;
            }
            
        }

        private void mkSep_Click(object sender, EventArgs e)
        {
            Button child = new Button();
            Controls.Add(child);
            if(tmp_location == 1)
            {
                child.Location = new Point(mkSep.Location.X, mkSep.Location.Y + (23 + 3));
                child.Text = "동적생성" + tmp_location +"번째";
                child.Width = 100;
                tmp_location++;
            }
            else
            {
                
                child.Location = new Point(mkSep.Location.X, mkSep.Location.Y + (23 + 3) * tmp_location);
                child.Text = "동적생성" + tmp_location + "번째";
                child.Width = 100;
                tmp_location++;
            }
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void mkbtn_Click(object sender, EventArgs e)
        {
            Button child = new Button();
            Controls.Add(child);
            child.Width = 100;
            if(tmp_location2 == 1)
            {
                child.Location = new Point(mkbtn.Location.X, mkbtn.Location.Y + (23 + 3));
                child.Text = "동적생성" + tmp_location2 + "번째";
                child.Click += mkbtn_Click;
                tmp_location2++;
            }
            else
            {
                child.Location = new Point(mkbtn.Location.X, mkbtn.Location.Y + (23 + 3)*tmp_location2);
                child.Text = "동적생성" + tmp_location2 + "번째";
                child.Click += mkbtn_Click;
                tmp_location2++;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            elapsed++;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
           
            MessageBox.Show("버튼지울까요", "", MessageBoxButtons.YesNo);
            Controls.Clear();
            MessageBox.Show("경과된 시간은" + elapsed + "초입니다.");
        }

        private static MessageBoxButtons GetYesNo()
        {
           
            return MessageBoxButtons.YesNo;
        }
    }
}
