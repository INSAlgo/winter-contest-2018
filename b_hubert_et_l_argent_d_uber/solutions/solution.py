# In this solution we will use a dictionary, which is a Python associative
# array based on hashtables.
# See http://doc.pyschools.com/html/dictionary.html

M = int(input())
price = {}
for i in range(M):
    data = input().split()
    price[data[0]] = int(data[1])

N = int(input())
total = 0
for i in range(N):
    data = input().split()
    total += price[data[0]] * int(data[1])

print(total)