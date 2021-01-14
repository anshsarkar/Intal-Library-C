# Intal-Library-C
A C library consisting of basic functions for integers of arbitrary length This library was implemented as a part of Design and Analysis of Algorithms (UE18CS251) course at PES University

## Compilation

To complie and execute, use 

```
gcc -w intal.c intalsampletest.c
./a.out
```

## Introduction

Intal stands for Intergers of Arbitrary Length. An INTAL is an integer which is not limited by predefined datatype sizes. An intal is a string of decimal digits of upto the length of 1000 characters stored in big endian format. They are stored as a null terminated string of ASCII charaters of maximum length of a 1000 characters and are used to represent arbitrarily large numbers, such as computing mathematical constants to high precision. 

In C we have datatypes such as int , long long int, unsigned int and many more to store integers. Intal can store the values in a range of {a,10^999} whereas the C datatypes such as int can store values from -2,147,483,648 to +2,147,483,647 and unsigned int can store values from 0 to 4,294,967,295. Intals are immune to overflow issues and the container size can be dynamically increased as required.  

Intals can be used to store large mathematical constants, for public-key cryptography and computing distances at astrnomical levels. Intals can be useful in calculations with much more precision as we can store the values of mathematical constants with higher precision. Intal can be used to represent the weights of a neural network so that we can store them with higher accuracy and thus our output results will be get significantly better.

A set of new functions must be built to perform the operations on intals as whole which translates operation on intal to operation on each digits.

## Approach

* intal_add():
We create a new separate array of strings to store our result. We start filling each cell from the lowest place with the sum of corresponding digits from each intal and keep propagatong the carry forward. Initially the carry is initialized as 0 and then it is updated as carry mod 10. This carry is propagated to the next lowest place until we have reached the end of either of the intals. If there is an intal with larger length we copy the leftover digits and ensure that all the digits of the intals have been covered. Before returning the result value we check if there are any unnecessary 0's or null values. These are removed using a helper function remove_zeroes and then the string is returned.

* intal_compare():
We start by checking the length of each intal. The intal with larger length is said to be greater than the other intal and has a higher value. If the length of both the intals are same we keep checking each digit to see if they are similar. If all the digits match we return 0. But if any digit i greater or lesser we conclude that the intal is greater or lesser respectively. Depending on each case we return the corresponding value.

* intal_diff():
We start by checking if the two intals are exactly same. In that case we return a 0. Else, we set the larger number as minuend and the smaller number as the subrahend. The number of digits in the result is set according to the greater intal and then per digits based subtraction is carried out. A borrow is taken from the first non-zero digit on the left from the greater number if necessary. The result is then checked for any unnecessary zeroes, these are removed and the resulting string is returned.

* intal_multiply():
We start by checking if either of the intal is 0, in that case the result is returened as a 0. The two intals are taken and intal1 is multiplied by each digit in intal2 starting from the lowest place. The carry is propagated forward if necessary. The partial products are added accordingy to obtain the final result which is returned.

* intal_mod():
The long division approach has been implemented. The result is initialized to 0 and the function loops through every digit in the dividend, multiplies the current result by 10 and adds the new digit of the intal to the mod value, then subtracts the divisor from it until the final result is lesser than the divisor. After passing over all the digits in dividend, 
the result is intal1 % intal2.

* intal_pow():
If n is 0 we return 1. We find the value of (intal)^n as (intal)^(n/2) * (intal)^(n/2). In case if n is odd one more multiplication with intal is done so that we get (intal)^(n). We compute this till n<0 and then the value is returned.

* intal_gcd():
We find the gcd using an iterative approach till the second number becomes 0. We find the GCD(m,n) as GCD(n,m mod n) and kep iterating till the second number becomes 0. The value of n is returned that is the value of GCD. If both the intals are 0 we return 0 or if the second intal is 0 then the value of intal1 is returned.

* intal_fibonacci():
We store the first two values of the fibonacci series as 0 and 1. If n=0 or n=1 we return the result from these 2 values. Else, we keep iterating and calculating the series elements by adding the previous two elements and assign the new value to the second value and second value to the first value. We iterate till the index is reached and the last number generated is returned.

* intal_factorial():
We check if n=0 or n=1, in either case we return the result as 1. Else we keep iterating through till the last index and keep multiplying the counter with the value and this value is updated in the result. The last value updated in result is returned.

* intal_bincoeff():
We use Pascal's identity and Dynamic programming concepts to generate the series. Since C(n, k) = C(n, n-k) we choose the smaller number between k and n-k. Then we use Pascal's identity which states that C(n, k) = C(n-1, k) + C(n-1, k-1). The initial values are stored in an array and iteratively find the result for the given index and this result is returned.

* intal_max():
We assign the first element in the array as the maximum element. We iterate through all the elements comparing each of them using the intal_compare() function. If an element is found that is greater than the present max value the index/offset is updated with that elements index. We iterate till the end of the array and the last index update is returned.

* intal_min():
We assign the first element in the array as the minimum element. We iterate through all the elements comparing each of them using the intal_compare() function. If an element is found that is lesser than the present min value the index/offset is updated with that elements index. We iterate till the end of the array and the last index update is returned.

* intal_search():
For this particular function the concepts of linear search is applied. We iterate through the array and compare each and every element with the key using intal_compare() function. The result is initialized with -1 assuming that the key is not present. If the key is found result is updated with the offset of the elements index and the result is returned that is the first occurrence of the key.

* intal_binsearch():
A simple binary search algorithm is implemented on the array of intals. The mid value is compared with the key. If the mid value is not equal to the key then depending on the key value the array is split into two. We assume that the array of intals is sorted. We keep splitting the array into two halves depending on the mid value compared to the key and this is done till no splitting is done. If the key is not found then -1 is returned otherwise the updated offset is returned.

* intal_sort():
A simple merge sort algorithm is implemented to sort the array of intals. This is a divide and conquer approach. We keep splitting the array into two halves recursively. While merging those 2 arrays we make sure that the element is placed in a non - decreasing order in the new array. We divide the array till there is only one element in the array and then start merging them. After the last merge the array is sorted.

* coin_row_problem():
Given a coin, the alternatives at each step are either to select it or not, based on whether picking it results in a greater total value or not. Hence the value at the nth coin, F(n) can be calculated using the recurrence relation F(n) = max(arr(n)+F(n-2), F(n-1)). This basically implies that picking the nth coin (arr(n)) forces us to skip the (n-1)th coin which covers the given constraint. 

## Future Work 
Additional functionalities such as bitwise operations, division, generating a random intal, finding all the prime intals in a given range. Also we can implement various data structures for intals and square root functions. We can implement intals with the help of a linked list or a doubly linked list. As it is easier to traverse through a list and handle the arbitrary length of the intals. We could also implement intals using structures.
