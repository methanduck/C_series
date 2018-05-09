using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_7_1
{
    class Program
    {
        abstract class AbstractDisplay
        {
            abstract public void open();
            abstract public void print();
            abstract public void close();
            public void display()
            {
                this.open();
                this.print();
                this.close();
            }
        }

        class CharDisplay : AbstractDisplay
        {
            private char data;
            public CharDisplay(char input)
            {
                this.data = input;
            }
            public override void open()
            {
                Console.Write("<<");
            }

            public override void print()
            {
                for (int i = 0; i < 5; i++)
                {
                    Console.Write("{0}", this.data);
                }
            }

            public override void close()
            {
                Console.WriteLine(">>");
            }
            
            
        }

        class StringDisplay : AbstractDisplay
        {
            private string data;
            private void printline() { Console.WriteLine(); }
            public StringDisplay(string input)
            {
                this.data = input;
            }
            public override void close()
            {
                Console.WriteLine("+-------------+");
            }

            public override void open()
            {
                Console.WriteLine("+-------------+");
            }

            public override void print()
            {
                for (int i = 0; i < 5; i++)
                {
                    Console.WriteLine("{0},{1},{2}", "|", this.data, "|");
                    this.printline();
                }
                    
            }
        }

        static void Main(string[] args)
        {
            AbstractDisplay d1 = new CharDisplay('H');
            AbstractDisplay d2 = new StringDisplay("hello world");

            d1.display();
            d2.display();
            Console.WriteLine();
        }
    }
}
