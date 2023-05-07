// TC(o(N*logN))
// SC(O(N))
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n){
        sort(arr,arr+n);
        if(n==1)
                return 1;
                
        vector<int>v;
        int prev_seen = -1;
        for(int i=0; i<n; i++){
            if(prev_seen != arr[i]){
                v.push_back(arr[i]);
            }
            prev_seen = arr[i];
        }
        int ans = 0,temp_cnt=0,i;
        for(i=0; i<v.size()-1; i++){
            if(v[i]+1 == v[i+1]){
                temp_cnt++;
            }
            else{
                ans = max(ans,temp_cnt);
                temp_cnt = 0;
            }
        }
        ans = max(ans,temp_cnt);
        ans++;
        return ans;
    }
};
