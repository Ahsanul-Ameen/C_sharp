using System;
using System.Text;


public class Starter {

//------------------------------------------Code it hard--------------------------------------------------------------
// #Task_01: Write a program(you may write a new method) which takes a string as user input and output its reversed version.
// 	example: Input: "Dhaka" (withoud quotes)
// 			 Output: "akahD" (without quotes)
// 	hint: you may want to swap the first character with the last one, second char with the previous last one and so on.
private static void task_1() {
	StringBuilder input = new StringBuilder(Console.ReadLine());
	// C-sharp, Java -> string immutable(), string builder -> mutable
	// revert
	// r e v e r t -> trever n = 6, pos = 0, 1, 2, 3, 4, 5


	for(int pos = 0, n = input.Length, i, j; 2 * pos < n; pos++) {
		// swap input[pos] , input[n-1-pos],  n = 6
		// pos = 2, n - 1 - pos = 6-1- 2 = 3	
		// i = pos;
		// j = n - 1 - pos;
		// input[i] += (int)input[j];
		// input[j] = input[i] - input[j];
		// intput[i] -= input[j];
		//Console.WriteLine("Before swap: " + input[pos] + ", " + input[n - 1 - pos]);
		char temp = input[pos];
		input[pos] = input[n - 1 - pos];
		input[n - 1 - pos] = temp;
		// swaped
		//Console.WriteLine("after swap: " + input[pos] + ", " + input[n - 1 - pos]);
		Console.WriteLine(pos + ", " + (n - 1 - pos) + ": " + input);	
	}

	
}
			 


  // Declaring a new method for some task
//   #Task_02: Write a program(you may write a new method) which takes the value of an integer N as user input and prints a N by N grid as output.
// 	example: Input: 5
// 			 Output: #####
// 			 		 #####
// 			 		 #####
// 			 		 #####
// 			 		 #####
private static void task_2() {
    int n = Convert.ToInt32(Console.ReadLine());
    // do something
    for(int i = 0; i < n; i++) {
      //print n #'s
      for(int j = 0; j < n; j++) {
        Console.Write('#');
      }
      //adopt a newline
      Console.Write('\n');
    }
  }


private static void task_3() {
    int n = Convert.ToInt32(Console.ReadLine());
    // do something
    for(int i = 0; i < n; i++) { // 0, 1, 2, 3
      //print n #'s
      for(int j = 0; j <= i; j++) { // 0 *, 1 - 1, 2 - 2, 3 - 3
        Console.Write('#');
      }
      //adopt a newline
      Console.Write('\n');
    }
}

// #Task_04: Write a program(you may write a new method) which takes the value of an integer N as user input and prints a right-angle triangle as output.
// 	example: Input: 4
// 			 Output:  **** // 0 -> space, 4 -> *
// 			 		  _*** // 1 -> space, 3 -> *
// 			 		  __** // 2 -> space, 2 -> *
// 			 		  ___* // 3 -> space, 1 -> * -> In total 4 characters

private static void task_4() {
    int n = Convert.ToInt32(Console.ReadLine());
    // // do something
    // for(int i = 1; i <= n; i++) { // 1, 2, 3, 4
    //   //print space first
	//   // i = 4    ___*
	//   // 3 times j : 1, 2, 3
	//   for(int j = 1; j < i; j++) {
	// 	  Console.Write(' ');
	//   }
	//   // print * second
	//   // first line: n = 4, i = 1,   j <= 3; j = 0, 1, 2, 3
	//   for(int j = 0; j <= n - i; j++) {
	// 	  Console.Write('*');	// character
	//   }
    //   //adopt a newline
    //   Console.Write('\n');
    // }

	// we're doing the same task as above using if-else & for loops
	for(int line_no = 1; line_no <= n; line_no++) {
		for(int char_no = 1; char_no <= n; char_no++) {
			if(char_no < line_no) {
				// space	
				Console.Write(' ');	// character
			} else {
				// star	
				Console.Write('*');	// character
			}
		}
		Console.WriteLine(); // newline
	}

}

// #Task_05: Write a program(you may write a new method) which takes the value of an integer N as user input and prints a  triangle as output.
// 	example: Input: 5
// 			 Output:  	*	                		// line 1: 2 * 1 - 1 = 2 - 1 = 1			 		    
// 			           ***				
// 			          *****
// 			         *******  // line_no = 4, total_stars = 7 = 2*3 + 1
// 			        ********* // line_no = 5, total_stars = 9 = 2*(5 - 1) + 1
// 	hint: there are (2*i - 1) characters printed in line i

private static void task_5() {
	int n = Convert.ToInt32(Console.ReadLine());

	for(int line_no = 1; line_no <= n; line_no++) {
		for(int space = 1; space <= (n - line_no); space++) {
			Console.Write(' ');
		}
		// print stars
		for(int stars = 1; stars <= 2*(line_no - 1) + 1; stars++) {
			Console.Write('*');
		} 
		
		Console.WriteLine();
	}
}

  
  public static void Main(string[] args) {
    
	//task_1();
	// call task_2
	// task_2();

	// task_3();
     

	//task_4();

	//task_5();

	// 1:odd    2)99(49
				//   98
				//   _
				//   1
				//   odd * odd = odd 3 * 5 = 15
				//   even * odd = even
				//   odd * even = even
				//   even * even = even
	// 2:even
	// 3:odd 
	// ....
	for(int i = 1; i <= 100; i+=1) {
		if(i%2 == 1) {
			Console.WriteLine(i + ":odd");
		} else {
			Console.WriteLine(i + ":even");
		}
	}

  }
}