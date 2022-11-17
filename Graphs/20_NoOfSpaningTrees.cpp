// Count the total number of spanning tree in the graph
// Kirchhoff's theorem is use to find the count of spanning trees

/*
Algorithm of kirchhoff' theorem : 
1 : convert the graph in to matrix by following below steps
    a). first fill all the possition of matrix except first diagonal by storing values -1 in matrix if there is an edge is present
        else store 0

    b). At diagonal put the degree of all the vertices
2. after contruction the matrix delete one of the row and column 
3. and take determinant of rest matrix that will be the count of total spanning tree in the graph
*/

