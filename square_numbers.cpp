/*
A number k is called a square number if for some value of d > 1,  k % (d*d) = 0.
Given a number N, the task is to find the total number of positive square numbers less than or equal to N.

Input: 
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a sinlge line containing a single integer N.

Output:
Corresponding to each test case, print in a new line an integer denoting the total number of positive square numbers less than or equal to N.

Constraints:
1<=T<=100
1<=N<=10^9

Example:
Input:
3
42
4
10


1
42 4,8,9,12,16,18,20,24,25,27,28,32,36,40,

Output:
0
1
3

Explanation:

4 -> (divisible by 2*2)
8 ->(divisible by 2*2)
9 ->(divisible by 3*3)

For 2-> no numbers less than or equal 2 are square numbers
For 4-> only 4 is a square number
For 10-> 4,8,9 are square numbers
*/

//Loop to n is always slower than closed form

#include <cstdio>

long long res, nn;
int primes2[3404] = {4}, n, np = 1;
bool br, prime[31624] = {false, false, true}; // 2 is prime


void calc(int iter, int t, int i, long long prime_sq)
{
    if (prime_sq > nn)
        return;
    if (iter >= t)
    {
        /*
        when t is 1, it adds normally nn/prime_sq without accounting for overlaps
        when t is even, aka t%2==0 or !t&1, it removes all overlaps, including those with 3 factors
        when t is 3, t&1, it compensates the over-removing in step 2 with 3 layer multiplication

        */
        if (t & 1)
        {
            res += nn / prime_sq;
            printf("%lld\n", prime_sq);
        }
        else
        {
            res -= nn / prime_sq;
            printf("%lld\n", -prime_sq);
        }
        br = false;
        return;
    }
    for (int prime_iter = i; prime_iter < np; prime_iter++)
    {
        long long new_prime_sq = prime_sq * primes2[prime_iter];
        if (new_prime_sq > nn)
            break;
        calc(iter + 1, t, prime_iter + 1, new_prime_sq);
    }
}

int main()
{
    int t, n, m, i;

    for (n = 3; n < 31624; n += 2) prime[n] = true; // odd maybe prime
    for (n = 3; n < 178; n += 2) if (prime[n]) for(m=n*n;m < 31624; m += (n + n)) prime[m] = false;
    for (n = 3; n < 31624; n += 2)
        if (prime[n])
            primes2[np++] = n * n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &nn);
        for (i = 1, res = 0;; i++)
        {
            br = true;
            calc(0, i, 0, 1);
            if (br)
                break;
        }
        printf("%lld\n", res);
    }
}
/*
int main()
{
    int t, n, m, i;

    for (n = 3; n < 31624; n += 2)
        prime[n] = true; // odd maybe prime
    for (n = 3; n < 178; n += 2)
        if (prime[n])
            for (m = n * n; m < 31624; m += (n + n))
                prime[m] = false;
    for (n = 3; n < 31624; n += 2)
        if (prime[n])
            primes2[np++] = n * n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &nn);
        for (i = 0; i < 3404; i++)
        {
            if (primes2[i] > nn)
                break;
            else
            {
                res += nn / primes2[i];
                printf("%d\n", primes2[i]);
            }
            for (int j = 0; j < i; j++)
            {
                long long v = (primes2[i] * primes2[j]);
                if (v > nn)
                    break;
                res -= nn / (primes2[i] * primes2[j]);
                printf("%d\n", -(primes2[i] * primes2[j]));
            }
        }

        printf("%lld\n", res);
    }
}
*/
//18468
