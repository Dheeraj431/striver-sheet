    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
            vector<int>ans;
            int curr_ldr = arr[n-1];
            for(int i=n-1; i>=0; i--){
                if(arr[i]>=curr_ldr){
                    ans.push_back(arr[i]);
                }
                curr_ldr = max(arr[i],curr_ldr);
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};
