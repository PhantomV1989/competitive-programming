/*
https://practice.geeksforgeeks.org/problems/return-two-prime-numbers/0
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only first such pair. 
NOTE: A solution will always exist, read Goldbach’s conjecture.
Also, solve the problem in linear time complexity, i.e., O(n).
 
Input:
The first line contains T, the number of test cases. The following T lines consist of a number each, for which we'll find two prime numbers.
Note: The number would always be an even number.
 
Output:
For every test case print two prime numbers space separated, such that the smaller number appears first. Answer for each test case must be in a new line.
Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 10000
Example:
Input:
5
74
1024
66 
8
9990
Output:
3 71
3 1021
5 61
3 5
17 9973
*/

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

    long long res, nn;
    int m, n, np = 1;
    bool br, prime[31624] = {false, false, true}; // 2 is prime

    for (n = 3; n < 31624; n += 2)
        prime[n] = true; // odd maybe prime
    for (n = 3; n < 178; n += 2)
        if (prime[n])
            for (m = n * n; m < 31624; m += (n + n))
                prime[m] = false;

    int t;
    cin >> t;
    while (t--)
    {
        long long l;
        int i;
        cin >> l;
        for (i = l; i > 0; i--)
            if (prime[i] && prime[l - i])
                break;
        cout << l - i << " " << i << endl;
    }
    return 0;
}