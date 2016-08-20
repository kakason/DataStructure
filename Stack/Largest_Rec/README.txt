There are N buildings in a certain two-dimensional landscape. Each building has
a height given by h(i), i belongs to [1,N]. If you join K adjacent buildings,
they will form a solid rectangle of area K x min[h(i), h(i+1),..., h(i+k-1)].

Given N buildings, find the greatest such solid area formed by consecutive buildings.

Input Format
The first line contains N, the number of buildings altogether.
The second line contains N space-separated integers, each representing the height
of a building.

Constraints
1 <= N <= 100000
1 <= h(i) <= 1000000

Output Format
One integer representing the maximum area of rectangle formed.

Sample Input
16
5 3 6 4 1 7 6 4 3 5 1 2 3 4 5 6

Sample Output
16
