Given an array A[] of N distinct elements. Let M1 and M2 be the smallest and the
next smallest element in the interval [L, R] where 1 <= L < R <= N.

Si = ((M1 & M2) xor (M1 or M2)) & (M1 xor M2).

&: the bitwise operators "AND"
xor: the bitwise operators "XOR"
or: the bitwise operators "OR"

Your task is to find the maximum possible value of Si.

Input Format
First line contains integer N.
Second line contains N integers, representing elements of the array A[].

Constraints
1 < N <= 10^6
1 <= Ai <= 10^9

Output Format
Print the value of maximum possible value of Si.

Sample Input
5
9 6 3 5 2

Sample Output
15
