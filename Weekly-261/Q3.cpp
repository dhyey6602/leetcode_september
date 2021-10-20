class Solution {
    public boolean stoneGameIX(int[] stones) {
        int[] f = new int[3];
        for(int v : stones){
            f[v%3]++;
        }
        for(int i = 1;i <= 2;i++){
            if(f[i] == 0)continue;
            if(f[0] % 2 == 0){
                if(f[i]-1 < f[3-i])return true;
            }else{
                if(f[i]-2 > f[3-i])return true;
            }
        }
        return false;
    }
}