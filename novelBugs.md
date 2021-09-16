### Determinant1 (From the library of flanagan)

Determinant1 is from the study[1]. 

Input： A matrix A.

Output：The determinant of this matrix, i.e., det(A).

MR1: Transposition: det(A) = det(A^T^) 

MR2: Row Multiplied with Scalar: β*det((a~1~,...,a~k-1~ ,a~k~,a~k+1~,...,a~n~) ^T^ ) = det((a~1~,...,a~k-1~ ,β*a~k~,,a~k+1~,...,a~n~) ^T^) for k ∈ {1, ..., n}

Giving two testcases 0.txt and 1.txt：

<img src="C:\Users\VULCAN\AppData\Roaming\Typora\typora-user-images\image-20210913122040011.png" alt="image-20210913122040011" style="zoom: 67%;" />

**The second test case input is based on the first test case, multiplying the value of line 20 by 6; However, the output of the first test case multiplied by 6 is not equal to the output of the second test case, which violates the metamorphic relation.**

We sent an email on July 16, 2020, to the author to describe the bug we have found, but no reply is received as of now.The email content is as follows：

![image-20210916232223303](C:\Users\VULCAN\AppData\Roaming\Typora\typora-user-images\image-20210916232223303.png)

### JAMA (From the library of JAMA)

JAMA is from the study[1]. 

Input： A matrix A.

Output：The determinant of this matrix, i.e., det(A).

MR1: Transposition: det(A) = det(A^T^) 

MR2: Row Multiplied with Scalar: β*det((a~1~,...,a~k-1~ ,a~k~,a~k+1~,...,a~n~) ^T^ ) = det((a~1~,...,a~k-1~ ,β*a~k~,,a~k+1~,...,a~n~) ^T^) for k ∈ {1, ..., n}

Giving two testcases 0.txt and 1.txt：

<img src="C:\Users\VULCAN\AppData\Roaming\Typora\typora-user-images\image-20210913123608808.png" alt="image-20210913123608808" style="zoom: 67%;" />

**The second test case input is based on the first test case, multiplying the value of line 16 by 5; However, the output of the first test case multiplied by 5 is not equal to the output of the second test case, which violates the metamorphic relation.**

We sent an email on July 16, 2020, to the author to describe the bug we have found, but no reply is received as of now.The email content is as follows：

![image-20210916232249501](C:\Users\VULCAN\AppData\Roaming\Typora\typora-user-images\image-20210916232249501.png)

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