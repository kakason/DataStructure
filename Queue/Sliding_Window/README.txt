Consider an n-integer sequence, A = {a(0),a(1),...a(n-1)}. We perform a query on
A by using an integer, d, to calculate the result of the following equation:

 min  (   max    a(j) )
0<=i<n  i<=j<i+d

Given A and q queries (each query consists of an integer, d), print the result
of each query on a new line.

Input Format
The first line consists of two space-separated integers describing the respective
values of n and q.
The second line consists of n space-separated integers describing the respective
values of a(0), a(1),...,a(n-1).
Each of the q subsequent lines contains a single integer denoting the value of
d for that query.

Constraints
1 <= n <= 10^5
0 <= a(i) < 10^6
1 <= q <= 100
1 <= d <= n

Output Format
For each query, print an integer denoting the query's answer on a new line.
After completing all the queries, you should have printed q lines.

Sample Input
7 7
4 5 6 7 3 2 1
1
2
3
4
5
6
7

Sample Output
1
2
3
7
7
7
7
