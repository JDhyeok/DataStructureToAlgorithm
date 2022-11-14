def solution(elements):
    answer = 0

    N = len(elements)
    elements = elements + elements
    ret = []

    for i in range(1, N + 1):
        for j in range(N):
            sum_ = sum(elements[j:j + i])
            ret.append(sum_)
    ret = list(set(ret))

    return len(ret)