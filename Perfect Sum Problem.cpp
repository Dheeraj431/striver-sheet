// Problem Link : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#define MOD 1000000007
class Solution{

	public:
	int f(int ind, int sum, int target, int arr[],vector<vector<int>>&dp){
	    if(ind==0){
	        if(sum==0){
	            if(arr[ind]==0)
	                return 2;
	            else
	                return 1;
	        }
	        else{
	            if(arr[ind]==sum)
	                return 1;
	            else
	                return 0;
	        }
	            
	    }
	    if(dp[ind][sum] != -1)
	        return dp[ind][sum];
	        
	    int take=0,not_take=0;
	    not_take += f(ind-1,sum, target, arr,dp);
	    if(sum>=arr[ind]){
	        take += f(ind-1, sum-arr[ind],target, arr,dp);
	    }
	    
	    return dp[ind][sum]=(take+not_take)%MOD;
	}
	int perfectSum(int arr[], int n, int sum){
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	    return f(n-1,sum,sum,arr,dp);
	}
	  
};
