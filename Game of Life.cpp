/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows= board.size(), cols= board[0].size();
        vector<vector<int>> result= board;
        int right, left, up, down, r_d, r_u, l_d, l_u;
        int count_0, count_1;
        
        for (int i=0 ;i < rows; i++)
        {
            for (int j=0; j < cols; j++)
            {
                count_0 =0;
                count_1 =0;
                
                right= j < cols-1 ? board[i][j+1] : -1;
                if(right ==0)
                    count_0++;
                else if(right ==1)
                    count_1++;
                left= j >0 ? board[i][j-1] : -1;
                if(left ==0)
                    count_0++;
                else if(left ==1)
                    count_1++;
                
                down= i < rows- 1 ? board[i+1][j] : -1;
                if(down ==0)
                    count_0++;
                else if(down ==1)
                    count_1++;
                up= i >0 ? board[i-1][j] : -1;
                if(up ==0)
                    count_0++;
                else if(up ==1)
                    count_1++;
                
                r_d= j < cols-1 && i < rows- 1 ? board[i+1][j+1] : -1;
                if(r_d ==0)
                    count_0++;
                else if(r_d ==1)
                    count_1++;
                r_u= j < cols-1 && i >0 ? board[i-1][j+1] : -1;
                if(r_u ==0)
                    count_0++;
                else if(r_u ==1)
                    count_1++;
                
                l_d= j >0 && i < rows- 1 ? board[i+1][j-1] : -1;
                if(l_d ==0)
                    count_0++;
                else if(l_d ==1)
                    count_1++;
                l_u= j >0 && i >0 ? board[i-1][j-1] : -1;
                if(l_u ==0)
                    count_0++;
                else if(l_u ==1)
                    count_1++;
                
                
                if (board[i][j] ==0 && count_1 ==3)
                    result[i][j] = 1;
                
                if(board[i][j] ==1 && count_1 <2)
                    result[i][j] =0;
                
                if(board[i][j] ==1 && count_1 >3)
                    result[i][j] =0;
            }
        }
        board= result;
    }
};