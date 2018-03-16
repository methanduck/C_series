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
        int Onebtn_Count =1 ;
        int Sepbtn_Count = 1;
        int elapsed=0;

        public Form1()
        {
            InitializeComponent();
        }

        private void MkAll_Click(object sender, EventArgs e)
        {
            for (int i = 1; i < 5; i++)
            {
                Button child = new Button();
                Controls.Add(child);
                child.Location = new Point(MkAll.Location.X,MkAll.Location.Y+(23+3)*i);
                child.Text = "동적생성" + i + "번째";
                child.Width = 100;
            }
            
        }

        private void MkOne_Click(object sender, EventArgs e)
        {
            Button child = new Button();
            Controls.Add(child);
            if(Onebtn_Count == 1)
            {
                child.Location = new Point(MkOne.Location.X, MkOne.Location.Y + (23 + 3));
                child.Text = "동적생성" + Onebtn_Count +"번째";
                child.Width = 100;
                Onebtn_Count++;
            }
            else
            {
                
                child.Location = new Point(MkOne.Location.X, MkOne.Location.Y + (23 + 3) * Onebtn_Count);
                child.Text = "동적생성" + Onebtn_Count + "번째";
                child.Width = 100;
                Onebtn_Count++;
            }
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void MkSeperate_Click(object sender, EventArgs e)
        {
            Button child = new Button();
            Controls.Add(child);
            child.Width = 100;
            if(Sepbtn_Count == 1)
            {
                child.Location = new Point(MkSeperate.Location.X, MkSeperate.Location.Y + (23 + 3));
                child.Text = "동적생성" + Sepbtn_Count + "번째";
                child.Click += MkSeperate_Click;
                Sepbtn_Count++;
            }
            else
            {
                child.Location = new Point(MkSeperate.Location.X, MkSeperate.Location.Y + (23 + 3)*Sepbtn_Count);
                child.Text = "동적생성" + Sepbtn_Count + "번째";
                child.Click += MkSeperate_Click;
                Sepbtn_Count++;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            elapsed++;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
           
            DialogResult result = MessageBox.Show("버튼지울까요", "", MessageBoxButtons.YesNo);
            if(result == DialogResult.Yes)
            {
                Controls.Clear();
            }
            
            MessageBox.Show("경과된 시간은" + elapsed + "초입니다.");
        }

        private static MessageBoxButtons GetYesNo()
        {
            return MessageBoxButtons.YesNo;
        }
    }
}
