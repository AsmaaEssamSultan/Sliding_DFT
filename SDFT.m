clc
x =[1,-5,2,7,1,7,2,4,0,9]
N = 5;
a = x(1:5);
A = fft(a);
disp('a[n]')
disp(a)
disp('A[k]')
disp(A)


b = x(2:6);
B = zeros(1,5);
for k = 1:5
    num = A(:,[k]) + b(:,[5]) - a(:,[1]);
    B(:,[k]) = num * exp((2*pi*j*(k-1))/N);
end
disp('b[n]')
disp(b)
disp('B[k]')
disp(B)

c = x(3:7);
C = zeros(1,5);
for k = 1:5
    num = B(:,[k]) + c(:,[5]) - b(:,[1]);
    C(:,[k]) = num * exp((2*pi*j*(k-1))/N);
end
disp('c[n]')
disp(c)
disp('C[k]')
disp(C)

d = x(4:8);
D = zeros(1,5);
for k = 1:5
    num = C(:,[k]) + d(:,[5]) - c(:,[1]);
    D(:,[k]) = num * exp((2*pi*j*(k-1))/N);
end
disp('d[n]')
disp(d)
disp('D[k]')
disp(D)

e = x(5:9);
E = zeros(1,5);
for k = 1:5
    num = D(:,[k]) + e(:,[5]) - d(:,[1]);
    E(:,[k]) = num * exp((2*pi*j*(k-1))/N);
end
disp('e[n]')
disp(e)
disp('E[k]')
disp(E)

f = x(6:10);
F = zeros(1,5);
for k = 1:5
    num = E(:,[k]) + f(:,[5]) - e(:,[1]);
    F(:,[k]) = num * exp((2*pi*j*(k-1))/N);
end
disp('f[n]')
disp(f)
disp('F[k]')
disp(F)



