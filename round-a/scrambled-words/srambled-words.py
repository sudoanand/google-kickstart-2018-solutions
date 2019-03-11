import sys

sys.stdin = open('/Users/hack4mer/Lab/stdin.txt', 'r')

def xi(a,x_prev,b,x_prev_prev,c,d):
    return ((a*x_prev)+(b*x_prev_prev)+c)%d

def si(xi):
    return chr(97 + xi % 26)



for _ in range(int(input())):
    L = int(input())
    Ldisct = input().split()

    S1,S2,N,A,B,C,D  = [ int(x) if i > 1 else x for i,x in enumerate(input().split())]
    S = [S1,S2];
    X = [ord(S1),ord(S2)];

    for i in range(2,N):
        X.append(xi(A,X[i-1],B,X[i-2],C,D))
        S.append(si(X[i]))

    print(''.join(S))
