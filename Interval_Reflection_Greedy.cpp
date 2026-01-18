/*
 * Problem: [Insolvable Disks] (2180-D)
 * Link: https://codeforces.com/contest/2180/problem/D
 * ------------------------------------------------------------------
 * Objective: 
 * Calculate the answer by maintaining a valid range [l, r] that 
 * satisfies the reflection constraints across the array elements.
 * * Key Algorithm: 
 * Constructive / Interval Sweeping
 * * Complexity: 
 * Time: O(N) - Single pass through the input array.
 * Space: O(N) - To store the input vector.
 * ------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip> 
#include <cassert> 
#include <climits>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;

void solve() {
    
    int n; cin >> n;
    vi x(n);
    for (auto& num: x) cin >> num;
    int ans = 1;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int l = x[0], r = x[1]; 
    for (int i = 1; i < n-1; i++) {
        r = 2*x[i]-r;
        l = 2*x[i]-l;
        swap(l, r);
        r = min(r, x[i+1]);
        if (l >= r) {
            l = x[i];
            r = x[i]+min(x[i]-x[i-1], x[i+1]-x[i]);
        }
        else ans++;
    }
    cout << ans << endl;

}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt; 
    while (tt--) {
        solve();
    }
 
    return 0;
}
