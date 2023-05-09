// #define ll long long

class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        ll mod = 1e9+7;
        vector<vector<ll>> v(n, vector<ll>(n, 0));
        v[0][0] = 1;
        vector<ll>ans;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<=i; j++){
                if(j==0 || j==i){
                    v[i][j] = 1;
                }
                else{
                    v[i][j] = (v[i-1][j-1] + v[i-1][j])%mod;
                }
                if(i==n-1){
                    ans.push_back(v[i][j]);
                }
            }
            
        }
        return ans;
        
    }
};
