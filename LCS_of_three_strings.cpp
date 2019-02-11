/*
Given sno strings X, Y and Z, the task is to find the longest common sub-sequence in all three given sequences.
 
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers n, m and k denoting the length of strings X, Y and Z respectively.
The second line of each test case contains the three strings X, Y and Z. The string consists of only lower case english alphabets.
Output:
Print the length of the longest common sub- sequence of the three strings for each test case in a new line.

Constraints:
1<= T <=100
1<= N, M, K <=100

Example:
Input:
1
5 8 13
geeks geeksfor geeksforgeeks
Output:
5
*/

//1426

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int sno = 3;
    int T, t;
    cin >> T;
    for (t = 0; t < T; t++)
    {
        int size[sno], i, max, min, min_pos;
        for (i = 0; i < sno; i++)
        {
            cin >> size[i];
            if (i == 0)
            {
                max = size[i];
                min = size[i];
                min_pos = i;
            }
            else
            {
                if (size[i] > max)
                    max = size[i];
                if (size[i] < min)
                {
                    min = size[i];
                    min_pos = i;
                }
            }
        }

        std::string str[sno];
        for (i = 0; i < sno; i++)
            cin >> str[i];

        for (int s = 0; s < min; s++)
        {
            for (int j = min; j > 0; j--)
            {
                for(int p=0;p<sno;p++){

                auto sub = str[0].substr(s, j);
                auto a = str[1].find(sub);
                auto b = str[2].find(sub);
                }
                
               
            }
        }
    }
}

/*0.25
    #include <iostream>//0.25
    using namespace std;
    using namespace std;
    int main()
    {
        int t,i,j,k,l,m,n;
        cin>>t;
        while(t--)
        {
        cin>>l>>m>>n;
        string p,q,r;
        cin>>p>>q>>r;
        int dp[l+1][m+1][n+1];
        for(i=0;i<=l;i++)
        {
        for(j=0;j<=m;j++)
        {
        for(k=0;k<=n;k++)
        {
            dp[i][j][k]=0;
        }
        }
        }
        for(i=1;i<=l;i++)
        {
        for(j=1;j<=m;j++)
        {
        for(k=1;k<=n;k++)
        {
            if(p[i-1]==q[j-1]&&q[j-1]==r[k-1])
            dp[i][j][k]=dp[i-1][j-1][k-1]+1;
            else
            dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
        }
        }
        }
        cout<<dp[l][m][n]<<endl;
        }
        return 0;
    }//0.25
*/

/*0.98
    #include <algorithm>
    #include <vector>
    #include <list>
    #include <string>
    #include <set>
    #include <map>
    #include <fstream>
    #include <sstream>
    #include <cmath>
    #include <unordered_set>
    #include <unordered_map>
    #include <iomanip>
    #include <functional>
    #include <bits/stdc++.h>
    using namespace std;

    int Three(void)
    {
        int m, n, l;
        cin >> m >> n >> l;
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(l + 1, 0)));
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 0; j < n + 1; ++j)
            {
                for (int k = 0; k < l + 1; ++k)
                {
                    if (j == 0 || k == 0)
                    {
                        continue;
                    }
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
                    }
                }
            }
        }
        return dp[m][n][l];
    }

    int main()
    {
        int T = 0;
        cin >> T;
        for (int i = 0; i < T; ++i)
        {
            cout << Three();
            cout << endl;
        }
        return 0;
    }//0.98
*/

/*0.24
    using namespace std;//0.24
    int main()
    {
        int t,i,j,k,l,m,n;
        cin>>t;
        while(t--)
        {
        cin>>l>>m>>n;
        string p,q,r;
        cin>>p>>q>>r;
        int dp[l+1][m+1][n+1];
        for(i=0;i<=l;i++)
        {
        for(j=0;j<=m;j++)
        {
        for(k=0;k<=n;k++)
        {
            dp[i][j][k]=0;
        }
        }
        }
        for(i=1;i<=l;i++)
        {
        for(j=1;j<=m;j++)
        {
        for(k=1;k<=n;k++)
        {
            if(p[i-1]==q[j-1]&&q[j-1]==r[k-1])
            dp[i][j][k]=dp[i-1][j-1][k-1]+1;
            else
            dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
        }
        }
        }
        cout<<dp[l][m][n]<<endl;
        }
        return 0;
    }
*/

/*0.21
    #include <iostream>//0.25
    #define ll long long int
    using namespace std;
    int main()
    {
        int test;
        cin>>test;
        while(test--)
        {
            int n,m,p;
            cin>>n>>m>>p;
            cin.clear();
            string s1,s2,s3;
            cin>>s1;
            cin.clear();
            //cin.ignore(100, ' ');
            cin>>s2;
            cin.clear();
            //cin.ignore(100, ' ');
            cin>>s3;
            cin.clear();
            //cin.ignore(100, ' ');
            int dp[n+1][m+1][p+1];
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=m;j++)
                {
                    for(int k=0;k<=p;k++)
                    {
                        if(i==0 || j==0 || k==0)
                        dp[i][j][k]=0;
                        else if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                        else
                        dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                    }
                }
            }
            cout<<dp[n][m][p]<<endl;
            //getchar();
            
        }
        return 0;
    }

*/

/*0.22
    #include <iostream>//0.25
    #include <bits/stdc++.h>
    using namespace std;

    int lcs(string str1, string str2, string str3, int n, int m, int k)
    {
        int f[n+1][m+1][k+1];
        int p,q,r;
        for(p=0; p<=n; p++)
        {
            for(q=0; q<=m; q++)
            {
                for(r=0; r<=k; r++)
                {
                    if(p==0 || q==0 || r==0)
                    f[p][q][r]=0;
                    else if(str1[p-1]==str2[q-1] && str1[p-1]==str3[r-1])
                    f[p][q][r]=1+f[p-1][q-1][r-1];
                    else
                    f[p][q][r] = max(max(f[p-1][q][r],f[p][q-1][r]),f[p][q][r-1]);
                }
            }
        }
        return f[n][m][k];
    }

    int main() {
        //code
        int t,i,n,m,k,j;
        char ch;
        cin>>t;
        for(i=0; i<t; i++)
        {
            cin>>n>>m>>k;
            string str1,str2,str3;
            for(j=0; j<n; j++)
            {
                cin>>ch;
                str1.push_back(ch);
            }
            for(j=0; j<m; j++)
            {
                cin>>ch;
                str2.push_back(ch);
            }
            for(j=0; j<k; j++)
            {
                cin>>ch;
                str3.push_back(ch);
            }
            cout<<lcs(str1,str2,str3,n,m,k)<<endl;
        }
        return 0;
    }

*/