def minmax(N):
    """
    For some natual number N, find the minimum c
    that satisfies a + b + c = N where a, b, and c are distinct
    natural numbers.
    """
    if N % 3 == 1:
        max_a = (N-1)/3 - 1
        max_b = (N-1)/3
        min_c = (N-1)/3 + 2
    elif N % 3 == 2:
        max_a = (N+1)/3 - 2
        max_b = (N+1)/3
        min_c = (N+1)/3 + 1
    elif N % 3 == 0:
        max_a = (N/3) - 1
        max_b = N/3
        min_c = N/3 + 1
    return max_a, max_b, min_c

def factor_pairs(X, c):
    idx1 = 1
    idx2 = X-1
    result = []
    while idx1 <= idx2:
        if idx1 != idx2 and idx1 < c and idx2 < c:
            result.append((idx1, idx2))
        idx1 += 1
        idx2 -= 1
    return result

def main(N):
    max_c = N - 3
    max_a, max_b, min_c = minmax(N)
    a_b = 3
    c = max_c

    while a_b <= max_a + max_b and c >= min_c:
        pairs = factor_pairs(a_b, c)
        for a, b in pairs:
            if (a**2 + b**2 == c**2):
                return a,b,c
        a_b += 1
        c -= 1

if __name__ == "__main__":
    N = 1000
    result = main(N) 
    if result:
        a,b,c = result 
        assert a**2 + b**2 == c**2
        assert a + b + c == N
        print(a, b, c)
    

    



