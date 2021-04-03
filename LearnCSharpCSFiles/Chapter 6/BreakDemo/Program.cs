using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BreakDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            
            for (i = 0; i < 5; i++)
            {
                Console.WriteLine("i = {0}", i);
                if (i == 2)
                    break;
            }

            Console.Read();
        }
    }
}
