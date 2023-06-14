//Problem Link : https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0; i<n; i++){
            dp[i][i]=1;
        }
        int start=0;
        int maxLength=1;
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                if (2 > maxLength) {
                        start = i;
                        maxLength = 2;
                }
            }
        }
        for(int len=3; len<=n; len++ ){
            for(int i=0; i<n-len+1; i++){
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        return s.substr(start,maxLength);
    }
};
