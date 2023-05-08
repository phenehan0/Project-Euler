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
    long int x = 1;
    long int Y;
    int factors;
    while (max_factors <= 500) {
        Y = x*x + x;
        factors = factor_pairs(Y/2);
        if (factors > max_factors) {
            max_factors = factors;
        };
        if (max_factors > 500) {
            cout << "result: " << Y / 2 << '\n';
            time_t  t2 = time(0);
            cout << "seconds elapsed: " << t2 - t1;
            return 0;
        };
        x++;
    };
    return 0;
};