N = int(input())

nums = []
freq = {}

for _ in range(N):
    tmp = int(input())
    nums.append(tmp)
    freq[tmp] = freq.get(tmp, 0) + 1
    
nums = sorted(nums)
max_val = max(freq.values())

max_freq = []

for k, v in freq.items():
    if v == max_val:
        max_freq.append(k)

max_freq = sorted(max_freq)
max_freq_val = max_freq[0]

if len(max_freq) > 1:
    max_freq_val = max_freq[1]

print(round(float(sum(nums) / N)))
print(nums[N // 2])
print(max_freq_val)
print(nums[-1] - nums[0])