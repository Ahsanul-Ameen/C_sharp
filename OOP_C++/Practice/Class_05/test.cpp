#include <iostream> 
#include <unistd.h>
#include <stdio.h>
#include <string>

using namespace std;

void pushback ()
 {
     string str1;
     string str = "\0";
     string str2 = ",";
     cin >> str1;
     //str1 =

     int counter = 1;
    if (str1.length() == 7)
    {   for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 2)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 5)
            {
                str.push_back(str2[0]);
            }
        }
    }
    else if (str1.length() == 9)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 2)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 5)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 8)
            {
                str.push_back(str2[0]);
            }
        }
    }
    else if (str1.length()  == 8)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 3)
            {
                str.push_back(str2[0]);
            }
            else if (counter == 6)
            {
                str.push_back(str2[0]);
            }
        }
    }      

    else if (str1.length() == 4)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 2)
            {
                str.push_back(str2[0]);
            }
        }
    }      
     else if (str1.length() == 5)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 3)
            {
                str.push_back(str2[0]);
            }
        }
    } 
    else if (str1.length() == 3)
    {
      for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
        }

    } 
    else if (str1.length() < 3)
    {
        cout << str1;
    }    
    else if (str1.length() == 6)
    {
        for(int i = 0; i < str1.length(); i++)
        {
            str.push_back(str1[i]);
            counter++;
            if (counter == 4)
            {
                str.push_back(str2[0]);
            }
        }
    }
    cout << str;

 }

int main ()
{
    pushback();
    cout << "\n";
    return 0;
}