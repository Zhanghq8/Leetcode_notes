## Question
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*

- Example1:
```
Input: [2,2,1]
Output: 1
```
- Example2:
```
Input: [4,1,2,1,2]
Output: 4
```
- Answer:
```
Approach 4: Bit Manipulation   
If we take XOR of zero and some bit, it will return that bit
a ^ 0 = a
If we take XOR of two same bits, it will return 0
a ^ a = 0
a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b
So we can XOR all bits together to find the unique number.
```