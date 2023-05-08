#include<bits/stdc++.h>

using namespace std;
int a[10] = {1,5,345,5,23,4,56,7,324,4};
int binary_search(int x, int l, int r)
{
    // cout << "l: " << l << "\tr: " << r <<"\ta[l]: " <<a[l] << "\ta[r]: " << a[r] << endl;
    if (l > r) {
        return -1;
    }
    int mid = l + r / 2;
    if (a[mid] == x) return mid;

    if (a[mid]  > x) {
        return binary_search(x, l, mid -1);
    }
    else 
    {
        return binary_search(x, mid +1, r);
    }
}
int main()
{
    sort(a, a+10);
    // for (int i =0 ; i<10; i++) {
    //     cout << a[i] << endl;
    // }
    cout << binary_search(5, 0, 9);
    

}