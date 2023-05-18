#include <bits/stdc++.h>
using namespace std;
#include <utility>

bool pairComparator(pair<int, int>& pair1, pair<int, int>& pair2) {
    if (pair1.second > pair2.second) {
        return true;
    }
    else if (pair1.second < pair2.second) {
        return false;
    }
    else {
        return pair1.first < pair2.first;
    }
}

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[v[i]]++;
        }
        vector<pair<int,int>>vp;
        for(auto x : mp){
            vp.push_back({x.first,x.second});
        }
        sort(vp.begin(),vp.end(),pairComparator);
        for(auto x:vp){
            for(int i=0; i<x.second; i++){
                cout<<x.first<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
