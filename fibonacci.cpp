# include <iostream>
# include <cstdlib>
# include <stdio.h> 
# include <string>

using namespace std;

//Project Euler #2 -- Even Fibonacci Numbers

int even_fibonacci_sum(int a, int b, int sum, long int max_val) {
    if (sum + (a + b) > max_val && ((a + b) % 2 == 0)) {
        return sum;
    } else {
        if ((a + b) % 2 == 0){
            sum = sum + (a + b);
        };
        cout << a + b << "\n";
        cout << "Sum of even terms is: "<<sum << "\n";
        even_fibonacci_sum(b, a + b, sum, max_val);
    };
}

int main(int argc, char *argv[]) {
    
    char* endptr;
    long int max = strtol(argv[1], &endptr, 10);
    cout << "max is: "<< max <<'\n';
    cout << " "<<argc << " " <<argv;
    int result = even_fibonacci_sum(0, 1, 0, max);
    cout << "Result is: " << result;
    return result;
};