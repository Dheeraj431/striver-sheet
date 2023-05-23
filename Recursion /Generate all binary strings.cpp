//User function Template for C++

class Solution{
public:
    void rec(int ind, int n, bool prev,string str){
        if(ind==n){
            cout<<str<<" ";
            return;
        }
        
        rec(ind+1,n,0,str+'0');
        if(prev==0){
            rec(ind+1,n,1,str+'1');
        }
    }
    void generateBinaryStrings(int num){
        string str="";
        rec(0,num,0,str);
    }
};
