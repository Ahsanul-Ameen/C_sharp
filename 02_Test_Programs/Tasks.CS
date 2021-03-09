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



  
  public static void Main(string[] args) {
    
    //task_1();
    //task_3();
    //task_3(false);
	  findInSortedArray(999);
  }
}
