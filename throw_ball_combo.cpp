/*https://practice.geeksforgeeks.org/problems/throwball-at-fair/0
ThrowBall at Fair
Submissions: 205   Accuracy:
6.81%   Difficulty: Medium   Marks: 4

Recently you went to a fair. There were a lots of rides and stalls. You enjoyed the fair a lot, but the most entertaining part was to play ThrowBall. In ThrowBall, you need to pay Rs 100 as the fee, and then throw N identical balls into K distinct boxes, such that there is at least one ball in each box. You tried your best but couldn’t throw all balls properly, so you lost your money. But the shopkeeper was generous, he gave you a last chance. He asked you a question, which if solved correctly will give your money back.
The question is What was the distinct number of ways in which you could throw those balls into the boxes?
As the answer could be very large, print it modulo M, where M is a prime number.
Input:
The first line of input contains an integer T, denoting the number of test cases. The only line of each test case contains 3 space seperated integers N,K and M as described above.
Output:
For each test case output a single integer corresponding to the answer of the question asked by the shopkeeper, in new line.
Constraints:
1<= T <=100
1<= N <= 1018
1<= K <= 1018
1<= M <= 106
Example:
Input:
2
13 9 7
5 5 7
Output:
5
1
Explanation:
In first test case distinct number of ways of throwing 13 identical balls into 9 distinct boxes is  495.
So the answer modulo 7 is 5.
** For More Input/Output Examples Use 'Expected Output' option **
*/
/*
each k >= 1 ball
N>=k

if N=k, return 1
Excess = N-k
Each excess,E, has k possibilities
K^E


*/
#include <cstdio>
#include <iostream>
using namespace std;

using namespace std;

static const auto speedup = []() {
    cin.tie(nullptr);
    return nullptr;
}();

int h(int b, int c)
{
    if (b < c)
        return 0;
    if (b == 1 || c <= 1)
        return 1;
    int cnt = 0;
    for (int i = 1; i <= b - 1; i++)
        cnt += h(i, 1) * h(b - i, c - 1);
    return cnt;
}

int main()
{
    long long int n, r;
    int t, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> r >> p;
        int rr = h(n, r);
        cout << rr << endl;
        //your code
        //cout << sum << endl;
    }
    return 0;
}
/*
long long pow(int a, long long b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}

int C(long long n,long long r,int m)
{
	long long res;
	long long l,h,tot,fixc,bons,bone;
	
	long long i;int a[m]={0};
	l=r+1,h=n;
	tot=h-l+1;
       if(tot>=m)
      return 0;
    fixc=tot/m;
	bons=l%m;
	bone=bons+tot%m-1;
	
	for(i=0;i<m;i++)
	{
		if(i>=bons&&i<=bone)
		a[i]=fixc+1;
		else
		a[i]=fixc;
	}
	res=1;
	for(i=0;i<m;i++)
	{
		res*=pow(i,a[i],m);
		res%=m;
	}
	long long nume=res;
	/////////////
	
	int b[m]={0};
	l=1,h=n-r;
	tot=h-l+1;
    fixc=tot/m;
	bons=l%m;
	bone=bons+tot%m-1;
	
	for(i=0;i<m;i++)
	{
		if(i>=bons&&i<=bone)
		b[i]=fixc+1;
		else
		b[i]=fixc;
	}
	res=1;
	for(i=0;i<m;i++)
	{
		res*=pow(i,b[i],m);
		res%=m;
	}
	
	long long int deno=res;
	
	return ((nume*pow(deno,m-2,m))%m);
	
}

int main()
{
	long long int n,r;int t,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%d",&n,&r,&p);
	    printf("%d\n",C(n-1,r-1,p));
	}
	
}*/