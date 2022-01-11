class NumMatrix {
    
public:
    vector<vector<int>> psum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        psum = matrix;
        //for row sum
        for(int i =1 ; i < m ; i++)
        {
            psum[i][0] += psum[i-1][0];
        }
        //for col sum
        for(int i = 1  ; i <n; i++)
        {
            psum[0][i] += psum[0][i-1];
        }
        for(int i = 1 ;i<m; i++){
            for(int j =1;j < n; j++)
            {
                psum[i][j] += psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1];
            }
        }     
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans  = psum[row2][col2]  ;
        if(col1-1 >= 0)
        {
            ans = ans- psum[row2][col1-1];
        }
         if(row1-1 >= 0)
        {
            ans = ans - psum[row1-1][col2];
        }
         if(col1-1 >= 0 && row1-1 >= 0)
        {
            ans = ans + psum[row1-1][col1-1];
        }
                
       return ans;
            
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */