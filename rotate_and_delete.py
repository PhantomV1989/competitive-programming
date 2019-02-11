'''
Given an array arr of N integers. Do the following operation n-1 times. For every Kth operation:

    Right rotate the array by 1.
    Delete the (n-k+1)th last element.

Which element is left at last.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains an integer N. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new line print the required result.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 107

Example:
Input
2
8
1 2 3 4 5 6 7 8
6
1 2 3 4 5 6

Output:
2
3

Explanation:
Testcase 2: A = {1,2,3,4,5,6}. Rotate the array clockwise i.e. after rotation the array A = {6,1,2,3,4,5} and delete the last element that is {5} so A = {6,1,2,3,4}. Again rotate the array for the second time and deletes the second last element that is {2} so A = {4,6,1,3}, doing these steps when he reaches 4th time, 4th last element does not exists so he deletes 1st element ie {1} so A={3,6}. So continuing this procedure the last element in A is {3}, so o/p will be 3.


'''


def h(a, p=-1):
    print(a)
    if len(a) > 1:
        new_a = [a[-1]] + a[:-1]
    else:
        return a[0]
    if abs(p) > len(new_a):
        p = 0
    new_a.pop(p)
    return h(new_a, p=0 if p == 0 else p-1)


# 2313
test_count = int(input())
for i in range(test_count + 1):
    size = int(input())
    problem = input().split(' ')
    print(h(problem))
# 2349


'''


#include <iostream>
using namespace std;

using namespace std;
int main()
{
    int T,k;
    cin>>T;
    for(k=0;k<T;k++)
    {
      int n;
    cin>>n;
    int arr[n],i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n==1)
        cout<<arr[0]<<endl;
    else if(n%2!=0)
    {
        cout<<arr[((n/2)+3)/2]<<endl;
    }
    else
        cout<<arr[((n/2)+1)/2]<<endl;
    }    
}
'''