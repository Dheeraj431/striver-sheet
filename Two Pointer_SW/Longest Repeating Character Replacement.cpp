//Problem Link:https://practice.geeksforgeeks.org/problems/longest-repeating-character-replacement/1
class Solution {
  public:
    int characterReplacement(string str, int k) {
        int i=0,j=0,n=str.length();
        int mx=0,ans=0;
        vector<int>v(26,0);
        while(j<n){
            v[str[j]-'A']++;
            if(mx<v[str[j]-'A']){
                mx=max(mx,v[str[j]-'A']);
            }
            while(j-i+1-mx>k){
                v[str[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
