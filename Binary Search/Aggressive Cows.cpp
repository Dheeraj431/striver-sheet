// User function Template for C++

class Solution {
public:
    
    bool good(int mid, int k, vector<int>v){
        int n = v.size();
        int i=1, cow = 1, prev_cow = v[0];
        while(i<n && cow<k){
            if(v[i]-prev_cow>=mid){
                prev_cow = v[i];
                cow++;
                i++;
            }
            else{
                i++;
            }
        }
        
        if(cow>=k)
            return true;
        else
            return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=1, high = INT_MAX , ans = INT_MIN;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(good(mid,k,stalls)){
                ans = max(mid,ans);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
