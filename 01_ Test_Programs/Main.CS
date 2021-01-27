using System;

public class Utility {
  public int __multiply(int a, int b) {
    return a * b;
  }
}

class Starter {
  static void Main(string[] args) {
    Console.WriteLine("Hello" + "Wolrd: " + 2021);

    Utility math = new Utility();
    int a = Convert.ToInt32(Console.ReadLine());
    int b = Convert.ToInt32(Console.ReadLine());
    int m = math.__multiply(a, b);

    Console.WriteLine(a + "*" + b + " = " + m);
  }
}