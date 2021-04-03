using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExceptionDemo1
{
    class Program
    {
        static void Main(string[] args)
        {
            int numerator, denominator;

            Console.Write("Please enter the numerator: ");
            numerator = Convert.ToInt32(Console.ReadLine());

            Console.Write("Please enter the denominator: ");
            denominator = Convert.ToInt32(Console.ReadLine());

            try
            {
                Console.WriteLine("The result is {0}.", numerator / denominator);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("----End of Error Handling Example----");
            }

            Console.Read();
        }
    }
}
