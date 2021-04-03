using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LINQDemoWithClass
{
    class Program
    {
        static void Main(string[] args)
        {

            List<Customer> customers = new List<Customer>();

            customers.Add(new Customer("Alan", "80911291", "ABC Street", 25.60m));
            customers.Add(new Customer("Bill", "19872131", "DEF Street", -32.1m));
            customers.Add(new Customer("Carl", "29812371", "GHI Street", -12.2m));
            customers.Add(new Customer("David", "78612312", "JKL Street", 12.6m));

            var overdue =
                from cust in customers
                where cust.Balance < 0
                orderby cust.Balance ascending
                select new { cust.Name, cust.Balance };

            foreach (var cust in overdue)
                Console.WriteLine("Name = {0}, Balance = {1}", cust.Name, cust.Balance);

            Console.Read();
        }
    }

    class Customer
    {
        public string Name
        {
            get;
            set;
        }

        public string Phone
        {
            get;
            set;
        }

        public string Address
        {
            get;
            set;
        }

        public decimal Balance
        {
            get;
            set;
        }

        public Customer(string name, string phone, string address, decimal balance)
        {
            Name = name;
            Phone = phone;
            Address = address;
            Balance = balance;
        }
    }
}
