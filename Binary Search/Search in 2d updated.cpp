//last elemt of eachh row is greate than the starting element of next row 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n=arr.size();
        int m=arr[0].size();
        int low=0, high=m*n-1;
				while(low<=high){
						int mid=(low+high)/2;
						int ele = arr[mid/m][mid%m];
						if(ele>x){
								high = mid-1;
						}
						else if(ele<x){
								low = mid+1;
						}
						else
								return 1;
				}
				return false;
    	}
			
};
