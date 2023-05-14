class Solution {
  public:
    bool isGood(int mid, int m, int k,vector<int>arr){
        int n = arr.size();
        int num_bq = 0;
        int curr=0;
        for(int i=0; i<n; i++){
            if(curr==k){
                    num_bq++;
                    curr = 0;
            }
            if(arr[i]<=mid){
                curr++;
            }
            else{
                curr = 0;
            }
            
            
            if(num_bq>=m){
                return true;
            }
        }
        
        if(curr==k){
                    num_bq++;
                    curr = 0;
        }
        if(num_bq>=m){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(int M, int K, vector<int> &bloomDay){
        if(bloomDay.size()<M*K)
            return -1;
        int n= bloomDay.size();
        int low = 1, high = (int)1e9;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(isGood(mid,M,K,bloomDay)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(ans != INT_MAX)
        return ans;
        else
        return -1;
    }
};
