#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isFeasible(vector<int> arr, int mid, int n, int c)
{
    int positiion = arr[0];
    int placed = 1;
    for(int i = 0; i<n; i++)
    {
        if (arr[i] - positiion >=mid)
        {
            positiion = arr[i];
            placed++;
            if(placed == c )return true;
        }
    }
    return false;
}
int largestMinDistance(vector<int> arr, int n, int c)
{
    sort(arr.begin(),arr.end());
    int anws = -1;
    int left= arr[0];
    int right = arr[n-1];
    while(left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(arr,mid,n,c))
        {
            anws = max(anws, mid);
            left = mid +1;
        }
        else right = mid;
    }
    return anws;
}
int main(){
    int T;
    cin >> T;
    for(int t =1; t<=T; t++)
    {
        vector<int> arr;
        int n, c;
        cin >> n >> c ;
        for(int i=0;i<n;i++)
        {
            int number;
            cin >> number;
            arr.push_back(number);
        }
        int anwser = largestMinDistance(arr,n,c);
        cout << anwser <<endl;
    }
}