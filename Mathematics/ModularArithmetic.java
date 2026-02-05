public class ModularArithmetic {

    static final long MOD = 1000000007;

    // Modular Addition: (a + b) % m
    public long modAdd(long a, long b, long m) {
        return ((a % m) + (b % m)) % m;
    }

    // Modular Subtraction: (a - b) % m
    public long modSub(long a, long b, long m) {
        return ((a % m) - (b % m) + m) % m;
    }

    // Modular Multiplication: (a * b) % m
    public long modMul(long a, long b, long m) {
        return ((a % m) * (b % m)) % m;
    }

    // Modular Exponentiation: (base^exp) % m - O(log exp)
    public long modPow(long base, long exp, long m) {
        long result = 1;
        base = base % m;

        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % m;
            }
            exp >>= 1;
            base = (base * base) % m;
        }

        return result;
    }

    // Modular Inverse using Fermat's Little Theorem: a^(-1) = a^(m-2) % m
    // Only works when m is prime
    public long modInverse(long a, long m) {
        return modPow(a, m - 2, m);
    }

    // Modular Division: (a / b) % m = (a * b^(-1)) % m
    public long modDiv(long a, long b, long m) {
        return modMul(a, modInverse(b, m), m);
    }

    // GCD using Euclidean Algorithm
    public long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // LCM
    public long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    // Extended Euclidean Algorithm: Returns gcd and coefficients x, y
    // such that ax + by = gcd(a, b)
    public long[] extendedGCD(long a, long b) {
        if (b == 0) {
            return new long[]{a, 1, 0};  // gcd, x, y
        }

        long[] result = extendedGCD(b, a % b);
        long gcd = result[0];
        long x = result[2];
        long y = result[1] - (a / b) * result[2];

        return new long[]{gcd, x, y};
    }

    // nCr % m using Pascal's Triangle (for small n)
    public long nCrPascal(int n, int r, long m) {
        long[][] dp = new long[n + 1][r + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= Math.min(i, r); j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % m;
            }
        }

        return dp[n][r];
    }

    // nCr % m using Factorial and Modular Inverse (for large n)
    private long[] factorial;
    private long[] inverseFactorial;

    public void precomputeFactorials(int n, long m) {
        factorial = new long[n + 1];
        inverseFactorial = new long[n + 1];

        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % m;
        }

        inverseFactorial[n] = modInverse(factorial[n], m);
        for (int i = n - 1; i >= 0; i--) {
            inverseFactorial[i] = (inverseFactorial[i + 1] * (i + 1)) % m;
        }
    }

    public long nCr(int n, int r, long m) {
        if (r > n || r < 0) return 0;
        return (factorial[n] * inverseFactorial[r] % m) * inverseFactorial[n - r] % m;
    }

    // Euler's Totient Function: Count of numbers coprime to n
    public long eulerTotient(long n) {
        long result = n;

        for (long p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                while (n % p == 0) {
                    n /= p;
                }
                result -= result / p;
            }
        }

        if (n > 1) {
            result -= result / n;
        }

        return result;
    }

    // Check if prime
    public boolean isPrime(long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        ModularArithmetic ma = new ModularArithmetic();

        System.out.println("=== Modular Arithmetic ===");
        System.out.println("(5 + 3) % 7 = " + ma.modAdd(5, 3, 7));  // 1
        System.out.println("(5 - 3) % 7 = " + ma.modSub(5, 3, 7));  // 2
        System.out.println("(5 * 3) % 7 = " + ma.modMul(5, 3, 7));  // 1

        System.out.println("\n=== Modular Exponentiation ===");
        System.out.println("2^10 % 1000000007 = " + ma.modPow(2, 10, MOD));  // 1024
        System.out.println("2^100 % 1000000007 = " + ma.modPow(2, 100, MOD));

        System.out.println("\n=== Modular Inverse ===");
        System.out.println("3^(-1) % 7 = " + ma.modInverse(3, 7));  // 5 (since 3*5=15≡1 mod 7)

        System.out.println("\n=== GCD & LCM ===");
        System.out.println("GCD(48, 18) = " + ma.gcd(48, 18));  // 6
        System.out.println("LCM(48, 18) = " + ma.lcm(48, 18));  // 144

        System.out.println("\n=== Extended GCD ===");
        long[] ext = ma.extendedGCD(48, 18);
        System.out.println("48x + 18y = " + ext[0] + " where x=" + ext[1] + ", y=" + ext[2]);

        System.out.println("\n=== nCr (Combinations) ===");
        System.out.println("10C3 (Pascal) = " + ma.nCrPascal(10, 3, MOD));  // 120

        ma.precomputeFactorials(1000, MOD);
        System.out.println("10C3 (Factorial) = " + ma.nCr(10, 3, MOD));  // 120
        System.out.println("100C50 % MOD = " + ma.nCr(100, 50, MOD));

        System.out.println("\n=== Euler's Totient ===");
        System.out.println("φ(10) = " + ma.eulerTotient(10));  // 4
        System.out.println("φ(36) = " + ma.eulerTotient(36));  // 12

        System.out.println("\n=== Prime Check ===");
        System.out.println("Is 97 prime? " + ma.isPrime(97));  // true
        System.out.println("Is 100 prime? " + ma.isPrime(100));  // false
    }
}

/*
 * Modular Arithmetic Cheat Sheet
 *
 * Properties:
 * - (a + b) % m = ((a % m) + (b % m)) % m
 * - (a - b) % m = ((a % m) - (b % m) + m) % m
 * - (a * b) % m = ((a % m) * (b % m)) % m
 * - (a / b) % m = (a * b^(-1)) % m  (where b^(-1) is modular inverse)
 *
 * Modular Inverse (when m is prime):
 * - a^(-1) ≡ a^(m-2) (mod m)  [Fermat's Little Theorem]
 *
 * Important Formulas:
 * - nCr = n! / (r! * (n-r)!)
 * - nCr % m = (n! * (r!)^(-1) * ((n-r)!)^(-1)) % m
 *
 * Common MOD value: 10^9 + 7 = 1000000007 (prime)
 *
 * Time Complexities:
 * - Modular Exponentiation: O(log exp)
 * - GCD: O(log(min(a,b)))
 * - nCr with precomputation: O(1) query, O(n) precompute
 * - Euler Totient: O(√n)
 */
