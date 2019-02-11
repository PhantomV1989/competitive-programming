/*https://practice.geeksforgeeks.org/problems/factorial-and-numbers/0
Factorial and numbers
Submissions: 606   Accuracy:
7.43%   Difficulty: Medium   Marks: 4
Given a number N. You are tasked with finding the smallest number S, such that N is a factor of S! (S factorial). N can be very large.
Input:
The first line of input contains an long longeger T denoting the number of test cases. Then T test cases follow. Each test case contains an long longeger n.
Output:
Prlong long the smallest number, such that N is a factor of S!
Constralong longs:
1<=T<=100
1<=N<=10^12
Example:
Input:
2
6
800
Output:
3
10
** For More Input/Output Examples Use 'Expected Output' option **
*/
//1824
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
vector<long long> factor(long long x)
{ //odd is value, even is freq
    vector<long long> res;
    long long i = 2;
    while (i * i <= x)
    {
        long long c = 0;
        while (x % i == 0)
        {
            x = x / i;
            c++;
        }
        res.push_back(i);
        res.push_back(c);
        i++;
    }
    if (x != 1)
        res.push_back(x);
    res.push_back(1);
    return res;
}
static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
void h(long long x)
{
    vector<long long> a = factor(x);
    long long mx = 0;
    long long n = 0;
    for (long long i = 0; i < a.size() - 1; i += 2)
    {
        n = a[i];
        for (long long j = i + 1; j < a.size(); j++)
        {
            if (a[j] == a[i])
                n *= a[j];
            else
            {
                if (n > mx)
                    mx = n;
                i = j - 1;
                break;
            }
        }
    }
    cout << mx;
}
long long main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long l;
        cin >> l;
        h(l);
    }
    return 0;
}*/
long long n;
struct prime_freq
{
    vector<long long> prime;
    vector<long long> freq;
};

prime_freq factor(long long x)
{ //odd is value, even is freq
    vector<long long> prime;
    vector<long long> freq;
    long long i = 2;
    while (i * i <= x)
    {
        long long c = 0;
        while (x % i == 0)
        {
            x = x / i;
            c++;
        }
        if (c > 0)
        {
            prime.push_back(i);
            freq.push_back(c);
        }
        i++;
    }
    if (x != 1)
    {
        prime.push_back(x);
        freq.push_back(1);
    }
    prime_freq res;
    res.prime = prime, res.freq = freq;
    return res;
}
long long h()
{
    if (n == 1 || n == 0)
        return 1;
    long long max = 0;
    prime_freq r = factor(n);
    for (long long i = 0; i < r.prime.size(); i++)
    {
        long long rr = r.prime[i] * r.freq[i];
        if (rr > max)
            max = rr;
    }
    return max;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << h() << endl;
    }

    return 0;
}