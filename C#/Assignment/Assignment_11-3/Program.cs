using System;

namespace Assignment_11_3
{
    class Program
    {
        static void Main(string[] args)
        {
            Func<int,int, int> myfunc = (a,b) => a / b;

            Console.WriteLine("10/2 == {0}", myfunc(10, 2));
        }
    }
}
