//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &arr, int n, int m, int x)
	{
	    // your code here
	    int i=0,j=m-1;
	    while(i<n && j>=0){
	        if(arr[i][j]==x)
	            return true;
	        else if(arr[i][j]>x)
	            j--;
	        else
	            i++;
	    }
	    return false;
	}
};
