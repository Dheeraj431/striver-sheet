//Problem Link : https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        int m=(int)1e9+7;
        for(int i=0; i<n; i++){
            arr[i]=arr[i]+(arr[arr[i]]%m)*m;
            
        }
        for(int i=0; i<n; i++){
            arr[i]=arr[i]/m;
        }
    }
};
