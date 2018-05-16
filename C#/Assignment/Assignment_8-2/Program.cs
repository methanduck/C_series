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
            int input;
            Stack<int> stk = new Stack<int>();
            stk.Push(1);
            stk.Push(2);
            stk.Push(3);
            Console.WriteLine("1,2,3푸쉬 완료");
            Console.WriteLine("스택 팝 >> {0}", stk.Pop());
            Console.WriteLine("스택 팝 >> {0}", stk.Pop());
            stk.Push(7);
            Console.WriteLine("스택 푸쉬 7");
            Console.WriteLine("스택에 푸쉬할 값 입력");
            input = int.Parse(Console.ReadLine());
            stk.Push(input);
            Console.WriteLine("스택에 푸쉬 완료");
            Console.WriteLine("---------------");
            IEnumerator iterator = stk.GetEnumerator();
            while(iterator.MoveNext())
            {
                object i = iterator.Current;
                Console.WriteLine(i);
            }
            
        }
        
    }
}
