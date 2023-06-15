#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const ll MOD = 1e9 + 7;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    ll n, m;
    cin >> n >> m;

    vector<ll> nums(n);
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    ll z0;
    cin >> z0;

    if (z0 == 0) {
        for (ll i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][z0] = 1;
    }

    for (ll i = 1; i < n; i++) {
        cin >> nums[i];
        if (nums[i] == 0) {
            for (ll val = 1; val <= m; val++) {
                if (val + 1 <= m) {
                    dp[i][val] = (dp[i][val] + dp[i - 1][val + 1]) % MOD;
                }
                if (val - 1 >= 1) {
                    dp[i][val] = (dp[i][val] + dp[i - 1][val - 1]) % MOD;
                }
                dp[i][val] = (dp[i][val] + dp[i - 1][val]) % MOD;
            }
        } else {
            if (nums[i] - 1 >= 1) {
                dp[i][nums[i]] = (dp[i][nums[i]] + dp[i - 1][nums[i] - 1]) % MOD;
            }
            if (nums[i] + 1 <= m) {
                dp[i][nums[i]] = (dp[i][nums[i]] + dp[i - 1][nums[i] + 1]) % MOD;
            }
            dp[i][nums[i]] = (dp[i][nums[i]] + dp[i - 1][nums[i]]) % MOD;
        }
    }

    ll tot_ways = 0;
    for (ll i = 1; i <= m; i++) {
        tot_ways = (tot_ways + dp[n - 1][i]) % MOD;
    }

    cout << tot_ways << endl;
    return 0;
}
