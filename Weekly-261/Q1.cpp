class Solution {
    public int minimumMoves(String S) {
        char[] s = S.toCharArray();
        int ret = 0;
        for(int i = 0;i < s.length;i++){
            if(s[i] == 'X'){
                for(int j = i;j < i+3 && j < s.length;j++){
                    s[j] = 'O';
                }
                ret++;
            }
        }
        return ret;
    }
}