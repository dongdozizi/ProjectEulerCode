def tau(n):
    """Return the number of divisors of n."""
    count = 0
    # 这里用简单的sqrt(n)方法减少时间复杂度
    # 对于更大的 n，建议用质因分解方法获取约数数目
    limit = int(n**0.5)
    for i in range(1, limit+1):
        if n % i == 0:
            count += 2
    # 如果 n 是一个完全平方数，则前面多加了一个约数，需要减1
    if limit * limit == n:
        count -= 1
    return count

def m(k):
    """Find the smallest tau number x such that tau(x) = k."""
    x = k  # 从 k 开始搜索，因为 x 必须被 k 整除
    N=1000
    while x<=N:
        if tau(x) == k and x % k == 0:
            return x
        x += k  # 直接以 k 为步长增加，因为 x 必须被 k 整除
    if x>N:
        return 0
    else:
        return x
sum=0
for i in range(1,100):
    pp=m(i)
    if pp==0:
        continue
    sum+=pp
    print(i,pp)
print(sum)
