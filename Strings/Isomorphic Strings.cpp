class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2) {
        if(str1.size()!=str2.size())
        return false;
        vector<char>op1(256,'*');
        int n = str1.length();
        for(int i=0; i<n; i++){
            if(op1[str1[i]]=='*'){
                for(char x : op1){
                    if(x==str2[i]){
                        return false;
                    }
                }
                op1[str1[i]] = str2[i];
            }
            else{
                if(op1[str1[i]] != str2[i]){
                    return 0;
                }
            }
        }
        return 1;
    }
};
