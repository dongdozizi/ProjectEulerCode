from math import gcd
from functools import reduce

class Equa:
    def __init__(self, nm=0, n5=0):
        self.nm = nm  # Coefficient of 1
        self.n5 = n5  # Coefficient of sqrt(5)

    def __mul__(self, other):
        return Equa(
            self.nm * other.nm + 5 * self.n5 * other.n5,
            self.n5 * other.nm + self.nm * other.n5
        )

    def __add__(self, other):
        return Equa(
            self.nm + other.nm,
            self.n5 + other.n5
        )

class Node:
    def __init__(self, up=None, dw=None):
        self.up = up if up else Equa()
        self.dw = dw if dw else Equa(nm=1)

    def refine(self):
        # Multiply numerator and denominator by conjugate of denominator
        a3dw = Equa(self.dw.nm, -self.dw.n5)
        self.dw = self.dw * a3dw
        self.up = self.up * a3dw
        
        # Simplify by greatest common divisor
        gcc = reduce(gcd, [self.dw.nm, self.up.nm, self.up.n5])
        self.dw.nm //= gcc
        self.up.nm //= gcc
        self.up.n5 //= gcc
        return self

    def __mul__(self, other):
        result = Node()
        result.up = self.up * other.up
        result.dw = self.dw * other.dw
        return result.refine()

    def __truediv__(self, other):
        # Swap numerator and denominator of the second node
        other = Node(up=other.dw, dw=other.up)
        return self * other

    def __add__(self, other):
        result = Node()
        result.dw = self.dw * other.dw
        result.up = self.up * other.dw + self.dw * other.up
        return result.refine()

def num(nm):
    return Node(up=Equa(nm=nm))

def print_node(a0):
    print(f"({a0.up.nm}+{a0.up.n5}sqrt(5))"
          f"/({a0.dw.nm}+{a0.dw.n5}sqrt(5))")

def qpow(base, exp, mod):
    res = 1
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
        base = (base * base) % mod
        exp //= 2
    return res

def check(x):
    a0,a1=0,1
    cnt=0
    while x!=a0:
        a0,a1=a1,4*a1+a0
        cnt=cnt+1
    return cnt

def checky(x):
    a0,a1=1,2
    cnt=0
    while x!=a0:
        a0,a1=a1,4*a1+a0
        cnt=cnt+1
    return cnt

# Main computation
def main():
    mod=398874989
    a0 = Node(up=Equa(1, 1), dw=Equa(2, 0))
    sq5=72648253
    sq51=326226736
    b0=(sq5+1)*qpow(2,mod-2,mod)%mod
    p0=1
    q0=2
    for i in range(3):
        a2 = a0 * a0
        a4 = a2 * a2
        
        up = a0 * (a4 + (a2 * num(10)) + num(5))
        dw = (a4 * num(5)) + (a2 * num(10)) + num(1)
        a0 = up / dw
        print(a0.up.n5,check(a0.up.n5),a0.dw.nm,checky(a0.dw.nm))
        pn=a0.up.n5%mod
        qn=a0.dw.nm%mod
        print(pn,qn)
        up=(pn*sq5+1)%mod
        dw=qn
        up0=b0*(b0*b0*b0*b0+10*b0*b0+5)%mod
        dw0=(5*b0*b0*b0*b0+10*b0*b0+1)%mod
        b0=b0*(b0*b0*b0*b0+10*b0*b0+5)*qpow(5*b0*b0*b0*b0+10*b0*b0+1,mod-2,mod)%mod
        an0=up*qpow(dw,mod-2,mod)%mod
        an1=up0*qpow(dw0,mod-2,mod)%mod
        print(b0,an0,an1,up0*qpow(up,mod-2,mod)%mod,dw0*qpow(dw,mod-2,mod)%mod)
        print()
#        print_node(a0)

if __name__ == "__main__":
    main()
'''
305 682 257933744
218103825 377145357 26500067
151851298 20269167 248829279
309_055767 289013590 10860616
171106951 69611418 156761845
291600067 186498455 84936537

pn+1=apn+bqn
qn+1=cpn+dqn
'''