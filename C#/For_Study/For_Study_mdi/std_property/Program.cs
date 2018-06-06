using System;

namespace std_property
{
    class Program
    {

        abstract class abs
        {
            public int data
            {
                get; set;
            }
            public abstract void showdata();
        }


        class tmp : abs
        {
            private testInterface Inter;
            public tmp(testInterface input)
            {
                this.Inter = input;
            }
            public override void showdata()
            {
                Console.WriteLine(this.data + "extends");
                this.Inter.showData();
            }

        }


        class impleted : testInterface
        {
            public int inte { get; set; }
            public string str { get; set; }

            public void showData()
            {
                this.inte = 3;
                this.str = "welcome";
                Console.WriteLine(this.inte + this.str);
            }
        }


        static void Main(string[] args)
        {
            tmp test = new tmp(new impleted());
            test.showdata();
        }
    }
}
