package NumberTheory;

public class BigMod {
    
    private static int power(int a, int b, int k) {
        if(b == 0) return 1 ;

        if((b & 1) == 0){
            int res = power(a, b >> 1, k);
            return((res % k) * (res % k)) % k;
        }
        return (a % k * power(a, b - 1, k) % k) % k;
        
    }

    
    public static void main(String[] args) {
        int base=2;
        int power=5;
        int mod= 7;
        System.out.println(power(base, power, mod)); 
        
    }
}
