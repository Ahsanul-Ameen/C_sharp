using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForAndForEachDemo
{
    class Program
    {
        static void Main(string[] args)
        {

            //For Demo
            Console.WriteLine("FOR DEMO\n");

            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine(i);
            }

            //For Demo for Array
            Console.WriteLine("\n\nFOR DEMO FOR ARRAY\n");

            int[] myNumbers = { 10, 20, 30, 40, 50 };

            for (int i = 0; i < myNumbers.Length; i++)
            {
                Console.WriteLine(myNumbers[i]);
            }

            //ForEach Demo
            Console.WriteLine("\n\nFOREACH DEMO\n");

            char[] message = { 'H', 'e', 'l', 'l', 'o' };

            foreach (char i in message)
                Console.Write(i);

            //Prevents window from closing
            Console.Read();

        }
    }
}
