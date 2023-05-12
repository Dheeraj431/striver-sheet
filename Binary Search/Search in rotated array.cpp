class Solution{
    public:
    int search(int arr[], int l, int h, int key){
        int low = l,high = h;
        while(low<=high){
            int mid = low + (high-low)/2;
            // left side is sorted;
            
            if(arr[mid]==key)
                return mid;
             if(arr[mid]==arr[low] && arr[high]==arr[mid]){
                low++;
                high--;
              }
             else if(arr[low]<=arr[mid]){
                if(key>=arr[low] && key<=arr[mid]){
                    high=mid-1;
                }
                 
                else{
                    low = mid+1;
                }
            }
            //right side is sorted
            else{
                if(arr[mid]<=key && arr[high]>=key){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
