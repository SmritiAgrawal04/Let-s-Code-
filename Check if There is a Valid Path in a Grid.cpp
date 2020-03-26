/*Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.*/



class Solution {
public:
    bool util(int i, int j, int rows, int columns, vector<vector<bool>>& visit, vector<vector<int>>& grid, int current)
    {
        if(i< 0 || i>= rows || j< 0 || j>= columns || visit[i][j])
            return false;
        
        if((current == 1 && grid[i][j] ==2) || (current == 2 && grid[i][j] ==1))
            return false;
        
        if(i == rows-1 && j == columns-1)
            return true;
        
        visit[i][j]= 1;
        
        if(grid[i][j] ==1)
            return util(i, j+1, rows, columns, visit, grid, 1) || util(i, j-1, rows, columns, visit, grid, 1);
            
        if(grid[i][j] ==2)
            return util(i-1, j, rows, columns, visit, grid, 2) || util(i+1, j, rows, columns, visit, grid, 2);
                
        if(grid[i][j] ==3)
            return util(i+1, j, rows, columns, visit, grid, 3) || util(i, j-1, rows, columns, visit, grid, 3);
                    
        if(grid[i][j] ==4)
            return util(i, j+1, rows, columns, visit, grid, 4) || util(i+1, j, rows, columns, visit, grid, 4);
        
        if(grid[i][j] ==5)
            return util(i-1, j, rows, columns, visit, grid, 5) || util(i, j-1, rows, columns, visit, grid, 5);
        
        if(grid[i][j] ==6)
            return util(i, j+1, rows, columns, visit, grid, 6) || util(i-1, j, rows, columns, visit, grid, 6);
        
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows= grid.size();
        int columns= grid[0].size();
        
        vector<vector<bool>> visit;
        visit.resize(rows);
        for(int i=0 ;i < rows; i++)
        {
            visit[i].resize(columns);
            fill(visit[i].begin(), visit[i].end(), 0);
        }
        
        int i= 0, j= 0;
            
        return util(i, j, rows, columns, visit, grid, 0);
    }
};