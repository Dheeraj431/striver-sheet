//User function Template for C++
//TC O(n*m)
//SC O(n*m)
class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> matrix2 = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix2[i][j]==0){
                    int sum = 0;
                    if(i != 0){
                        sum += matrix2[i-1][j];
                        matrix[i-1][j] = 0;
                    }
                    
                    if( i != n-1){
                        sum += matrix2[i+1][j];
                        matrix[i+1][j] = 0;
                    }
                    
                    if(j != 0){
                        sum += matrix2[i][j-1];
                        matrix[i][j-1] = 0;
                    }
                    
                    if(j != m-1){
                        sum += matrix2[i][j+1];
                        matrix[i][j+1] = 0;
                    }
                    matrix[i][j]=sum;
                }
            }
        }
    }
};
