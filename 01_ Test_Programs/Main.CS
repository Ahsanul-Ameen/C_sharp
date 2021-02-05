using System;


class Starter {

  // overloaded print methods
  private static void print(int goat) {
     Console.WriteLine(goat);
  }

   private static void print(char ch) {
     Console.WriteLine(ch);
  }

  private static void print(string arg) {
     Console.WriteLine(arg);
  }

   private static void print(bool status) {
     Console.WriteLine( "bool: " + status);
  }

  // generates a table of multiplication with 1..10
  private static void printMultiplication(int number) {
      // 13 * 1 = 13
      // 13 * 2 = 26 
      // ....
      // 13 * 10 = 130

      for(int i = 1; i <= 10; i++) {
        print("\t" + number + " * " + i + " = " + number * i);
        //Console.WriteLine($"\t{number} * {i} = {number * i}");
      }
  }

  private static void printGrid(int N) {
      //outer for loop
      for(int i = 1; i <= N; i++) {
        // each line print '*' N times
        // inner for loop
        string my_line = "";
        for(int star_no = 1; star_no <= N; star_no++) {
            my_line += "*";
        }
        
        // now my_line contains a line of N stars!!!
        // hence print it
        //print("i : " + i + ": " + my_line);
        print(my_line);
      }
  }

  private static void printAllPair(int n) {
      print("All pair unordered...");
      for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
          print("(" + i + ", " + j + ")");
        }
      }
      print("\n");
  }

  private static void printReversedTriangle(int n) {
      print("A reversed triangle...");
      for(int i = n; i >= 1; i--) {
        string decorated_line = "";
        for(int e = 0; e < n - i; e++) {
          decorated_line += " ";
        }
        for(int s = 1; s <= (2*i - 1); s++) {
          decorated_line += "*";
        }
        print(decorated_line);
      }
  }

  static void Main(string[] args) {
    
      // printMultiplication(13); // 13 er namta will be printed by calling this method
      int n = 5; // for user input
      // n = Convert.ToInt32(Console.ReadLine());

      //printGrid(n); // we pass n to print as N by N grid 

      //printAllPair(6);

      //printReversedTriangle(7);

      // string name = "Abdullah";

      // for(int indx = 0; indx < name.Length; indx++) {
      //     print(name[indx]);
      // }

      // // enhanced for loop
      // foreach(char ch in name) {
      //   print(ch);
      // }
     
  }
}