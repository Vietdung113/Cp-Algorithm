#include <iostream>
#include <algorithm>
using namespace std;

static int arr[10000001];
static int dq[10000001];   // array-based deque: holds INDICES into arr
                           // head/tail as ints -- no push/pop method overhead

// Returns the XOR of the minimum of every window of length k.
// arr[0..n-1] is already filled in.
long long solve(int n, int k) {
    int head = 0, tail = 0;      // dq[head..tail-1], strictly increasing arr values
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        // drop back elements that can never be a minimum again
        while (head < tail && arr[dq[tail - 1]] >= arr[i]) tail--;

        dq[tail++] = i;

        // front expired: window is [i-k+1 .. i], so index i-k is out
        if (dq[head] <= i - k) head++;

        if (i >= k - 1) ans ^= arr[dq[head]];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long long x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    arr[0] = (int)x;
    long long prev = x;
    for (int i = 1; i < n; i++) {
        prev = (a * prev + b) % c;   // a*prev can exceed 2^31 -> long long is required
        arr[i] = (int)prev;
    }

    cout << solve(n, k) << '\n';
    return 0;
}
