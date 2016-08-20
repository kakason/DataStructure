There are N plants in a garden. Each of these plants has been added with some
amount of pesticide. After each day, if any plant has more pesticide than the
plant at its left, being weaker than the left one, it dies. You are given the
initial values of the pesticide in each plant. Print the number of days after
which no plant dies, i.e. the time after which there are no plants with more
pesticide content than the plant to their left.

Input Format
The input consists of an integer N. The next line consists of N integers
describing the array P where P[i] denotes the amount of pesticide in plant .

Constraints
1 <= N <= 100000
0 <= P[i] <= 1000000000

Output Format
Output a single value equal to the number of days after which no plants die.

Sample Input 1
7
6 5 8 4 7 10 9

Sample Input 2
6
1 1 1 1 1 1

Sample Input 3
6
3 4 7 6 2 3

Sample Output 1
2

Sample Output 2
0

Sample Output 3
2
