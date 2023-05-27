class Solution
{
    public:
    void g(int open, int close, int limit, string str, vector<string>&ans){
        if(open==limit && close==limit){
            ans.push_back(str);
            return;
        }
        if(open<limit){
            g(open+1, close, limit, str+'(', ans);
        }
        if(close<limit && open>close){
            g(open,close+1,limit,str+')',ans);
        }
    }
    vector<string> AllParenthesis(int n){ 
        int limit = n;
        string str = "";
        vector<string>ans;
        g(0,0,n,str,ans);
        return ans;
    }
};
