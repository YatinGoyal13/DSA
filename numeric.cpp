/*Convert a sentence into its equivalent mobile numeric keypad sequence
Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 
Input: GEEKSFORGEEKS
Output: 4333355777733366677743333557777
Explanation: For obtaining a number, 
we need to press a number corresponding to that character for a number of times equal to the position of the character. 
For example, for character E, press number 3 two times and accordingly.*/

/**
 * The function takes a string of lowercase letters and returns a string of corresponding numbers based
 * on a given mapping.
 * 
 * @param s The input string for which we want to generate the sequence of numbers based on the phone
 * keypad mapping.
 * @param arr An array of strings where each index represents a letter of the alphabet and the string
 * at that index represents the corresponding sequence of numbers on a phone keypad.
 * 
 * @return The function `printSeq` is returning a string which is the sequence of numbers corresponding
 * to the input string `s` based on the mapping given in the `arr` array.
 */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string printSeq(string s,string arr[])
{
    int n=s.length();
    string ans="";
	for(int i=0;i<n;i++)
    {
	    int index=s[i]-'a';
        ans+=arr[index];
        }
	return ans;
}


int main()
{
    string s;
    cin>>s;

    string arr[]={"2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999"};
    cout<<printSeq(s,arr);
}