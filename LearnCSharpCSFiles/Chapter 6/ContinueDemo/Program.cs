using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContinueDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("i = {0}", i);
                if (i == 2)
                    continue;
                Console.WriteLine("I will not be printed if i = 2.\n");
            }

            Console.Read();
        }
    }
}
