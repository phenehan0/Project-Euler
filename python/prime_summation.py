# Project Euler #10
import math
import time

def primesBelowN(N):
    i = 2
    j = 1
    res = 0
    results = []
    results = {i: False for i in range(2, N+1)}
    while i < int(math.sqrt(N))+1:
        j=1
        res=0
        while res <= N:
            res = i*j
            if (not (j == 1 and results[res] == False)) and res <= N:
                results[res] = True
            j += 1
        i += 1
    return results

def main(N, write_to_file=False):
    results = primesBelowN(N)
    idx = 1
    csv_str = ""
    sum = 0
    for i in results:
        if not results[i]:
            sum += i
            idx += 1
            if not write_to_file:
                continue
            csv_str += str(i)
            csv_str += ","
            if idx % 8 == 1:
                csv_str += '\n'
    if write_to_file:
        csv_str = csv_str[:-1]
        with open(f"primes_up_to_{N}.csv", "w+") as f:
            f.write(csv_str)
    return sum

if __name__ == "__main__":
    start = time.time()
    N = 2000000
    sum = main(N, write_to_file=0)
    print(sum)
    print(time.time() - start)