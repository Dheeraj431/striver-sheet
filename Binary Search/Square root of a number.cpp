long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long low = 1, high = x;
        while(low<=high){
            long long  mid = (low+high)/2;
            if(mid*mid<=x && (mid+1)*(mid+1)>x){
                return mid;
            }
            else if(mid*mid>x){
                high = mid-1;
            }
            else
                low = mid+1;
        }
    }
