class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        vector<set<char>>rows(9),cols(9),box(9);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                //rows no repeat
                //cols no repeat 
                //box no repeat
                
                char k=board[i][j];
                
                //compute box number
                int boxid=i/3; //row
                boxid += (j/3)*3; //col
                
                if(rows[i].find(k)!=rows[i].end() 
                   or cols[j].find(k)!=cols[j].end() 
                   or box[boxid].find(k)!=box[boxid].end())
                    return false;
                
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                box[boxid].insert(board[i][j]);
                    
            }
        }
        return true;
    }
};