//Problem Link : http://www.usaco.org/index.php?page=viewproblem2&cpid=694
#include<bits/stdc++.h>
#define ll long long  
using namespace std;

#define HOFF 0
#define PAPER 1
#define SCISSOR 2
int addon(int a, int b){
    if(a==HOFF && b==SCISSOR){
        return 1;
    }
    else if(a==SCISSOR && b==PAPER){
        return 1;
    }
    else if(a==PAPER && b==HOFF){
        return 1;
    }
    else{
        return 0;
    }
}
int solve(){
        ll n,k;
        cin>>n>>k;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            char move;
            cin>>move;
            if(move=='P'){
                v[i]=1;
            }
            else if(move=='S'){
                v[i]=2;
            }
        }
        int ans=-1;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 2, vector<int>(3, 0)));
        for(int ind=1; ind<=n; ind++){
                for(int swap=1; swap<=k+1; swap++){
                        int add=addon(HOFF,v[ind]);
                        dp[ind][swap][HOFF]=max(dp[ind-1][swap][HOFF]+add,max(dp[ind-1][swap-1][PAPER]+add,dp[ind-1][swap-1][SCISSOR]+add));

                        add=addon(PAPER,v[ind]);
                        dp[ind][swap][PAPER]=max(dp[ind-1][swap][PAPER]+add,max(dp[ind-1][swap-1][HOFF]+add,dp[ind-1][swap-1][SCISSOR]+add));

                        add=addon(SCISSOR,v[ind]);
                        dp[ind][swap][SCISSOR]=max(dp[ind-1][swap][SCISSOR]+add,max(dp[ind-1][swap-1][PAPER]+add,dp[ind-1][swap-1][HOFF]+add));

                        if(ind==n){
                        ans=max(dp[ind][swap][HOFF],max(dp[ind][swap][PAPER],dp[ind][swap][SCISSOR]));
                    }
                }
                
        }
        cout<<ans<<endl;
        return 0;
}
int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

        solve();
        return 0;
}
