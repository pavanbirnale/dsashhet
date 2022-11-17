// Bit mask || Bitmasking 

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/

/* 
Mask in Bitmask means hiding something. 
Bitmask is nothing but a binary number that represents something.
Let's take an example. Consider the set A = {1,2,3,4,5} We can represent set A by using bitmask of length 5
like 11111 so, if subset B of set A will be = {2,4} represented as 01010 
*/

// ####################### Operations Of Bitmasking #######################

/*
set A = {0,1,2,3,4};
Let us consider subset of set A, set B = {2,4} then its bitmask is

set  :  4 3 2 1 0
mask :  1 0 1 0 0

That means bit number 2 and 4 is set

Now we do operations on It :=>





1. Set ith bit : 
Formula : B|(1<<i)
so, if we have to set 3rd bit then,
          B|(1<<3) = 10100|01000 it gives => 11100
          so the set now B = {2,3,4};




2. Unset ith bit :
 formula : B&!(1<<i)
 so, if we have to unset 3rd bit then,
        B&!(1<<3) = 11100 &!(01000)
                  = 11100 & (10111) it gives => 10100
        so the set now B = {2,4};




3. Check is Bit set :
 formula : B&(1<<i)
 so, if we have to check 3rd bit weather it is set or not
       B&(1<<3) = 10100 & 01000 it gives => 00000
       so that the 3rd bit is unset 
*/