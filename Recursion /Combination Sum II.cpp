// User function Template for C++
// Problem Link : https://practice.geeksforgeeks.org/problems/combination-sum-ii/1
class Solution {
  public:
    void findcombs(int ind, int target, vector<int>arr, vector<int>&ds, vector<vector<int>>&combs){
        
        if(target==0){
            combs.push_back(ds);
            return;
        }
        else{ 
            for(int i=ind; i<arr.size(); i++){
                if(i>ind && arr[i-1]==arr[i])continue;
                if(arr[i]>target)break;
                ds.push_back(arr[i]);
                findcombs(i+1,target-arr[i],arr,ds,combs);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        vector<int>ds;
        vector<vector<int>>combs;
        sort(candidates.begin(),candidates.end());
        findcombs(0,target,candidates,ds,combs);
        return combs;
    }
};
