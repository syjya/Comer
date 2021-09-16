### Determinant1 (From the library of flanagan)

Determinant1 is from the study[1]. 

Input： A matrix A.

Output：The determinant of this matrix, i.e., det(A).

MR1: Transposition:<img src="https://render.githubusercontent.com/render/math?math=de t(A) = det(A^{T})"> 

MR2: Row Multiplied with Scalar:

<img src="https://render.githubusercontent.com/render/math?math=\beta \times det((a_{1},..., a_{k-1}, a_{k}, a_{k+1}, ..., a_{n})^T) = det((a_{1},..., a_{k-1}, \beta \times a_{k}, a_{k+1}, ..., a_{n})^T)\ \ for\ \ k \in \{1, ..., n \} ">

Giving two text files as test cases:

0.txt

```
21 21
0 0 0 0 0 0 0 0 -8 0 0 0 0 0 0 0 0 0 -4 -3 0
-2 -7 0 0 0 0 0 -4 0 0 0 0 -9 0 0 0 -9 0 0 0 0
0 -7 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -4
0 0 0 0 0 0 0 -9 0 0 0 0 0 0 -1 0 0 0 0 0 0
0 0 0 0 0 -2 0 0 0 0 0 -4 0 0 0 0 0 0 0 -5 0
-9 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -2 0 -6 0 0
0 0 0 0 0 0 0 0 -4 0 0 0 0 -7 0 0 0 0 0 0 0
0 0 0 0 0 0 -2 0 0 0 0 0 0 0 0 0 -5 0 -5 0 0
0 0 0 0 0 0 0 0 0 0 -3 0 0 0 0 0 -7 0 0 0 0
0 0 0 -4 0 0 -9 0 0 -2 0 0 -6 0 0 0 0 -10 0 0 0
0 0 0 0 0 -10 -2 0 -9 0 0 0 0 0 0 -2 -2 0 0 -4 0
0 0 0 0 0 -10 0 0 0 0 0 0 0 0 0 0 -2 0 0 0 0
0 0 0 -4 0 0 0 0 0 -5 0 0 0 0 0 0 0 0 0 0 0
-8 0 0 0 0 0 0 0 0 -2 0 0 0 -1 0 0 0 0 0 0 -9
0 0 0 0 0 -1 0 0 0 0 0 0 0 0 0 -8 -3 0 0 0 0
0 0 0 0 0 0 -5 0 -7 0 0 0 -7 0 -10 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 -5 0 -2 0 -8 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 -4 0 0 0 0 0 0 -4
0 0 -5 0 0 0 0 0 0 -4 0 0 0 0 -2 0 -9 0 0 0 0
0 0 0 -3 -4 0 0 -3 -8 -7 0 0 -5 0 -9 0 -3 0 0 0 0
0 0 -8 0 0 0 0 0 0 0 -10 0 0 0 0 0 0 0 0 0 0
52740503383572488.00000000
```

 and 1.txt

``` 
21 21
0 0 0 0 0 0 0 0 -8 0 0 0 0 0 0 0 0 0 -4 -3 0
-2 -7 0 0 0 0 0 -4 0 0 0 0 -9 0 0 0 -9 0 0 0 0
0 -7 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -4
0 0 0 0 0 0 0 -9 0 0 0 0 0 0 -1 0 0 0 0 0 0
0 0 0 0 0 -2 0 0 0 0 0 -4 0 0 0 0 0 0 0 -5 0
-9 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -2 0 -6 0 0
0 0 0 0 0 0 0 0 -4 0 0 0 0 -7 0 0 0 0 0 0 0
0 0 0 0 0 0 -2 0 0 0 0 0 0 0 0 0 -5 0 -5 0 0
0 0 0 0 0 0 0 0 0 0 -3 0 0 0 0 0 -7 0 0 0 0
0 0 0 -4 0 0 -9 0 0 -2 0 0 -6 0 0 0 0 -10 0 0 0
0 0 0 0 0 -10 -2 0 -9 0 0 0 0 0 0 -2 -2 0 0 -4 0
0 0 0 0 0 -10 0 0 0 0 0 0 0 0 0 0 -2 0 0 0 0
0 0 0 -4 0 0 0 0 0 -5 0 0 0 0 0 0 0 0 0 0 0
-8 0 0 0 0 0 0 0 0 -2 0 0 0 -1 0 0 0 0 0 0 -9
0 0 0 0 0 -1 0 0 0 0 0 0 0 0 0 -8 -3 0 0 0 0
0 0 0 0 0 0 -5 0 -7 0 0 0 -7 0 -10 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 -5 0 -2 0 -8 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 -4 0 0 0 0 0 0 -4
0 0 -30 0 0 0 0 0 0 -24 0 0 0 0 -12 0 -54 0 0 0 0
0 0 0 -3 -4 0 0 -3 -8 -7 0 0 -5 0 -9 0 -3 0 0 0 0
0 0 -8 0 0 0 0 0 0 0 -10 0 0 0 0 0 0 0 0 0 0
316443020301434880.00000000
```

**The second test case input is based on the first test case, multiplying the value of line 20 by 6; However, the output of the first test case multiplied by 6 is not equal to the output of the second test case, which violates the metamorphic relation.**

We sent an email on July 16, 2020, to the author to describe the bug we have found, but no reply is received as of now.The email content is as follows：

![image](https://github.com/syjya/Comer/blob/master/mail1.png)

### JAMA (From the library of JAMA)

JAMA is from the study[1]. 

Input： A matrix A.

Output：The determinant of this matrix, i.e., det(A).

MR1: Transposition:<img src="https://render.githubusercontent.com/render/math?math=de t(A) = det(A^{T})"> 

MR2: Row Multiplied with Scalar:

<img src="https://render.githubusercontent.com/render/math?math=\beta \times det((a_{1},..., a_{k-1}, a_{k}, a_{k+1}, ..., a_{n})^T) = det((a_{1},..., a_{k-1}, \beta \times a_{k}, a_{k+1}, ..., a_{n})^T)\ \ for\ \ k \in \{1, ..., n \} ">

Giving two text files as test cases:

0.txt

```
16 16
0 1 -5 5 -10 -10 -2 0 0 6 0 1 0 -5 9 10
0 -1 6 -5 -6 6 6 -10 0 0 0 -1 0 -2 -3 -6
-1 -4 0 -4 1 8 -7 -10 -7 -10 -5 0 -5 3 0 5
-7 4 -8 -5 7 10 -1 0 -4 -8 6 0 -6 3 -5 -4
-1 -6 0 -1 -6 -6 -1 -3 -6 -7 0 -8 -2 0 8 -6
5 -4 0 0 10 1 0 8 -1 -5 0 3 -7 0 -7 4
-5 1 6 0 5 -2 -7 -5 0 -2 -5 8 0 0 0 6
-9 8 0 4 -5 0 0 -8 -2 -10 -6 0 -3 -10 -7 -5
5 2 5 5 -4 9 3 -3 0 -7 -5 0 -10 0 -3 0
-9 -5 -3 -8 0 -10 0 -4 7 0 0 10 0 -2 -7 0
-8 0 4 -8 1 4 0 7 -9 9 -4 -4 9 0 -7 1
6 0 -9 -4 -1 0 -10 -4 10 5 1 0 10 0 -10 5
0 0 -2 -6 0 0 0 -7 1 0 -2 -3 3 -10 1 0
-6 -8 -1 -5 -3 -2 -1 -7 -6 2 -8 10 6 0 0 0
-9 0 -7 -10 0 -3 8 -1 -5 0 -1 -3 8 10 -10 -10
-9 -1 -1 5 0 0 -1 0 0 -5 -8 8 0 -3 0 -7
18644849679849716.00000000
```

 and 1.txt

``` 
16 16
0 1 -5 5 -10 -10 -2 0 0 6 0 1 0 -5 9 10
0 -1 6 -5 -6 6 6 -10 0 0 0 -1 0 -2 -3 -6
-1 -4 0 -4 1 8 -7 -10 -7 -10 -5 0 -5 3 0 5
-7 4 -8 -5 7 10 -1 0 -4 -8 6 0 -6 3 -5 -4
-1 -6 0 -1 -6 -6 -1 -3 -6 -7 0 -8 -2 0 8 -6
5 -4 0 0 10 1 0 8 -1 -5 0 3 -7 0 -7 4
-5 1 6 0 5 -2 -7 -5 0 -2 -5 8 0 0 0 6
-9 8 0 4 -5 0 0 -8 -2 -10 -6 0 -3 -10 -7 -5
5 2 5 5 -4 9 3 -3 0 -7 -5 0 -10 0 -3 0
-9 -5 -3 -8 0 -10 0 -4 7 0 0 10 0 -2 -7 0
-8 0 4 -8 1 4 0 7 -9 9 -4 -4 9 0 -7 1
6 0 -9 -4 -1 0 -10 -4 10 5 1 0 10 0 -10 5
0 0 -2 -6 0 0 0 -7 1 0 -2 -3 3 -10 1 0
-6 -8 -1 -5 -3 -2 -1 -7 -6 2 -8 10 6 0 0 0
-45 0 -35 -50 0 -15 40 -5 -25 0 -5 -15 40 50 -50 -50
-9 -1 -1 5 0 0 -1 0 0 -5 -8 8 0 -3 0 -7
93224248399245968.00000000
```

**The second test case input is based on the first test case, multiplying the value of line 16 by 5; However, the output of the first test case multiplied by 5 is not equal to the output of the second test case, which violates the metamorphic relation.**

We sent an email on July 16, 2020, to the author to describe the bug we have found, but no reply is received as of now.The email content is as follows：

![image](https://github.com/syjya/Comer/blob/master/mail2.png)

### ClosetPair

ClosetPair is a program posted online[2]. 

Input：A set of points with x-y Cartesian coordinates in a plane.

Output：The distance of two closest points.

MR：Adding one point to this plane, the distance should not be larger than before.

Giving two inputs：

First is [(784832243,700131220), (1696499969,459738083), (1390076221,809277653),(1896548658,14284339220), (355749738,1176386028), (-1540278275,283604219),(-312014611,1004576997), (-137565412,-1210662673), (-939623457,-1306181183), (982263467,-952545436)]，output  9978.34;

Second is [(784832243,700131220), (1696499969,459738083), (1390076221,809277653),(1896548658,14284339220), (355749738,1176386028), (-1540278275,283604219),(-312014611,1004576997), (-137565412,-1210662673), (-939623457,-1306181183), (982263467,-952545436), (1645682438,-1196740735)]，output  16556.7;

**The second test case added a point (1645682438,-1196740735) on the basis of the first test case, but the output of the second test case was greater than that of the first test case, which violated the metamorphic relation.**

### Rotate

Rotate is from the scipy[3].

issue：[BUG: Picture rotated 180 degrees and rotated -180 degrees should be consistent · Issue #12543 · scipy/scipy (github.com)](https://github.com/scipy/scipy/issues/12543)

### F_oneway

Foneway is from the scipy[3].

issue：[p-value varies with the order of the data · Issue #11669 · scipy/scipy (github.com)](https://github.com/scipy/scipy/issues/11669)



[1] J. Mayer and R. Guderlei, “An empirical study on the selection of good metamorphic relations,” in Proceedings of the 30th Annual International Computer Software and Applications Conference - Volume 01, ser. COMPSAC ’06. USA: IEEE Computer Society, 2006, p. 475–484. [Online]. Available: https://doi.org/10.1109/COMPSAC.2006.24

[2] “Closest pair of points O(nlogn) algorithm - problem with some data in c++ implementation,” Jul 2020, [Online; accessed 6. Jul. 2020]. [Online]. Available: https://stackoverflow.com/questions/54000950/closest-pair-of-points-onlogn-algorithm-problem-with-some-data-in-c-implem

[3] https://github.com/scipy