/*
https://practice.geeksforgeeks.org/problems/total-number-of-equal-partition/0
For a number N  f(N) = the total number of parts in the partitions of N into equal parts.
 
For example
if the given number is 4, the equal partitions will be:
{1,1,1,1}   ->total parts=4
{2,2}        -> total parts=2
{4}           -> total parts=1
So,  the total number of parts in the partition of 4 into equal parts is 7.
Now you are given two number l,r. find the sum of f(i) for i=l to r.(both inclusive)
 
Input:
First line of input contains a single integer T denoting the number of test cases.
Each line of test case containing two space separated integers l and r as described in the problem statement.
Output:
For each test case, output a single integer containing the sum as described in the problem statement.
Constraints:
1<=T<=100
1<=l<=r<=10^7
Example:
Input
1
1 2

1:1
2:2 1 1=>3
Output
4
** For More Input/Output Examples Use 'Expected Output' option **
*/

//closed form need to find patterns in the numbers
//1437
#include <cstdio>
#include <iostream>
using namespace std;

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        long long sum = 0;
        for (long long i = 1; i <= r; i++)
        {
            long a = (r / i);
            long b = ((l - 1) / i);
            long long count = a - b; //(l/i)-((l-1)/i)
            long long c = count * i;

            sum += c;
        }
        cout << sum << endl;
    }
    return 0;
}

//1617