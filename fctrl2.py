# your code goes here

t = int(input())

def factr(n):
	ans = n
	while(n > 1):
		ans *= n-1
		n -= 1
	return ans

for _ in range(t):
	n = int(input())
	print(factr(n))