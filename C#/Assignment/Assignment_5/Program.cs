using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_5
{
    class Program
    {
        class Zookeeper
        {
            public Zookeeper()
            {
            }
            public void Wash(String input)
            {
                Console.WriteLine("{0}를 Wash 합니다.", input);
            }

        }

        class Mammal
        {
            protected String name;
            public Mammal(String input)
            {
                this.name = input;
            }

        }

        static void Main(string[] args)
        {
            dog dog = new dog("dog");
            cat cat = new cat("cat");
            elephant ele = new elephant("elephant");
            lion li = new lion("lion");
            Zookeeper human = new Zookeeper();

            human.Wash(dog.Getname());
            human.Wash(cat.GetName());
            human.Wash(ele.GetName());
            human.Wash(li.GetName());

            Console.WriteLine();
        }


        class dog : Mammal
        {
            public dog(String input) : base(input) { }
            public String Getname()
            {
                return this.name;
            }
        }
        class cat : Mammal
        {
            public cat(String input) : base(input) { }
            public String GetName()
            {
                return this.name;
            }
        }
        class elephant : Mammal
        {
            public elephant(String input) : base(input) { }
            public String GetName()
            {
                return this.name;
            }
        }
        class lion : Mammal
        {
            public lion(String input) : base(input) { }
            public String GetName()
            {
                return this.name;
            }
        }
    }
}
