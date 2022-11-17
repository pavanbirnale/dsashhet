// count subsets with given difference
// this problem is an extention of count subset sum and minimum sum partition

//  here in this problem we have given an array and a diffenece value and we have to return that how many 
//  subsets of sets are present with given diff

// so for that small maths is require and then problem is converted to 9_count subset sum

/*
let us assume
s1 = sum of set1 
s2 = sum of set2 
we have given that :
    s1-s2 = diff
but we know that :
    s1+s2 = sum   -------------(sum==arraySum);
 
 therefore adding both eqn,
   2*s1 = diff + sum

   ie. s1 = (diff+sum)/2;


so the problem is reduces to count subset sum with we target s1


that all
*/