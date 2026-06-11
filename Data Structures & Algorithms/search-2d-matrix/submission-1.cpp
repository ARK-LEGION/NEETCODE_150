class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0, r=n-1;
        // int row=-1;
        while (l<r){
            int mid=(l+r)/2;
            if (matrix[mid][m-1]<target) l=mid+1;
            else {
                r=mid;
            }   
        }
        int row = l;
        if (l==n || matrix[l][0]>target) return false;
        
        int col= lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
        if (col<m && matrix[row][col]==target) return true;
        return false;

    }
};
