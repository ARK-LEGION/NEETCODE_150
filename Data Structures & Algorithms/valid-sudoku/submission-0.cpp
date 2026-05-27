class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++){
            vector<int> temp(10);
            for (int j=0; j<9; j++){
                if (board[i][j]!='.'){
                    temp[board[i][j]-'0']++;
                    if (temp[board[i][j]-'0']>1) return false;
                }
            }
        }

        for (int j=0; j<9; j++){
            vector<int> temp(10);
            for (int i=0; i<9; i++){
                if (board[i][j]!='.'){
                    temp[board[i][j]-'0']++;
                    if (temp[board[i][j]-'0']>1) return false;
                }               
            }
        }

        for (int i=0; i<9; i+=3){
            for (int j=0; j<9; j+=3){
                vector<int> temp(10,0);
                for (int k=0; k<3; k++){
                    for (int k2=0; k2<3; k2++){
                        if (board[i+k2][j+k]!='.'){
                            temp[board[i+k2][j+k]-'0']++;
                            if (temp[board[i+k2][j+k]-'0']>1) return false;
                        }
                    }
                }

            }
        }
        return true;
    }
};
