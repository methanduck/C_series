using System;

namespace std_delegateAnonymous
{
    class Program
    {
        delegate int tmp(int a, int b);
        static void Main(string[] args)
        {
            tmp calc = delegate (int a, int b){

                return a + b;
            };

            Console.WriteLine(calc(0, 1));
        }
    }
}
