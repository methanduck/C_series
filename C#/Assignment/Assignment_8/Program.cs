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
        class Mylist : IEnumerable, IEnumerator
        {
            private int[] array;
            int position = -1;

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

            public object Current
            {
                get { return array[position]; }
            }
            public IEnumerator GetEnumerator()
            {
               foreach(int i in array)
                {
                    yield return (array[i]);
                }
            }

            public bool MoveNext()
            {
               if(position == array.Length -1)
                {
                    Reset();
                    return false;
                }
                position++;
                return (position < array.Length);
            }

            public void Reset()
            {
                position = -1;
            }
        }
        static void Main(string[] args)
        {
            Mylist list = new Mylist();
            for (int i = 0; i < 5; i++)
            {
                list[i] = i;
            }

            foreach(int i in list)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();
        }
    }
}
