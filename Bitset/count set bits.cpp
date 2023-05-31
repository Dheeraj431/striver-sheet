//User function Template for C++
//Problem Link : https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n){
        int num = n,ans=0,i=1;
        while(num!=0){
            int temp = (n+1)/(i*2);
            ans+=temp*i;
            temp=(n+1)/i;
            if(temp%2==1){
                ans+=(n+1)%i;
            }
            i*=2;
            num/=2;
        }
        return ans;
    }
};
