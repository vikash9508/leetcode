class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    bool special=true;
                    for(int r=0;r<n;r++)
                    {
                        if(r!=i &&mat[r][j]==1){
                        special=false;
                        break;
                        }
                    }
                     for(int c=0;c<m;c++)
                    {
                        if(c!=j &&mat[i][c]==1){
                        special=false;
                        break;
                        }
                    }
                    if(special)
                    result++;
                }
            }
        }
        return result;

    }
};