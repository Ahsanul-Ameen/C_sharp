using System;
using System.Text;




public class Starter {


private static void task_2() {
  	//TODO:

    int n = Convert.ToInt32(Console.ReadLine());
    char[] chrs = new char[n];
    //char[,] chrs2d = new char[8,8];
    for(int i = 0; i < n; i++) {
      chrs[i] = (char)Console.Read();
    }
    Console.WriteLine("");
    char ch = (char)Console.Read(); // type casting
    Console.WriteLine("");
    // find all occurance
    bool found = false;
    for(int i = 0; i < n; i++) {
      if(chrs[i] == ch) {
        found = true;
        Console.WriteLine(i);
      }
    }

    if(!found) {
       Console.WriteLine(-1);
    }
}
			 

  private static void task_3() 
  {
      // n = 10000000 = 10^6 ----- > 10^12 / 2 = 10^11 ->  10^11 / 10^9 = 10^3 = 1000 second
      // // 1 sec -> 10^9
      // 1 + 2 + 3 + 4 + 5 = 5 * (5 + 1) / 2
      // 1 + 2 + 3 + 4 + 5 + 6 + 7 = 7 * (7 + 1) / 2
      // for(int i = 0; i < n; i++){
      //   read(arr[i])
      // }
      // sort(arr)
      // print(arr)

      // 10 = 10 * (10 + 1) / 2  = 55
      // 0 -> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
      // 1 -> 1, 2, 3, ......9
      // 2 -> 2, ...9
      // ..
      // ..
      // 7 -> 7, 8, 9
      // 8 -> 8, 9
      // 9 -> 9
    // bubble, selection, insertion sort have complexity of O(n^2) -> quadratic time complexity.. takes long time for n > 1000000
    // While counting sort has a time complexity of O(n) -> linear time complexity .. takes few time for n 
      int n = 1000;
      Random rnd = new Random();
      int[] arr = new int[n]; // [1 - 1000] 
      for(int  k =0; k < n; k++) {
        arr[k] = rnd.Next(1, 1000);
      }
    
      // print the array (whole)
      for(int  k =0; k < n; k++) {
          Console.Write(arr[k] + ", ");
      }
      Console.WriteLine();
    // selection sort
    for(int i = 0; i < n - 1; i++) {
      // find the minimum nuber's index in the array
      int min_indx = -1, mini = 100000; // arr[min_indx] // arr[-1] -> index out of bound error [0, arr.size() - 1]
      for(int j = i; j < n; j++) {
        if(arr[j] < mini) {
          mini = arr[j];
          min_indx = j; // indx of
        }
      }
        // swap arr[i], arr[min_indx]
        
        int temp = arr[i];
        arr[i] = arr[min_indx];
        arr[min_indx] = temp;

        // for(int  k =0; k < n; k++) {
        //   Console.Write(arr[k] + " ");
        // }
        Console.WriteLine();
    }

    for(int  i =0; i < n; i++) {
      Console.WriteLine(arr[i]);
    }
  }

  // method overloading | method_name | parameter change | return type doesn't matter
  private static void task_3(bool counting_sort = true) {
    int n = 1000;
    Random rnd = new Random();
    int[] arr = new int[n]; // [1 - 1000] 
    for(int  k =0; k < n; k++) {
      arr[k] = rnd.Next(1, 1000);
    }
  
    // print the array (whole)
    for(int  k =0; k < n; k++) {
        Console.Write(arr[k] + ", ");
    }
    Console.WriteLine();


    int[] counter = new int[1000 + 1]; // adjust counter array for total range(1, 1000)
    // int arr[] = new int()
    // int[] arr = new int()
    // 1 2, 3, ,,, 1000
    // linear scan
    for(int i = 0; i < n; i++) {
      // int indx = arr[i];
      // counter[index]++;
      counter[arr[i]]++;

      // for(int k = 1; k < 1000 + 1; k++) { // check for all numbers from 1 to 1000
      //     Console.Write(counter[k] + " ");
      // }
      // Console.WriteLine();
    }

    // update original array
    int next_indx = 0;
    for(int i = 1; i < 1000 + 1; i++) { // our number range is between [1, 1000]
      while(counter[i] > 0) { // i = 4, counter[4] = 2
        arr[next_indx++] = i; // arr[3] = 4, next_indx = 4
        counter[i]--;
      }
    }

    // 2, 3, 4, 4, 5

    // now print the original sorted array
    for(int k = 0; k < n; k++) {
          Console.Write(arr[k] + " ");
    }
    Console.WriteLine();

  }

  // task_04
  private static void findInSortedArray(int target) {
    int n = 100;
    Random rnd = new Random(); // actual random -> Pseudo random number -> efficient algorithm
    int[] arr = new int[n]; // [1 - 10000] 
    for(int  k =0; k < n; k++) {
      arr[k] = rnd.Next(990, 1010);
    }
    Array.Sort(arr);

    // binary search
    // array is sorted in non increasing order [5, 4, 4, 3, 2, 1]
    // ^--------|matched|---------^
    bool ache_kina = false;
    int found_indx = -1;
    int lo = 0, hi = n - 1, mid;
    while(lo <= hi) {
       mid = lo + (hi - lo) / 2 ;
       if(arr[mid] > target) {
          lo = mid + 1;
       } else if(arr[mid] < target) {
         hi = mid - 1;
       } else {
         // arr[mid] = target
         //mid -> indx
         ache_kina = true;
         found_indx = mid;
         break;
       }
    }
    Console.WriteLine(ache_kina + " indx: " + found_indx);
  }

  // task _05
  private static int countStr(string needle, string haystack) {

    //  in:  "poor", "A poor needle in haystack!"
    // 	   out: 1
        
    // 	   in:  "noodle", "A poor needle in haystack!"
    // 	   out: 0
        
    // 	   in:  " ", "A_poor needle in haystack!"
    // 	   out: 3

      int len1 = needle.Length;
      int len2 = haystack.Length;
      int count = 0;
      for(int beg_indx = 0; beg_indx < len2; beg_indx++) {
        if (beg_indx + len1 - 1 >= len2) {
          break;
        }

        // "xyz0123456" // staring_indx + length - 1 // 3 + 7 - 1 = 9
        // supporse needle starts from here
        // beg_indx + len1 - 1  // [7 + 0, 7 + 1, 7 + 2, 7 + 3, 7 + 4, 7 + 5]
        bool found = true;
        //"poor" "random poor guy"
        for(int j = 0; j < len1; j++) {
          if(needle[j] != haystack[beg_indx + j]) {
            found = false;
            break;
          }
        }
        if(/*prev index of first matched index shoul also be a space &&*/ found  /* && snext index of last matched index is a space*/) {
          count++;
          Console.WriteLine("found at: " + beg_indx);
        }
      }
      return count;
  }

  //  Task_06: Write a program that takes a binary string as input and prints the equivalent decimal value.
  // sample_IO: in: 1000101
  // 		   out: 69
        
  // 		   in: 10
  // 		   out: 2
        
  // 		   in: 11111111111111111111111111111111
  // 		   out: -1 (to be tested...)

  private static int binToDec(string bin_string) {
    int dec = 0;
    int value = 1;
    int len = bin_string.Length;
    for(int i = len - 1; i >= 0; i--) {
      if(bin_string[i] == '1') {
        dec += value;
      }
      value =  value << 1; // value *= 2; // left shift
    }
    return dec;
  }

  private static string decToBin(int decim) {
      StringBuilder sb = new StringBuilder("00000000000000000000000000000000", 50);
      /// 
      int place = 31;
      while(decim >= 0 && place >= 0) {
        //if(condition) a else b
        //condition ? a : b;
        sb[place--] = (decim % 2) == 1 ? '1' : '0'; // store the remainder // using Ternary operatior
        decim /= 2;  // update new decim as qoutient
      }
      while(place >= 0) {
        sb[place] = '0';
        place--;
      }
      return sb.ToString();
  }

  // Task 08
  private static int[] prefixSum(int[] arr) {
    int n = arr.Length;
    int[] prefix_sum = new int[n]; // create a prefix sum array of same length
    //Array.Clear(prefix_sum, 0, n); // clear the array with 0

    for(int i = 0; i < n; i++) {
      // pre[i] = pre[i-1] + arr[i] 
      prefix_sum[i] = arr[i];
      prefix_sum[i] += (i > 0) ? prefix_sum[i-1] : 0; 
    }

    return prefix_sum;
  }
 
  // Task 09
  private static int secondLargest(int[] arr) {
    int first = -1; 
    int second = -2;

    if(arr.Length >= 2) {
      for(int i = 0, item; i < arr.Length; i++) {
        item = arr[i];
        if(item > first) {
          second = first;
          first = item;
        } else if (item > second) {
          second = item;
        }
      }
    }

    return second;
  }

  // Task 10
  private static void task10() {
    int num_greets = 10;
    //num_greets = Convert.ToInt32(Console.ReadLine());
    
    // create an array of greetings
    String[] greets = {"Tank You!" , "It's nice to meet you", "What’s new?", "What’s happenin'"};
    // create a Random instance
    Random r = new Random();
    // execute as u wish
    for(int g = 1, n = greets.Length; g <= num_greets; g++) {
      Console.WriteLine("Greet " + g + ": " + greets[r.Next(0, n-1)]);
    }
  }


  
  public static void Main(string[] args) {
    
    //task_1();

    //task_3();
    //task_3(false);
	  
    //findInSortedArray(999);
    
    //Console.WriteLine(countStr("poor", "poor ! Arandom poor guy is less poor er than me! poor"));
    
    // int store = binToDec("1101010101010100011");
    // Console.WriteLine(store);
    
    // Console.WriteLine(decToBin(store));
    
    Console.WriteLine("[{0}]", string.Join(", ", prefixSum(new int[] {4, 0, 5, -8, -3, 11, 20})));
    Console.WriteLine("[{0}]", string.Join(", ", prefixSum(new int[] {2, 2, 2, 2, 100, 0})));
    
    Console.WriteLine(secondLargest(new int[] {6, 7, 4, -45}));  
    Console.WriteLine(secondLargest(new int[] {-100, -55}));
    
    task10();
  }
}
