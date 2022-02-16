import sys

n, m = map(int, input().split())
ans = 1

if(n==m):
	print(1)
	sys.exit(0)

for i in range(m):
	ans *= (n - i)
	ans //= (i+1)

print(ans)