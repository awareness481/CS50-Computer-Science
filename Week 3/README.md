The CS50 course content is licensed under a [Creative Commons Attribution-Noncommercial-Share Alike 3.0 Unported License](http://creativecommons.org/licenses/by-nc-sa/3.0/) by [David J. Malan](http://cs.harvard.edu/malan) of [Harvard University](http://www.harvard.edu/). You can find more information on [CS50.tv](http://cs50.tv/2016/fall/#lectures,license).

1. **find.C**
* Implement a program that finds a number among numbers, per the below.    
$./generate 1000 | ./find 42
Didn't find needle in haystack.

**Specifications**

**search**
* Your implementation must return false immediately if n is non-positive.
* Your implementation must return true if value is in values and false if value is not in values.
* The running time of your implementation must be in O(log n).
* You may not alter the function’s declaration. Its prototype must remain:
`bool search(int value, int values[], int n);`

**sort**
* Your implemenation must sort, from smallest to largest, the array of numbers that it’s passed.
* Assume that each of the array’s numbers will be non-negative and less than 65,536. But the array might contain duplicates.
* The running time of your implementation must be in O(n), where n is the array’s size. Yes, linear! Keep in mind that 65,536 is a constant.
* You may not alter the function’s declaration. Its prototype must remain:
`void sort(int values[], int n);`

2. **fifteen.c**
* Implement the Game of Fifteen

**Specifications**

* Implement init.

* Implement draw.

* Implement move.

* Implement won.


[Problem Set 3 Documentation](http://docs.cs50.net/2017/x/psets/3/pset3.html)
