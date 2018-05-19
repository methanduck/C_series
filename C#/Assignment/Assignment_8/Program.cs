using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_8
{
    class Program
    {
        class Mylist 
        {
            private int[] array;

            public Mylist()
            {
                array = new int[3];
            }

            public int this[int index]
            {
                get
                {
                    return array[index];
                }
                set
                {
                    if(index >= array.Length)
                    {
                        Array.Resize<int>(ref array, index + 1);
                        Console.WriteLine("Array Resized : {0}", array.Length);
                    }
                    array[index] = value;
                }
            }

            public IEnumerator GetEnumerator()
            {
               foreach(int i in array)
                {
                    yield return (array[i]);
                }
            }

        }
        static void Main(string[] args)
        {
            Mylist list = new Mylist();
            IEnumerator iterator = list.GetEnumerator();
            for (int i = 0; i < 5; i++)
            {
                list[i] = i;
            }
            while (iterator.MoveNext())
            {
                Console.WriteLine(iterator.Current);
            }
        }
    }
}
