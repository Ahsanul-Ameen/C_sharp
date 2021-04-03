using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticDemo
{
    class MyClass
    {
	    //Non static members
        public string message = "Hello World";
        public string Name { get; set; }
        public void DisplayName()
        {
            Console.WriteLine("Name = {0}", Name);
        }

        //Static members
        public static string greetings = "Good morning";
        public static int Age { get; set; }
        public static void DisplayAge()
        {
            Console.WriteLine("Age = {0}", Age);
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            MyClass classA = new MyClass();

            Console.WriteLine(classA.message);
            classA.Name = "Jamie";
            classA.DisplayName();

            Console.WriteLine(MyClass.greetings);
            MyClass.Age = 39;
            MyClass.DisplayAge();

            Console.Read();
        }
    }

}
