using System;

namespace std_delegateChain
{
    delegate void chain(string msg);

    class Noti
    {
        public chain notifier;
    }

    class EventHandler
    {
        private string name;
        public EventHandler(string name)
        {
            this.name = name;
        }
        public void SomethingHappend(string msg)
        {
            Console.WriteLine("{0}something happend!",msg);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Noti noti = new Noti();

            EventHandler a = new EventHandler("a");
            EventHandler b = new EventHandler("b");

            noti.notifier += a.SomethingHappend;
            noti.notifier("wow");
            noti.notifier += b.SomethingHappend;
            noti.notifier("omg");

        }
    }
}
