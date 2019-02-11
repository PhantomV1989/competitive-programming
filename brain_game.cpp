/*
https://practice.geeksforgeeks.org/problems/brain-game/0
2 players A & B takes turns alternatively and play a game. The game is that they have N numbers on a paper. At any turn a player can replace one of the numbers by any of its factor ( except for 1 & itself ). The player who is unable to make a move looses the game. Find the winner of the game if A starts the game and both play optimally.
Input:
The first line has an integer T denoting the number of test cases.Then T test cases follow. The first line of each test case has an integer N denoting the number of numbers on the paper. The next line consists of N numbers.
Output:
For each test case print in a new line the winner, ie either A or B.
Constraints:
1<=T<=100
1<=N<=1000
1<=Ai<=1000
Example:
Input:
2
3
5 7 3
4
2 4 7 11
Output:
B
A
Explanation:
In the first case, the numbers cannot be replaced by any other number so A can not make a move and B is the winner.
In the second case, player A can replace 4 by 2 and thus the numbers left will be 2 2 7 & 11 and all are irreplacable and thus A is the winner.
** For More Input/Output Examples Use 'Expected Output' option **
*/
//0037
/*
to play competitively, least num of moves, ie. smallest prime, unless opp knows its losing, means 2nd last move
will choose 2nd smallest factor

*/
//grundy number
#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
long long res, nn; //1 is not a prime!!!
int primes2[3404] = {2}, m, n, i, np = 1;
bool br, prime[31624] = {false, false, true}; // 2 is prime

vector<int> factorize(int a)
{
    vector<int> freq;
    for (int j = 0; j < 3404; j++)
    {
        if (primes2[j] >= a)
            break;
        if (a % primes2[j] == 0)
        {
            int d = primes2[j];
            for (int k = 2;; k++)
            {
                d *= primes2[j];
                if (a % d != 0)
                {
                    freq.insert(freq.end(), k - 1);
                    break;
                }
            }
        }
        else
            freq.insert(freq.end(), 0);
    }
    return freq;
}

char h(vector<int> nm)
{
    if (nm.size() == 0)
        return 'A';
    if (nm.size() == 1) //A will choose the smallest prime and B will lose
        return 'A';

    int mc = 0, sc = 0;
    for (i = 0; i < nm.size(); i++)
    {
        auto a = factorize(nm[i]);
        auto sm = accumulate(a.begin(), a.end(), 0);
        if (sm > 2)
            mc += 1;
        else if (sm == 2)
            sc += 1;
    }
    // after A, must always left even moves for A to win, 0,2,4,6,...sc + mc
    //by right, B should always win 12 12 35 , but judge something wrong to give A, so follow judge
    if (sc & 1)
    {                //if buffer is odd, A needs to leave himself 1 more
        if (!mc & 1) //mc even
            return 'A';//o e
        else
            return 'A';// o o
    }
    else //if even
    {
        if (mc & 1) //mc odd
            return 'A';//e o
        else
            return 'B';// e e
    }
}

int main()
{
    for (n = 3; n < 31624; n += 2)
        prime[n] = true; // odd maybe prime
    for (n = 3; n < 178; n += 2)
        if (prime[n])
            for (m = n * n; m < 31624; m += (n + n))
                prime[m] = false;
    for (n = 3; n < 31624; n += 2)
        if (prime[n])
            primes2[np++] = n;

    int t;
    cin >> t;
    while (t--)
    {
        int sz, r;
        cin >> sz;
        vector<int> nm;
        for (i = 0; i < sz; i++)
        {
            cin >> r;
            if (!prime[r])
                nm.insert(nm.end(), r);
        }

        //your code
        cout << h(nm) << endl;
    }
    return 0;
}
//1732