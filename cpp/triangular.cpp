# include <vector>
# include <iostream>
# include <ctime>

using namespace std;

int factor_pairs(long int N) {
    long int i = 1;
    long int j = N;
    int f_cnt = 0;
    while (i <= j) {
        if (N % i == 0 && N % j == 0) {
            if ( i == j) {
                f_cnt ++;
            } else {
                f_cnt = f_cnt + 2;
            };
        }
        i++;
        j = N / i;
    };
    return f_cnt;
};
 
int main() {
    time_t  t1 = time(0);
    int max_factors = 0;
    long int X;
    int factors;
    for (long int i=1; i<1000000; i++) {
        X = i*i + i;
        factors = factor_pairs(X/2);
        if (factors > max_factors) {
            max_factors = factors;
        };
        if (max_factors > 500) {
            // cout << i << ' ' << X << ' ' << ' ' << X / 2 << '\n';
            cout << "result: " << X / 2 << '\n';
            time_t  t2 = time(0);
            cout << "seconds elapsed: " << t2 - t1;
            return 0;
        };
    };
    return 0;
};