class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int s = 0;
        for(int v : rolls){
            s += v;
        }
        int tot = mean * (rolls.length + n);
        int cha = tot - s;
        if(cha >= n && cha <= 6*n){
            int[] ret = new int[n];
            Arrays.fill(ret, 1);
            cha -= n;
            for(int i = 0;i < n;i++){
                int u = Math.min(cha, 5);
                ret[i] += u;
                cha -= u;
            }
            return ret;
        }else{
            return new int[0];
        }
    }
}