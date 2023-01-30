**Description**

A polyline in 3D is given by the list of nodes’ coordinates. Implement an algorithm that
searches the nearest point on the polyline to any given point. In case of multiple solutions,
output all of them.

**Input-output**

The algorithm should be framed as a console application:
1. Input (command line options):
- name of text file containing coordinates of polyline nodes,
- coordinates of the point to be projected.
2. Output:
- print the indices of all nearest polyline segments and coordinates of corresponding
projection points.

**Samples:**

Example 1.
|Nodes|Target point|Output|
|----|----|----|
|0 0 0|2 0.5 0.5|segment 2 point 1.75 0.75 0
|1 0 0||segment 3 point 2.25 1 0.25
|2 1 0|
|3 1 1|

Example 2.
|Nodes|Target point|Output|
|----|----|----|
|0 0 0|1 1 1|segment 1 point 1 0 0
|2 0 0||segment 2 point 2 1 0
|2 2 0||segment 3 point 1 2 0
|0 2 0||segment 4 point 0 1 0
|0 0 0|

Example 3.
|Nodes|Target point|Output|
|----|----|----|
|0 0 0|3 3 3|segment 2 point 2 2 0
|2 0 0||segment 3 point 2 2 0
|2 2 0||
|0 2 0||
|0 0 0|
