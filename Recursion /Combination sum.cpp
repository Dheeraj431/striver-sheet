//User function template for C++

class Solution {
  public:
    void rec(int ind, int target, vector<int>&arr,vector<vector<int>>&combs,vector<int>&ds){
        if(ind>=arr.size()){
            if(target==0){
                combs.push_back(ds);
            }
            return;
        }
        
        if(target>=arr[ind]){
            ds.push_back(arr[ind]);
            rec(ind,target-arr[ind],arr,combs,ds);
            ds.pop_back();
        }
        rec(ind+1,target,arr,combs,ds);
        
    }
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<vector<int>>ans;
        vector<int>ds;
        rec(0,B,A,ans,ds);
        return ans;
    }
};
