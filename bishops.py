import sys
arr = sys.stdin.readlines()
for i in arr:
    if(int(i) == 1):
        print(1)
    else:
        print(int(i)*2 - 2)