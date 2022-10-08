class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for(int i=0,j=1;j<grid[0].size();j++){
            grid[i][j]+=grid[i][j-1];
        }
        for(int j=0,i=1;i<grid.size();i++){
            grid[i][j]+=grid[i-1][j];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                if(gird[i-1][j]>grid[i][j-1]) grid[i][j]+=grid[i-1][j];
                else grid[i][j]+=gri[i][j-1];
            }

        }
        return grid[grid.size()-1][grid[0].size()-1];
        
    }
};