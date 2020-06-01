//Python Soln

def a(t, m):
    count = 0
    for t in range(t,t+m):
        count=count+t
    return count


def calc(c, n):
    dif = c
    f=c//n
    for i in range(f, 0, -1):
      s = a(i, n)
      if s <= c:
        dif=c-s
        break
    print(dif)

t = int(input())
for j in range(0, t):
    c, n = map(int, input().split())
    calc(c, n)
