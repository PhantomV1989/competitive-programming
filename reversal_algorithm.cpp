/*


Given an array of N size. The task is to rotate array by d elements where d is less than or equal to N.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of three lines. The first line of each test case consists of an integer N, where N is the size of array.
The second line of each test case contains N space separated integers denoting array elements. The third line of each test case contains "d" .

Output:
Corresponding to each test case, in a new line, print the modified array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 200
1 ≤ A[i] ≤ 1000

Example:
Input
1
5
1 2 3 4 5
2

Output
3 4 5 1 2
** For More Input/Output Examples Use 'Expected Output' option **

*/
//Note:never ever hardcode, endl for every test case, check length==1
// 1303
#include <iostream>
using namespace std;

int main()
{
    int T, t;
    cin >> T;
    for (t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        int arr[n], tarr[n], i, d;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> d;
        if (n == 1)
            cout << arr[0];
        else
        {
            for (i = 0; i < n; i++)
            {
                if (i + d < n)
                    cout << arr[i + d];
                else
                    cout << arr[i - n + d];
                cout << ' ';
            }
        }
        cout << endl;
    }
}
//1352