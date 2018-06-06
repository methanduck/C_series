using System;

namespace Assignment_11_4
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Action<int, int> myfunc = (a, b) =>
        {
            int result = a / b;
            Console.WriteLine("10/2 == {0}", result);
        };
            myfunc(10, 2);
        }
    }
}
