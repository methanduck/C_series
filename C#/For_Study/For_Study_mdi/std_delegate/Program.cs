using System;

namespace std_delegate
{
    class Program
    {
        delegate int calc(int a, int b);
        static void Main(string[] args)
        {
            calc cal;
            cal = delegate (int input, int input2) {

                return input + input2;
            };

            Console.WriteLine(cal(3, 4));
        }
    }
}
