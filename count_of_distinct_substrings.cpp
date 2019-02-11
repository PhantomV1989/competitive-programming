/*
Given a string of length N of lowercase alphabet characters. The task is to complete the function h(), which returns the count of total number of distinct substrings of this string.

Examples:
Input: str = “ababa”
Output: 10
Total number of distinct substring are 10, which are,
"", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba"
and "ababa".

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case in a new line, output will be an integer denoting count of total number of distinct substrings of this string.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function h().

Constraints:
1 <=T <= 50
1 <= N <= 1000

Example(To be used only for expected output):
Input:
2
ab
ababa

Output:
4
10

Exaplanation:
Testcase 1: For the given string "ab" the total distinct substrings are: "", "a", "b", "ab".
** For More Input/Output Examples Use 'Expected Output' option **

*/

//0113

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm> //for find
#include <iostream>

using namespace std;

string s;
//
#include <string.h>
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int size = s.size();
    int c = 0;
    for (int i = 1; i <= size; i++)
    {
        string first = s.substr(0, i);
        int j = 0;
        string second = s.substr(i - j, j + 1);
        while (j < size && first.find(second) != string::npos)
        {
            j++;
            second = s.substr(i - j, j + 1);
        }
        c = c + i - j + 1;
    }
    return c + 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        cin >> s;
        cout << countDistinctSubstring(s) << endl;
    }
}