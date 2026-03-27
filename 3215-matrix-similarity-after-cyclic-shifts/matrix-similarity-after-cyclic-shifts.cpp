class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>curr = mat;

        k = k%n;
        for(int i=0; i<m; i++){
            if(i%2==0){
                reverse(mat[i].begin(), mat[i].begin()+k);
                reverse(mat[i].begin()+k, mat[i].end());
                reverse(mat[i].begin(), mat[i].end());
            }
            else{
                reverse(mat[i].begin()+k, mat[i].end());
                reverse(mat[i].begin(), mat[i].begin()+k);
                reverse(mat[i].begin(), mat[i].end());
            }
        }

        return curr==mat;
    }
};