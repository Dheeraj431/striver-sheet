// Link https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size){
        int res=0,count=0,n=size;
        for(int i=0; i<n; i++){
            if(count==0)
                res = arr[i];
            if(res==arr[i])
                count++;
            else
                count--;
                
        }
        count = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==res)
                count++;
        }
        if(count>n/2)
            return res;
        else
            return -1;
    }
};
