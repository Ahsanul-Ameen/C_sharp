using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EnumDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            DaysOfWeek myDays = DaysOfWeek.Mon;

            Console.WriteLine(myDays);
            Console.WriteLine((int)myDays);
            Console.WriteLine((DaysOfWeek)1);

            Console.Read();
        }
    }

    enum DaysOfWeek
    {
        Sun, Mon, Tues, Wed, Thurs, Fri, Sat
    }    

}
