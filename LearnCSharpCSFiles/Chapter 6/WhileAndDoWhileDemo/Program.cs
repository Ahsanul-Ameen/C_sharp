using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WhileAndDoWhileDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            //While Demo
            Console.WriteLine("WHILE DEMO\n");

            int counter = 5;

            while (counter > 0)
            {
                Console.WriteLine("Counter = {0}", counter);
                counter = counter-1;
            }

            //Do while Demo for Array
            Console.WriteLine("\n\nDOWHILE DEMO\n");

            counter = 100;

            do
            {

                Console.WriteLine("Counter = {0}", counter);
                counter++;

            } while (counter < 0);

            Console.Read();
        }
    }
}
