/*https://practice.geeksforgeeks.org/problems/santa-banta/0
Santa Banta
Submissions: 1531   Accuracy:
5.99%   Difficulty: Medium   Marks: 4
Santa is still not married. He approaches a marriage bureau and ask them to hurry the process.
The bureau checks the list of eligible girls (n) and hands it over to Santa.
Santa being conscious about his marriage, determined to find a girl with maximum connections so that he can gather more information about her.
Accordingly, he looks to figure out the maximum number of girls (from list) who know each other to achieve above purpose.
In order to finalise the girl,he needs to find the Kth prime.
Where k = largest group of girls who know each other .
Considering Santa's poor knowledge in Maths, he seeks for Banta's help for the answer.
Now you , being fan of Santa Banta Jokes, take this prestigious opportunity to solve the problem.
In case no of connections are zero ,print "-1".
Note :
Suppose girl "a" knows girl "b" and girl "b" knows girl "c" , then girl "a" also knows girl "c".
Transitivity holds.
Consider 1 composite no.
Input:
First line of the input contains t, the number of test cases. Each line of the test case contains a number n specifying the number of girls and m specifying no of connections. Each 'm' lines contain u and v denoting that girl u and v know each other.
Output:
Each new line of the output contains Kth prime no .
Constraints:
1<=t<=205
1<=n<=100000
0<=m<=10000
1<=u,v<=n
Example:
Sample Input 0
1
10 6
1 2
2 3
3 4
4 5
6 7
9 10
Sample Output 0
11


7 7
1 2
6 7
4 5
4 5
2 3
2 3
3 4


7 7
5 6
3 4
2 3
5 6
5 6
6 7
5 6
*/
//1705
//all same, 2 big different with last bridge
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

long long res, nn; //1 is not a prime!!!
const int p1 = 31624, p2 = 3403;
int primes2[p2] = {2}, m, n, np = 1;
bool br, prime[p1] = {false, false, true}; // 2 is prime

vector<long> grouplinks(vector<vector<long>> uv, int n)
{ //treat each vertice as a group with its neighbours instead of by itself
    vector<long> grp(n + 1);
    int gc = 1;
    for (int i = 0; i < n + 1; i++)
        grp[i] = 0;

    for (int j = 0; j < uv.size(); j++)
    {
        long u = uv[j][0];
        long v = uv[j][1];
        if (grp[u] == 0)
            grp[u] = gc;
        if (grp[v] == 0)
            grp[v] = gc;
        if (grp[u] != 0 && grp[u] < gc)
        {
            int lr = grp[v];
            for (int ii = 0; ii < grp.size(); ii++)
                if (grp[ii] == lr)
                    grp[ii] = grp[u];
        }

        else if (grp[v] != 0 && grp[v] < gc)
        {
            int lr = grp[u];
            for (int ii = 0; ii < grp.size(); ii++)
                if (grp[ii] == lr)
                    grp[ii] = grp[v];
        }
        gc++;
    }
    return grp;
}

long h2(vector<vector<long>> uv, int n)
{
    long mx = 0, tt = 1;
    vector<long> grp_r = grouplinks(uv, n);
    for (int i = 1; i <= grp_r.size(); i++)
    {
        int c = count(grp_r.begin(), grp_r.end(), i);
        if (c > mx)
            mx = c;
    }

    return mx;
}

int main()
{

    for (n = 3; n < p1; n += 2)
        prime[n] = true; // odd maybe prime
    for (n = 3; n < 178; n += 2)
        if (prime[n])
            for (m = n * n; m < p1; m += (n + n))
                prime[m] = false;
    for (n = 3; n < p1; n += 2)
        if (prime[n])
            primes2[np++] = n;
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        vector<vector<long>> uv;
        cin >> n >> m;
        while (m--)
        {
            long u, v;
            cin >> u >> v;
            vector<long> tuv = {u, v};
            uv.push_back(tuv);
        }
        if (uv.size() == 0)
            cout << "-1" << endl;
        else
        {
            long qwe = h2(uv, n);
            cout << primes2[qwe - 1] << endl;
        }
    }
    return 0;
}

/*
#define f(i,a,b) for(int i=a;i<b;i++)
#define lli long long int
#define ulli unsigned long long int
#define MAX 1000010
using namespace std;

int primeN[1000010];
void prime()
{
    bool isPrime[MAX]={0};
    int k=0;
    
    isPrime[0]=isPrime[1]=1;
    for(int i=2;i*i<MAX;i++)
    {
        if(!isPrime[i])
        {
            //primeN[k++]=i;
            for(int j=i*i;j<MAX;j+=i)
            {
                isPrime[j]=1;    
            }   
        }
        
    }
    for(int i=2;i<MAX;i++)
    {
        if(!isPrime[i])
            primeN[k++]=i;
    }
    
}


int find(int *parent, int x)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}

void makeUnion(int *parent, int *size, int u, int v)
{
    int uParent=find(parent,u);
    int vParent=find(parent,v);
    
    if(uParent==vParent)
        return;
    if(size[uParent]>=size[vParent])
    {
        size[uParent]+=size[vParent];
        parent[vParent]=uParent;
    }
    else
    {
        size[vParent]+=size[uParent];
        parent[uParent]=vParent;
    }
}

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prime();
	int t;
	cin >> t;
	while(t--)
	{
        int v,e;
        cin >>v >> e;
        //list<int> *adj = new list<int>[v+2];
        
        int *parent=new int[v+2];
        int *size=new int[v+2];
        //memset(size,1,sizeof(size));
        
        for(int i=0;i<v;i++)
           { parent[i]=i;size[i]=1;}
        
        
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin >> x >>y;
            makeUnion(parent,size,x,y);
        }
        int ma=1;
        for(int i=0;i<v;i++)
        {
            if(size[i]>ma)
                ma=size[i];
        }
        if(ma==1)
            cout<<"-1\n";
        else
            cout <<primeN[ma-1]<<endl;
	}
	return 0;
}

*/