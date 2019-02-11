#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int primeGenerator()
{

    long long res, nn;//1 is not a prime!!!
    const int p1=31624,p2=3403;
    int primes2[p2] = {2}, m, n, np = 1;
    bool br, prime[p1] = {false, false, true}; // 2 is prime

    for (n = 3; n < p1; n += 2)
        prime[n] = true; // odd maybe prime
    for (n = 3; n < 178; n += 2)
        if (prime[n])
            for (m = n * n; m < p1; m += (n + n))
                prime[m] = false;
    for (n = 3; n < p1; n += 2)
        if (prime[n])
            primes2[np++] = n;
}

struct prime_freq
{
    vector<int> prime;
    vector<int> freq;
};

prime_freq factor(int x)
{ //odd is value, even is freq
    vector<int> prime;
    vector<int> freq;
    int i = 2;
    while (i * i <= x)
    {
        int c = 0;
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

void generate_factorial_prime_factors(int max)
{
    vector<vector<int>> r;
    vector<int> tr;
    r.push_back({1, 1});
    r.push_back({1, 1});

    for (int i = 2; i <= max; i++)
    {
        tr = factor(i);
        vector<int> ttr = r[i - 1];
        //AB.insert(AB.end(), B.begin(), B.end());
        if (tr.size() == 2 && tr[1] == 1)
        {
            ttr.insert(ttr.end(), tr.begin(), tr.end());
        }
        else
        {
            int lp = 0;
            for (int j = 0; j < tr.size(); j += 2)
            {
                while (ttr[lp] != tr[j])
                {
                    lp += 2;
                }
                ttr[lp + 1] += tr[j + 1];
            }
        }
        r.push_back(ttr);
    }
}
/////////////////////////////////////////////////
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3 || n == 5)
        return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return false;
    int m = sqrt(n);
    for (int i = 5; i <= m; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

vector<bool> sieve(int n)
{
    vector<bool> prime(n + 1);
    fill(prime.begin(), prime.end(), true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 1; i <= (int)sqrt(n); i++)
    {
        if (isPrime(i))
            for (int k = i * i; k <= n; k += i)
                prime[k] = false;
    }
    return prime;
}
