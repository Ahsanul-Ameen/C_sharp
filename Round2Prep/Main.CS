using System;
using System.Text; // for StringBuilder
using System.Collections;
using System.Collections.Generic;


public class Starter {

  public static void CheckStack() {

    Hashtable table = new Hashtable();
    table.Add(1, "sabit");
    table.Add(2, "rabit");


    foreach (DictionaryEntry item in table) {
      Console.WriteLine($"{item.Key} has value {item.Value}");
    }

    table.Clear();
    table.Add("sabit", "valo");
    table.Add("orko", "o valo");
    table.Add("shada", "shidha");
    table.Remove("shada");

    foreach(var key in table.Keys) {
      Console.WriteLine(key + " has value : " + table[key]);
    }
    // Contains(key), ContainsKey(key), ContainsValue(value)
    Console.WriteLine(table.ContainsKey("shada"));
  }

  public static void ArrayManipulation() {
    int[] arr = new int[10];
    for (int i = 0; i < 10; ++i) {
      arr[i] = i * i - i;
    }
    Array.Reverse(arr);
    Array.Sort(arr);
    foreach(int value in arr) {
      Console.Write(value + " ");
    }
    Console.WriteLine();
  }

  public static void ArrayListDemo() {
    ArrayList list = new ArrayList();
    list.Add("lio");
    list.Add("co");
    list.Add("pen");
    list.Add(99);
    foreach(var element in list) {
      Console.WriteLine(element);
    }
    Console.WriteLine(list[2]);
  }

  static string DecodeString(string str) {
    
    Stack<char> st = new Stack<char>();

    foreach (char ch in str) {
      if (ch == ']') {
        StringBuilder sb = new StringBuilder();
        while (st.Count != 0 && st.Peek() != '[') {
          sb.Insert(0, st.Peek());
          st.Pop();
        }
        // Console.WriteLine(sb.ToString());
        // remove [
        st.Pop();
        // remove number
        StringBuilder num = new StringBuilder();
        while (st.Count != 0 && Char.IsDigit(st.Peek())) {
          num.Insert(0, st.Peek());
          st.Pop();
        } 
        int n = Convert.ToInt32(num.ToString());
        // Console.WriteLine(n);
        string chars = sb.ToString();
        for (int rep = 1; rep < n; ++rep) {
          sb.Append(chars);
        }
        // Console.WriteLine(chars);
        // insert chars
        foreach (char c in sb.ToString()) {
          st.Push(c);
        }
      } else {
        st.Push(ch);
      }
    }

    string temp = "";
    while (st.Count != 0) {
      temp = st.Peek() + temp;
      st.Pop();
    } 

    return temp;
  }

  static string WordWrap(string multi, int maxChars) {
    multi = multi.Replace("\r\n", " ").Replace("\n", " ").Replace("\r", " ");
    StringBuilder sb = new StringBuilder(multi);
    int left = 0;
    int i = 0;
    // abc|d 3
    while (i < sb.Length) {

      int spaceFreq = 0;
      // for (int j = left; j <= i; ++j) {
      //   if (sb[j] == ' ')
      //     spaceFreq++;
      // }

      while (i == left && sb[i] == ' ') {
        ++i;
        ++left;
      }

      //Console.WriteLine(multi.Substring(left, i - left + 1) + "->" + (i - left + 1 - spaceFreq));
      
      if ((i - left + 1 - (spaceFreq)) % maxChars == 0) { // break after this
        // we need to insert a newline here
        if (i + 1 < sb.Length && Char.IsLetter(sb[i + 1])) {
          // potential chance of begin a word
          while (i >= 0 && Char.IsLetter(sb[i])) --i;
        }
        if (!Char.IsLetter(sb[i])) {
          sb[i] = '\n';
          left = i + 1;
        } else {
          if (i + 1 < sb.Length) {
            ++i;
            sb[i] = '\n';
            left = i + 1;
          }
        }
      }
      ++i;
    }
    return sb.ToString() + "\n";
  }

  static string DiscardChars(string str) {
    Stack<char> st = new Stack<char>();
    
    foreach(char ch in str) {
      // st.Push(ch);
      if (st.Count == 0) {
        st.Push(ch);
      } else {
        if (st.Peek() == '@') {
          st.Pop();
          if (st.Count > 0 && st.Peek() == ch) {
            st.Push(ch);
            st.Push('$');
          } else {
            st.Push('@');
            st.Push(ch);
          }
        } else {
          if (ch != st.Peek()) {
            char lastChar = st.Peek();
            st.Pop();
            int removed = 1;
            while(st.Count != 0 && st.Peek() == lastChar) {
              st.Pop();
              removed++;
            }
            if (removed == 1) {
              st.Push(lastChar);
            }
          }
          st.Push(ch);
        }
      }
    }
    char[] arr =  String.Join("", st).Replace("$", "").ToCharArray();
    Array.Reverse(arr);
    return new string(arr);
  }

  static string CenterAlign(string multiLine) {
    int n = multiLine.Length;
    if (n > 2 && multiLine.Substring(n-2) != "\r\n") {
      multiLine += "\r\n";
    }
    multiLine.Replace("\r\n", "\n");
    // now each line has a newline
    n = multiLine.Length;
    multiLine = multiLine.Substring(0, n - 1); // except the last line

    string[] lines = multiLine.Split("\n");
    n = lines.Length;
    
    string res = "";
    for (int l = 0; l < n; ++l) {
      res += new string(' ', n - 1 - l) + lines[l] + "\r\n"; 
      
      // Console.WriteLine(new string(' ', n - 1 - l) + lines[l]);
    }
    return res;
  }

  static string CenterAlign2(string multiLine) {
    int n = multiLine.Length;
    if (n > 2 && multiLine.Substring(n-2) != "\r\n") {
      multiLine += "\r\n";
    }
    multiLine.Replace("\r\n", "\n");
    // now each line has a newline
    n = multiLine.Length;
    
    int lines = 0;
    foreach (char ch in multiLine) {
      if (ch.Equals('\n')) {
        ++lines;
      }
    }
    StringBuilder sb = new StringBuilder();
    int line = 0;
    bool flag = true;
    foreach (char ch in multiLine) {
      if (ch.Equals('\n')) {
        ++line;
        flag = true;
      } else {
        if (flag) {
          sb.Append(new string(' ', 2 * (lines - 1 - line)));
          flag = false;
        }
      }
      sb.Append(ch);
    }
    return sb.ToString();
  }

  static Tuple<Tuple<char, int>, Tuple<char, int>> MostFreq(string str) {

    if (str.Length == 0) {
      return Tuple.Create(Tuple.Create(' ', 0), Tuple.Create(' ', 0));
    } 
    if (str.Length == 1) {
      return Tuple.Create(Tuple.Create(str[0], 1), Tuple.Create(' ', 0));
    }
    // assume length is >= 2 

    // const int NCHARS = 256;
    Hashtable cnt = new Hashtable();
    //int[] cnt = new int[NCHARS];

    foreach (char ch in str) {
      if (cnt.ContainsKey(ch)) {
        int n = Convert.ToInt32(cnt[ch]);
        cnt[ch] = n + 1;
      } else {
        cnt.Add(ch, 1);
      }
    }

    int fc = 0, sc = -1;
    int fp = 0, sp = 0;

    for (int i = 0; i < str.Length; ++i) {
      char ch = str[i];
      // Console.WriteLine(ch + " : " + cnt[ch]);
      if ((int)cnt[ch] > fc) {
        sc = fc;
        sp = fp;
        fc = (int)cnt[ch];
        fp = i;
      } 
      if (fc > (int)cnt[ch] && (int)cnt[ch] > sc) {
        sc = (int)cnt[ch];
        sp = i;
      }
      // Console.WriteLine(fc + ", " + sc);
    }

    return Tuple.Create(Tuple.Create(str[fp], fc), Tuple.Create(str[sp], sc));
  }

  static int[] RightShift(int[] arr, int k) {
    // 1 2 3 4 | 5 6 7 
    // 5 6 7 | 1 2 3 4
    int n = arr.Length;
    if (n <= 1) {
      return arr; 
    }
    int[] temp = new int[n];
    for (int i = 0; i < n - k; ++i) {
      temp[i + k] = arr[i];
    }
    for (int i = 0; i < k; ++i) {
      temp[i] = arr[n - k + i];
    }
    return temp;
  }

  static string LeftAlign(string str) {
    str = str.Replace(" ", "");
    Console.WriteLine(str);
    int n = str.Length;
    StringBuilder sb = new StringBuilder();

    int m = Convert.ToInt32(Math.Sqrt(n)) + 4;
    int[] arr = new int[m];
    arr[0] = 1;
    for (int l = 1; l < m; ++l) {
      arr[l] = arr[l - 1] + (l + 1);
    }

    for (int i = 0, k = 0; i < n; ++i) {
      sb.Append(str[i]);

      if (i + 1 == arr[k]) {
        sb.Append("\r\n");
        k++;
      } else {
        sb.Append(' ');
      }
    }
    return sb.Append("\r\n").ToString();
  }



  public static void Main(string[] args) {
    // CheckStack();

    // ArrayManipulation();
    
    // ArrayListDemo();
    
    // Console.WriteLine(DecodeString("1[b]")); // bb
    // Console.WriteLine(DecodeString("2[ab]")); // abab
    // Console.WriteLine(DecodeString("2[a2[b]]")); // abbabb
    // Console.WriteLine(DecodeString("3[b2[ca]]"));  // bcacabcacabcaca

    // string multiLine = "is sabit\n\rWhat's your name?";
    // Console.Write(WordWrap(multiLine, 8));
    // multiLine = "yafi is a joker man";
    // Console.WriteLine(WordWrap(multiLine, 6));

    // Console.WriteLine(DiscardChars("Hebb is@s go@od b@y tttt@l@loop"));

    // Console.WriteLine(CenterAlign("1\r\n1 2\r\n1 2 3\r\n1 2 3 4\r\n")); 
    // Console.WriteLine(CenterAlign2("1\r\n1 2\r\n1 2 3\r\n1 2 3 4\r\n")); 

    // Console.WriteLine(MostFreq("geeksforgeeks"));
    // Console.WriteLine(MostFreq("aabababa"));
    // Console.WriteLine(MostFreq("geeksquiz"));
    // Console.WriteLine(MostFreq("abcd"));
    
    // int[] rotatedArray = RightShift(new int[]{1, 2, 3, 4, 5, 6, 7}, 3);
    // foreach (int item in rotatedArray) {
    //   Console.Write(item + " ");
    // } Console.WriteLine();
    // rotatedArray = RightShift(new int[]{-1,-100,3,99}, 2);
    // foreach (int item in rotatedArray) {
    //   Console.Write(item + " ");
    // } Console.WriteLine();

    Console.WriteLine(LeftAlign("1 1 2 1 2 3 1 2 3 4 1 2 3 4 5 1 2 3 4 5 6"));

    // Console.Write("Okay Boss!");
  }
}