using System;

namespace std_eventDelegate
{
    class Program
    {
        delegate void showMsg(string msg);

        class Show
        {
            public event showMsg gate;

            public void call(int input)
            {
                if(input%2 == 0)
                {
                    this.gate("wow");
                }
            }
        }

        static void Main(string[] args)
        {
            Show test = new Show();
            test.gate += new showMsg(showMsg);
for (int i = 0; i < 50; i++)
            {
                test.call(i);
            }

void showMsg(string msg)
            {
                Console.WriteLine("짝수입니다.{0}",msg);
            }
        }
    }
}
