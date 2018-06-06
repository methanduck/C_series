using System;

namespace Assignment_11
{
    delegate int MyDivide(int a, int b);
    class Program
    {
        static void Main(string[] args)
        {
            MyDivide myfunc = delegate(int a, int b) {

                if(b == 0)
                {
                    return 0;
                }
                return a / b;
            };
            Console.WriteLine("10/2 == {0}",myfunc(10,2));
            Console.WriteLine("10/0 == {0}",myfunc(10,0));
        }
    }
}
