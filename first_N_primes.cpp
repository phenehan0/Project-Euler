# include <vector>
# include <iostream>
# include <bits/stdc++.h>

using namespace std;

void SieveofEratosthenes(vector<long int> &primes, long int &N, long int &offset) {
    long int max_prime_idx = primes.size() -1;
    long int max_prime = primes[max_prime_idx];
    bool is_prime;
    vector<tuple<long int,bool>> sieve = {};

    for (long int i=offset+1; i < offset*2; i++) {
        sieve.push_back({i, true});
    };

    for (int j=0; j < sieve.size(); j++) {
        is_prime = true;
        for (long int k=0; k < max_prime_idx; k++) {
            if (get<0>(sieve[j]) % primes[k] == 0) {
                is_prime = false;
                get<1>(sieve[j]) = false;
            };
        };
        if (is_prime) {
            primes.push_back(get<0>(sieve[j]));
            if (primes.size() >= N) {
                return;
            };
        };
    };
};

int main(int argc, char* argv[]) {
    char* endptr;
    long int N = strtol((argv)[1], &endptr, 10);
    cout << "Generating first " << N << " prime numbers...\n";
    vector<long int> primes = {};
    primes.push_back(2);
    long int offset = 1;
    vector<tuple<long int, bool>> sieve = {{1, false}};
    while (primes.size() < N) {
        SieveofEratosthenes(primes, N, offset);
        offset = primes[primes.size()-1];
    };
    for (long int i=0; i < primes.size(); i++) {
        cout << primes[i];
        if (i < primes.size()-1) {
            cout << ',';
        };
        if (i % 20 == 0 && i > 1) {
            cout << '\n';
        };
    };
};