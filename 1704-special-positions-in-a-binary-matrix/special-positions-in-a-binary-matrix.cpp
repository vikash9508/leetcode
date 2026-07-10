class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<int>rowcount(n,0);
        vector<int>colcount(m,0);
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(mat[row][col]==1){
                    rowcount[row]++;
                    colcount[col]++;
                }
            }
        }
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(mat[row][col]==1 &&rowcount[row]==1 && colcount[col]==1)
                {
                    result++;
                }
            }
        }
        return result;
    }
};