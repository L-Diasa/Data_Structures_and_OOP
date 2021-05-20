Staque

Create a data structure called “Staque” which can store only integers. The way Staque works is as follows:

If the number that you are trying to store in the Staque is even, it is pushed in front of the Staque
If the number that you are trying to store in the Staque is odd, it is pushed at the end of the Staque
When you try to remove a number from the Staque, you always do it from either the front or from the back of the Staque following the LIFO rule.
Write a C++ code to implement a Staque. Since the data structure is all about inserting and deleting numbers,  use a linked list to implement Staque. Here’s how your user interface should like:

Insert the numbers 1, 3, 2, 4, 6, 8 9 in the Staque.

Display the Staque: This is how the Staque will look like given that the above numbers were pushed in the Staque in the order given above: (front) 8 6 4 2 1 3 9 (back)

Delete 2 even numbers and 1 odd number from the Staque and then display the Staque:

Since deletion always follows the LIFO order, the numbers to be removed are 8 first and then 6(the 2 even numbers) and 9(odd) from the back of the Staque. The Staque shall then look like: (front) 4 2 1 3 (back).

Run you program for at least 3 different input series & corresponding 3 different removal series.
