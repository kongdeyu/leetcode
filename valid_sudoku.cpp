class Solution {
private:
    bool is_valid_row(std::vector<std::vector<char> > &board, int row, int col)
    {
        char ch = board[row][col];
        for(size_t idx = 0; idx < 9; idx++)
        {
            if(idx == col || board[row][idx] == '.')
            {
                continue;
            }
            
            if(board[row][idx] == ch)
            {
                return false;
            }
        }
        return true;
    }
    
    bool is_valid_col(std::vector<std::vector<char> > &board, int row, int col)
    {
        char ch = board[row][col];
        for(size_t idx = 0; idx < 9; idx++)
        {
            if(idx == row || board[idx][col] == '.')
            {
                continue;
            }
            
            if(board[idx][col] == ch)
            {
                return false;
            }
        }
        return true;
    }
    
    bool is_valid_square(std::vector<std::vector<char> > &board, int row, int col)
    {
        char ch = board[row][col];
        for(size_t i = 0; i < 3; i++)
        {
            for(size_t j = 0; j < 3; j++)
            {
                int cur_row = (row / 3) * 3 + i;
                int cur_col = (col / 3) * 3 + j;
                if((cur_row == row && cur_col == col) || board[cur_row][cur_col] == '.')
                {
                    continue;
                }
                
                if(board[cur_row][cur_col] == ch)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9)
        {
            return false;
        }
        
        for(std::vector<std::vector<char> >::const_iterator cit = board.begin();
            cit != board.end();
            cit++)
        {
            if(cit->size() != 9)
            {
                return false;
            }
        }
        
        for(size_t i = 0; i < 9; i++)
        {
            for(size_t j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                
                if(!is_valid_row(board, i, j) || !is_valid_col(board, i, j) || !is_valid_square(board, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
};