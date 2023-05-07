//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        
     
     map<int,int>mp;
     int sum =0,ans =0;
     mp[0]=1;
     for(int i=0; i<n; i++){
            sum += arr[i];
            ans += mp[sum-k];
            mp[sum]++;
     }
      return ans ;
    }
};
