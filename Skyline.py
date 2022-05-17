def BinominalCoefficient(n,k):
    res = 1;
    if (k > n - k):
        k = n - k
    for i in range(k):
        res *= (n - i)
        res /= (i + 1)
    return res
def CatalanNumbers(n):
   c = BinominalCoefficient(2*n, n)
   return (c//(n+1))
i=0
variable = []
while i<1001:
   variable.append(int(CatalanNumbers(i)))
   i+=1
x = input()
while x != 0:
   print (int(variable[x])) % 1000000
   x = input()
