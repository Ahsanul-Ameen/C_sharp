using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdvancedMethods
{
    class Program
    {
        static void Main(string[] args)
        {
            /*As we are accessing methods of MyClass 
             from the Program class, we need to 
             instantiate a MyClass object first
             and use that object to call the methods.*/

            MyClass a = new MyClass();


            //Passing array as an argument
            int[] myArray = { 1, 2, 3, 4, 5 };      //First declare the array
            a.PrintFirstElement(myArray);           //Then pass it in to the PrintFirstElement() method

            //Passing list as an argument
            List<int> myList = new List<int> { 1, 2, 3 };       //First declare and initilize the list
            a.PrintFirstListElement(myList);                    //Then pass it in the the PrintFirstListElement() method

            //Returning an array
            int[] myArray2 = a.ReturnUserInput();   //Call the ReturnUserInput() method that returns an array
            Console.WriteLine("The array is...");   //Display the content of the array
            foreach (int i in myArray2)
                Console.WriteLine(i);
            Console.WriteLine("\n");

            //Returning a list
            List<int> myList2 = a.ReturnUserInputList();    //Call the ReturnUserInputList() method that returns a list
            Console.WriteLine("The list is...");            //Display the content of the list
            foreach (int i in myList2)
                Console.WriteLine(i);
            Console.WriteLine("\n");

            //Using params
            a.PrintNames("Peter");        //Call the PrintNames() method that can take in a variable number of strings as arguments
            a.PrintNames("Yvonne", "Jamie");
            a.PrintNames("Abigail", "Betty", "Carol", "David");     

            Console.Read();
        }

    }

    class MyClass
    {
        //Method to demonstrate using array as parameter
        public void PrintFirstElement(int[] a)
        {
            Console.WriteLine("The first element is {0}.\n", a[0]);
        }


        //Method to demonstrate using list as parameter
        public void PrintFirstListElement(List<int> a)
        {
            Console.WriteLine("The first list element is {0}.\n", a[0]);
        }

        //Method to demonstrate returning an array
        public int[] ReturnUserInput()
        {
            int[] a = new int[3];

            for (int i = 0; i < a.Length; i++)
            {
                Console.Write("Enter an integer: ");
                a[i] = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Integer added to array.\n");
            }

            return a;
        }

        //Method to demonstrate returning a list
        public List<int> ReturnUserInputList()
        {
            List<int> a = new List<int>();
            int input;

            for (int i = 0; i < 3; i++)
            {
                Console.Write("Enter an integer: ");
                input = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Integer added to list.\n");
                a.Add(input);
            }

            return a;
        }

        //Method to demonstrate using params
        public void PrintNames(params string[] names)
        {
            for (int i = 0; i < names.Length; i++)
            {
                Console.Write(names[i] + " ");
            }

            Console.WriteLine();
        }

    }
}
