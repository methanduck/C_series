using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_8_2
{
    
    class Program 
    {
        
        static void Main(string[] args)
        {
            Stack<int> stk = new Stack<int>();
            stk.Push(1);
            stk.Push(2);
            stk.Push(3);

            IEnumerator iterator = stk.GetEnumerator();
            while(iterator.MoveNext())
            {
                object i = iterator.Current;
                Console.WriteLine(i);
            }
            
        }
        
    }
}
