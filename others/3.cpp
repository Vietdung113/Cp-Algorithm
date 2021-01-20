#include<bits/stdc++.h>
using namespace std;
int findMaxSum(vector<int> arr, int n, int L1, int L2)
{
    int maxSUM[n];
    maxSUM[n-1] = arr[n-1];
    for(int i =n-2; i >=0;i--)
    {
        // for (int k=L1; k<=L2;k++)
        // {
        int k =2;
        if(i+k+1>=n) maxSUM[i] = max(arr[i], maxSUM[i+1]);
        else maxSUM[i] = max(arr[i]+ maxSUM[i+k+1], maxSUM[1+i]);
        // }
    }
    return maxSUM[0];
}
int main()
{
    int T;
    cin >> T;
    for(int t=1; t<=T;t++)
    {
        int n;
        int L1, L2;
        vector<int> arr;
        cin >> n >> L1 >> L2;
        int tmp;
        for(int i =0; i< n; i++) 
        {
            cin >> tmp;
            arr.push_back(tmp);
        }
        int anws = findMaxSum(arr, n, L1, L2);
        cout << anws;
        cout << endl;
    }
}