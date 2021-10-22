class Solution {
    public long solution(int w, int h) {
        long answer = 1;
        
        long W = Integer.valueOf(w).longValue();
        long H = Integer.valueOf(h).longValue();
        
        answer = W * H - (W + H - gcd(W,H));
        
        return answer;
    }
    
    long gcd(long w, long h){
        long big = Math.max(w, h);
        long small = Math.min(w, h);
        
        while(small != 0){
            long tmp = big % small;
            big = small;
            small = tmp;
        }
        
        return big;
    }
}