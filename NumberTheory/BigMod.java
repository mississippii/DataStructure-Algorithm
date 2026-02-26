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

    static int bigFactorial(int n, int m) {
        int fact = 1;

        for(int i=1 ;i<=n ; i++) {
            fact = ((fact%m)*(i%m))%m;
        }
        return fact;
    }
    public static void main(String[] args) {
        int val = power(2, 10, 1000);
        int reminder = bigFactorial(55, 101);
        System.out.println("Power: " + val);
        System.out.println("Reminder: " + reminder);    
    }
}
