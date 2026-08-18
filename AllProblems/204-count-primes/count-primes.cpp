class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        // isPrime[i] represents number (2*i + 1)
        int size = n / 2;
        vector<bool> isPrime(size, true);

        // index 0 represents number 1
        isPrime[0] = false;

        for (int i = 3; 1LL * i * i < n; i += 2) {

            if (isPrime[i / 2]) {

                for (long long j = 1LL * i * i; j < n; j += 2LL * i) {
                    isPrime[j / 2] = false;
                }
            }
        }

        int ans = 1; // prime number 2

        for (int i = 1; i < size; i++) {
            if (isPrime[i])
                ans++;
        }

        return ans;
    }
};