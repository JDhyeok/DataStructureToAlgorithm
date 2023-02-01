N = int(input())

fibo_dict = {0: 0, 1: 1, 2: 1}

def fibo(n):
    if fibo_dict.get(n) != None:
        return fibo_dict[n]
    else:
        fibo_dict[n] = fibo(n - 1) + fibo(n - 2)
        return fibo_dict[n]
print(fibo(N))