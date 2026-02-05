package NumberTheory;

public class BigMod {
    
    private static int bigMod(int a, int b, int k) {
        if(b == 0) return 1 ;

        if((b & 1) == 0){
            int res = bigMod(a, b >> 1, k);
            return((res % k) * (res % k)) % k;
        }
        return (a % k * bigMod(a, b - 1, k) % k) % k;
        
    }
    public static void main(String[] args) {
        int base=2;
        int power=5;
        int mod= 7;
        System.out.println(bigMod(base, power, mod)); 
        
    }
}
