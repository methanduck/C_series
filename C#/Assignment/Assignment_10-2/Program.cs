using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_10_2
{
     delegate void MyDelegate(int a);
        class Market
        {
            public event MyDelegate CustomerEvent;

            public void BuySomething(int CustomerNo)
            {
                if (CustomerNo == 30)
                {
                    CustomerEvent(CustomerNo);
                }
            }
        }
    class Program
    {
        static public void MyEvent(int a)
        {
            Console.WriteLine("축하합니다! {0}번째 고객 이벤트에 당첨되셨습니다.",a);
        }
        static void Main(string[] args)
        {
            Market market = new Market();
            market.CustomerEvent += new MyDelegate(MyEvent);
            for (int customerno = 0; customerno <= 100; customerno+=10)
            {
                market.BuySomething(customerno);
            }
            
        }
    }
    
}
