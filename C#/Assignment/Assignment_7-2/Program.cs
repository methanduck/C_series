using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_7_2
{
    class Program
    {
        class NameCard
        {
            public int age { get; set;}
            public string name{get; set;}
        }
        static void Main(string[] args)
        {
            NameCard Mycard = new NameCard();

            Mycard.age = 24;
            Mycard.name = "상현";

            Console.WriteLine("나이 : {0}", Mycard.age);
            Console.WriteLine("이름 : {0}", Mycard.name);
        }
    }
}
