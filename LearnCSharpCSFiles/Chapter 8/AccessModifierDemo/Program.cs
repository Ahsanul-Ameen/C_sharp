using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccessModifierDemo
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }

    class ClassA
    {
        private int privateNum = 1;
        public int publicNum = 2;
        protected int protectedNum = 3;

    }

    class ClassB : ClassA
    {
        public void PrintMessages()
        {
            Console.WriteLine(publicNum);		//This is ok
            Console.WriteLine(protectedNum);	//This is ok
            Console.WriteLine(privateNum);	//This is NOT ok
        }
    }

    class ClassC
    {
        ClassA a = new ClassA();

        public void PrintMessages()
        {
            Console.WriteLine(a.publicNum);	//This is ok
            Console.WriteLine(a.protectedNum);	//This is NOT ok
            Console.WriteLine(a.privateNum);	//This is NOT ok
        }
    }
}
