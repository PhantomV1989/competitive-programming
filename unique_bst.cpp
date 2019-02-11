/*https://practice.geeksforgeeks.org/problems/unique-bsts/0/?ref=self
Unique BST's
Submissions: 8277   Accuracy:
48.1%   Difficulty: Medium   Marks: 4
Associated Course(s):   Interview Preparation   Geeks Classes in Noida More
Given an integer N, how many structurally unique binary search trees are there that store values 1...N?
Input:
First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.
Ouput:
For each testcase, in a new line, print the answer.
Constraints:
1<=T<=15
1<=N<=11
Example:
Input:
2
2
3
Output:
2
5
Explanation:
Testcase1:
for N = 2, there are 2 unique BSTs
     1               2
      \            /
       2         1
Testcase2:
for N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /           /    \      \
     3        2         1        1    3      2
    /       /                \                      \
   2      1               2                        3
** For More Input/Output Examples Use 'Expected Output' option **
*/
//2247
#include <cstdio>
#include <iostream>
using namespace std;

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int h(int sz)
{
    if (sz == 0 || sz == 1)
        return 1;
    if (sz == 2)
        return 2;
    int c = 0;
    for (int l = 0; l < sz; l++)
    {
        int r = sz - 1 - l;
        if (l == 1 && r == 1)
        {
            c += 1;
        }
        else
        {
            c += h(l) * h(r);
        }
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ll;
        cin >> ll;
        //your code
        cout << h(ll) << endl;
    }
    return 0;
}

/*
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ll;
        cin >> ll;
        //your code
        cout << h(ll) << endl;
    }
    return 0;
}



#include<iostream>
using namespace std;
int main()
 {
    int arr[12];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=11;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            sum+=arr[j]*arr[i-j-1];
        }
        arr[i]=sum;
    }
	int t;
	cin>>t;
	for(int ti=0;ti<t;ti++){
	    int n;
	    cin>>n;
	    cout<<arr[n]<<endl;
	}
	return 0;
}

a[i] stores number result for n=i. To calculate it, set numbers from 1 to i as root and calculate different bst with them as root and finally sum them. For example, let say, we want to calculate number of bst with j as root, where 1<=j<=i. Now, numbers from 1 to j-1 will come on left and from j+1 to i will come on right in bst. Now calculate number of bst with n=j-1 which is a[j-1] and with n=i-j-1 and multiply them. Hope it helps.*/