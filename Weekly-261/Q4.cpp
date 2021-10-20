class Solution {
    public String smallestSubsequence(String S, int k, char letter, int repetition) {
        char[] s = S.toCharArray();
        int n = s.length;
        int[] f = new int[n+1];
        for(int i = n-1;i >= 0;i--){
            f[i] = f[i+1] + (s[i] == letter ? 1 : 0);
        }
        int[][] next = makeFatNext(s, 'a', 'z');
        char[] ret = new char[k];
        int pos = 0;
        int rem = repetition;
        outer:
        for(int p = 0;p < k;p++){
            for(int i = 0;i < 26;i++){
                int nex = next[i][pos];
                if(nex >= n+1-(k-1-p))continue;
                int lrem = rem - (letter-'a' == i ? 1 : 0);
                if(f[nex] < lrem || lrem > k-1-p)continue;
                ret[p] = (char)('a'+i);
                rem = lrem;
                pos = nex;
                continue outer;
            }
            throw new RuntimeException();
        }
        return new String(ret);
    }
    
	int[][] makeFatNext(char[] s, char inf, char sup)
	{
		int n = s.length;
		int[][] next = new int[sup-inf+1][n+1];
		for(int i = 0;i < sup-inf+1;i++)next[i][n] = n+1;
		for(int i = s.length-1;i >= 0;i--){
			for(int j = 0;j < sup-inf+1;j++)next[j][i] = next[j][i+1];
			next[s[i]-inf][i] = i+1;
		}
		return next;
	}
}