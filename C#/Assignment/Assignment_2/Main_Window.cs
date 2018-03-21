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
    
    public partial class Main_Window : Form
    {
         int count = 1;
        Stack<New_Window> Win_list = new Stack<New_Window>();
        public Main_Window()
        {
            InitializeComponent();
        }

        private void 두번째폼열기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            count++;
            
            New_Window Window_New = new New_Window(this);
            Win_list.Push(Window_New);
            Window_New.Show();
            
        }

        private void 폼제거ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Win_list.Count != 0)
            {
                New_Window del = Win_list.Pop();
                del.Close();
                del.Dispose();
            }
            else
                this.Close();
           
        }
        public int getCount()
        {
            return this.count;
        }
        public void setCount_plus()
        {
            this.count++;
        }
        public void addStack(New_Window input)
        {
            this.Win_list.Push(input);
        }
    }

}
