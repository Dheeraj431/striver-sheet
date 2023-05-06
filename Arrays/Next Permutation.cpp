// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        if(n==1)
            return arr;
            
        int ind1 = n-2, ind2 = -1;
        for(ind1 ; ind1>=0; ind1--){
            if(arr[ind1]<arr[ind1+1])
                    break;
        }
        
        if(ind1<0){
            reverse(arr.begin(),arr.end());
        }
        else{
            for(ind2=n-1; ind2>=0 ; ind2--){
                if(arr[ind2]>arr[ind1]){
                    break;
                }
            }
            swap(arr[ind1],arr[ind2]);
            reverse(arr.begin()+ind1+1,arr.end());
        }
        return arr;
    }
};
