P = float(input())
T = float(input())

# P = H * (1 + T/100)
# Therefore H = P / (1 + T/100)
H = P / (1 + T/100)

print("%0.2f" % H)