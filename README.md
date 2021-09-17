## COMER, an enhancement approach of CT which supports metamorphic relation matching

We mainly explored 31 software subjects. For each of these software subjects, we provide a folder containing  the abstract phase code and the concrete phase code. 

#### Abstract test case generation

This includes ART_Cons.jar, ART_Cons_MR.jar, and Baseline.jar, corresponding to CT, COMER, and TRI_MCT respectively.Input parameters include generating the abstract test case store path, dimension, and file name (numeric only) .For example，run the command: "java  -jar ART_Cons.jar  /ART_Cons  2  0"，then a TXT file named 0 is generated under the path "/ART_Cons" to hold an abstract set of test cases that meet 2-dimensional coverage.

#### concrete test case generation

- **Scipy**

We mainly explored 3 software subjects about scipy，includes "F_oneway"、"Rotate" and "Shortest_path".In this phase, each of them provides a script that inputs an abstract set of test cases, outputs a concrete set of test cases (both input and output), and the results of matching the metamorphic relation.

- **Others**

  In addition to the three subjects associated with Scipy, there are 28 software subjects. In this phase, each of them provides model_CT.cpp,model_COMER.cpp, and model_Random.cpp for converting abstract test cases into concrete test cases, corresponding to CT, COMER(TRI_MCT), and Random, respectively.In addition, also provides the source code, variants, and the script that can search and count the matchings of the metamorphic relations between generated test cases. 
  
  

#### data

It also provides the results of our emprical studies of COMER, including **results.xlsx**、**time_abstract.xlsx**、**time_concrete.xlsx** and **ComerVSOptimal.xlsx**, and is explained at **data.md**.

It also includes the descriptions of  five previously unknown bugs,that is **novelBugs.md**.



#### The detailed description of  the subjects

Functional descriptions, inputs, outputs, and metamorphic relations of all subjects are listed in **metamorphic relation.pdf**.  



The abstract models of subjects are shown below：

- **Schedule** 

  【Parameters】

  cmmand1: [0, 1, (1,10] ]  

  cmd1_queue: [1, 2, 3]

  cmmand2:[0, 1, (1,10] ]

  cmd2_queue: [1, 2]

  cmd2_ratio: [0, 1, 0.1, 0.4, 0.5, 0.6, 0.9, 2]

  cmmand3:[0, 1, (1,10] ]

  cmmand4:[0, 1, (1,10] ]

  cmd4_ratio: [0, 1, 0.1, 0.4, 0.5, 0.6, 0.9, 2 ]

  cmmand5:[0, 1, (1,10] ]

  cmmand6:[0, 1, (1,10] ]

  cmmand7:[ 1, (1,10] ]

- **Determinant1**

  【Parameters】

  row: [[1,10)，[10,20)，[20,30)]

  matrix_attribute:[normal，zero，diagonal matrix，Upper triangular matrix，Lower triangular matrix]

  k[0,1/2，1/3，1/4 ,1] //////In normal, it is the positive proportion of all Numbers; in other times, it is the positive proportion of variable values.

  mutiple:[1,(2,10)] //////When mutiple is (2,10), there is a random k in the range, and any row of the source matrix is multiplied by k, leaving the other rows unchanged to form a new matrix.

- **JAMA** 

  【Parameters】

  row: [[1,10)，[10,20)，[20,30)]

  matrix_attribute:[normal，zero，diagonal matrix，Upper triangular matrix，Lower triangular matrix]

  k[0,1/2，1/3，1/4 ,1] //////In normal, it is the positive proportion of all Numbers; in other times, it is the positive proportion of variable values.

  mutiple:[1,(2,10)] //////When mutiple is (2,10), there is a random k in the range, and any row of the source matrix is multiplied by k, leaving the other rows unchanged to form a new matrix. 

- **ClosestPair**

  【Parameters】

  point:[[1,10],（10,20)]

  The ratio of the first quadrant points:[0,1/2,1/4,1/8,1]

  The ratio of the second quadrant points:[0,1/2,1/4,1/8,1]

  The ratio of the third quadrant points:[0,1/2,1/4,1/8,1]

  【Constraints】

  The ratio of the first quadrant points + The ratio of the second quadrant points+The ratio of the third quadrant points<=1

- **Printtoken** 

  【Parameters】

  keyword: [and, or, if, xor, lambda, equalgreater, lparen, rparen, lsquare, rsquare, quote, bquote, comma ]

  keyword_attribute: [none, begin, middle, end]

  identifier: [test, test15, AND, IF3, lambda7, X15or, test\t, te?st, test., 15or]

  identifier_attribute: [none, begin, middle, end]

  number: [0, 7, 770, 777, 077]

  number_attribute: [none, begin, middle, end]

  special: [comment, character, string] 

  special_value: [none, te #st, te ;st, te "st, te#st, te;st, te"st, and, test, te?st, 770, test\ttest, test (]

  special_attribute: [none, begin, middle, end]

  repeat: [0，1]

  judge:[0，1] //All lowercase becomes uppercase at 1. 

  【Constraints】

  keyword_attribute =begin => identifier_attribute !=begin && number_attribute !=begin && special_attribute !=begin

  identifier_attribute =begin => keyword_attribute !=begin && number_attribute!=begin && special_attribute !=begin

  number_attribute =begin => keyword_attribute !=begin && identifier_attribute !=begin && special_attribute !=begin

  special_attribute =begin => keyword_attribute !=begin && identifier_attribute !=begin && number_attribute !=begin

  special_attribute =end => keyword_attribute !=end && identifier_attribute !=end && number_attribute !=end

  number_attribute =end => keyword_attribute !=end && identifier_attribute !=end && special_attribute !=end

  identifier_attribute =end => keyword_attribute !=end && number_attribute !=end && special_attribute !=end

  keyword_attribute =end => identifier_attribute !=end && number_attribute !=end && special_attribute !=end

- **Multi-MAXSUM**

  【Parameters】

  same_number:[0，[2,10)，[10，20)] 

  negative:[0，[1,20)，[20，40)]

  positive:[0，[1,20)，[20，40)]

  zero:[0，[1,5)，[5，10)]

  m:[1,n/3,n/2,n]

  issame:[0,1] //When Issame is 0, the parameter Same is invalid.

   【Constraints】

  negative+zero+ positive>0

  zero+ positive+ negative >= same_number 

  zero <= same_number

  same_number - zero ! = 1

- **SurroundedRegion**

  【Parameters】

  m:[[1,10)，[10,20)，[20,30)]

  n: [[1,10)，[10,20)，[20,30)]

  matrix_attribute:[normal，zero，diagonal matrix，Upper triangular matrix，Lower triangular matrix]

  k[0,1/2，1/3，1/4 ,1] // it is X proportion of all characters.

  isk[0,1] //When IsK is 0, the parameter K is invalid.

  【Constraints】

  matrix_attribute= diagonal matrix || matrix_attribute= Upper triangular matrix || matrix_attribute= Lower triangular matrix => m=n

- **MaxRectangle** 

  【Parameters】

  m:[[1,10)，[10,20)，[20,30)]

  n: [[1,10)，[10,20)，[20,30)]

  matrix_attribute:[normal，zero，diagonal matrix，Upper triangular matrix，Lower triangular matrix]

  k[0,1/2，1/3，1/4 ,1] // it is X proportion of all characters.

  isk[0,1] //When IsK is 0, the parameter K is invalid.

  【Constraints】

  matrix_attribute= diagonal matrix || matrix_attribute= Upper triangular matrix || matrix_attribute= Lower triangular matrix => m=n

- **InterleavingString** 

  【Parameters】

  length1:[1-10,11-18,19-30]

  num1:[0,1/2,1/3,1/4,1]

  notation1:[0,1/2,1/3,1/4,1]

  length2:[1-10,11-18,19-30]

  num2:[0,1/2,1/3,1/4,1]

  notation2:[0,1/2,1/3,1/4,1]

  intersect:[0,1]

  【Constraints】

  num1 + notation1<=1

  num2 + notation2<=1

- **QuickSort**

  【Parameters】

  same_number:[0，[2,10)，[10，20)] 

  negative:[0，[1,20)，[20，40)]

  positive:[0，[1,20)，[20，40)]

  zero:[0，[1,5)，[5，10)] 

  add:[0, [1,5)，[5，10)] 

  order:[Positive, negative, out of order]

  【Constraints】 

  The length of the array is greater than 0.

  zero+ positive+ negative >= same_number 

  zero <= same_number

  same_number - zero ! = 1

- **Bsearch1**

  【Parameters】

  same_number:[0，[2,10)，[10，20)] 

  negative:[0，[1,20)，[20，40)]

  positive:[0，[1,20)，[20，40)]

  zero:[0，[1,5)，[5，10)]

  const:[Less than every number in the array, not matching in the array, matching, greater than every number in the array, random]

   【Constraints】

  zero+ positive+ negative > 0

  zero+ positive+ negative >= same_number 

  zero <= same_number

  same_number - zero ! = 1

  const=not matching in the array => zero+ positive+ negative > 1

- **Spwiki** 

  【Parameters】

  point:[1,(1,10),(10,20)]

  edge:[0,1,(1,20),(20,40)]

  start:[0,(0,n-1),n-1]

  end:[0,(0,n-1),n-1]

  multiple:[1,2,3]

   【Constraints】 

  point*(point-1)/2>=edge

  edge=0 =>start=0 =>end=0

- **DistinctSubsequence** 

  【Parameters】

  length1:[0,1-10,11-20,21-30]

  num:[0,1/2,1/3,1/4,1]

  notation:[0,1/2,1/3,1/4,1]

  length2:[0,1-10,11-20,21-30]

  in:[0,1]

   【Constraints】 

  length2!=0=>length1> length2

  num + notation<=1

- **Editingdistance**

  【Parameters】

  length1:[0,1-4,5-9]

  num1:[0,1/2,1/3,1/4,1]

  notation1:[0,1/2,1/3,1/4,1]

  length2:[0,1-4,5-9]

  num2:[0,1/2,1/3,1/4,1]

  notation2:[0,1/2,1/3,1/4,1]

   【Constraints】

  num1 + notation1<=1

  num2 + notation2<=1

- **FirstMissingPositive**

  【Parameters】

  same_number:[0，[2,10)，[10，20)] 

  negative:[0，[1,20)，[20，40)]

  positive:[0，[1,20)，[20，40)]

  zero:[0，[1,5)，[5，10)]

  order:[Positive, negative, out of order]

  issame:[0,1] 

  【Constraints】

  zero+ positive+ negative >0

  zero+ positive+ negative >= same_number 

  zero <= same_number

  same_number - zero ! = 1

- **HeapSort**

  【Parameters】

  same_number:[0，[2,10)，[10，20)] 

  negative:[0，[1,20)，[20，40)]

  positive:[0，[1,20)，[20，40)]

  zero:[0，[1,5)，[5，10)] 

  add:[0, [1,5)，[5，10)] 

  order:[Positive, negative, out of order]

  【Constraints】 

  The length of the array is greater than 0.

  zero+ positive+ negative >= same_number 

  zero <= same_number

  same_number - zero ! = 1

- **Schedule2**

  【Parameters】

  cmmand1: [0, 1, (1,10] ]  

  cmd1_queue: [1, 2, 3]

  cmmand2:[0, 1, (1,10] ]

  cmd2_queue: [1, 2]

  cmd2_ratio: [0, 1, 0.1, 0.4, 0.5, 0.6, 0.9, 2]

  cmmand3:[0, 1, (1,10] ]

  cmmand4:[0, 1, (1,10] ]

  cmd4_ratio: [0, 1, 0.1, 0.4, 0.5, 0.6, 0.9, 2 ]

  cmmand5:[0, 1, (1,10] ]

  cmmand6:[0, 1, (1,10] ]

  cmmand7:[ 1, (1,10] ]

- **Printtoken2** 

  【Parameters】

  keyword: [and, or, if, xor, lambda, equalgreater, lparen, rparen, lsquare, rsquare, quote, bquote, comma ]

  keyword_attribute: [none, begin, middle, end]

  identifier: [test, test15, AND, IF3, lambda7, X15or, test\t, te?st, test., 15or]

  identifier_attribute: [none, begin, middle, end]

  number: [0, 7, 770, 777, 077]

  number_attribute: [none, begin, middle, end]

  special: [comment, character, string] 

  special_value: [none, te #st, te ;st, te "st, te#st, te;st, te"st, and, test, te?st, 770, test\ttest, test (]

  special_attribute: [none, begin, middle, end]

  repeat: [0，1]

  judge:[0，1] //All lowercase becomes uppercase at 1. 

  【Constraints】

  keyword_attribute =begin => identifier_attribute !=begin && number_attribute !=begin && special_attribute !=begin

  identifier_attribute =begin => keyword_attribute !=begin && number_attribute!=begin && special_attribute !=begin

  number_attribute =begin => keyword_attribute !=begin && identifier_attribute !=begin && special_attribute !=begin

  special_attribute =begin => keyword_attribute !=begin && identifier_attribute !=begin && number_attribute !=begin

  special_attribute =end => keyword_attribute !=end && identifier_attribute !=end && number_attribute !=end

  number_attribute =end => keyword_attribute !=end && identifier_attribute !=end && special_attribute !=end

  identifier_attribute =end => keyword_attribute !=end && number_attribute !=end && special_attribute !=end

  keyword_attribute =end => identifier_attribute !=end && number_attribute !=end && special_attribute !=end

- **TCAS**

  【Parameters】

  Cur_Vertical_Sep: [299, 300, 601]

  High_Confidence: [0, 1]

  Two_of_Three_Reports_Valid: [0, 1]

  Own_Tracked_Alt: [1, 2]

  Own_Tracked_Alt_Rate: [600, 601]

  Other_Tracked_Alt: [1, 2]

  Alt_Layer_Value: [0, 1, 2, 3]

  Up_Separation: [0, 399, 400, 499, 500, 639, 640, 739, 740, 840]

  Down_Separation: [0, 399, 400, 499, 500, 639, 640, 739, 740, 840]

  Other_RAC: [0, 1, 2]

  Other_Capability: [1, 2]

  Climb_Inhibit: [0, 1]

- **Maxsub**

  【Parameters】

  same_number:[0，[2,10)，[10，20)] 

  negative:[0，[1,20)，[20，40)]

  positive:[0，[1,20)，[20，40)]

  zero:[0，[1,5)，[5，10)]

  order:[Positive, negative, out of order]

  【Constraints】 

  zero+ positive+ negative>0

  zero+ positive+ negative >= same_number 

  zero <= same_number

  same_number - zero ! = 1

- **Jodatime**

  【Parameters】

  year:[1900，1998，2000，2008，2009，2012]

  month : [1,2,7,8,9,12]

  day : [1,28,29,30,31]

  hour : [0,9,13,18,20]

  minute : [0,5,18,31,50]

  second : [0,5,18,31,50]

  milliseconds : [0,5,18,31,50]

  week_value : [0,1,3]

  day_value:[0,1,2,7]

  seconds_value:[0,1,2,3,604800]

  【Constraints】 

  (year=1900|| year=1998|| year=2009)&&month=1 => (day!=29&&day!=30 &&day!=31)

  (year=2000|| year=2008|| year=2012)&&month=1 => (day!=30 &&day!=31)

  month=9 => day!=31

- **Klp**

  【Parameters】

  row: [[1,10)，[10,20)，[20,30)]

  column: [[1,10)，[10,20)，[20,30)]

  k[(0,1),1] // The ratio of 1's in each column, at least one 1 in each column

  isk:[0,1]

- **Trisquarej**

  【Parameters】

  attribute:[Ordinary, isosceles not equilateral, not triangle, equilateral]

  a:[（1，10），（11，50），（51，100），]

  b:[（1，10），（11，50），（51，100），]

  c:[（1，10），（11，50），（51，100），]

  【Constraints】 

  a <= b <= c

  attribute = isosceles not equilateral => c=b||a=b

  attribute = equilateral => a=b=c

  attribute = not triangle  => a+b<c

  attribute ！= not triangle => a+b>c

- **Boyer**

  【Parameters】

  num:[0,（0，5]，（5，10]]

  k1:[0，2，5]

  character:[0,（0，5]，（5，10]]

  k2:[0，2，5]

  notation:[0,（0，5]，（5，10]]

  k3:[0，2，5]

  position:[-1,0,n/2,n-1]

  delete:[0,1]

  【Constraints】 

  num+cha+no>0

- **Lucene** 

  【Parameters】

  num:[0,[1,5),[5,10)]

  k1:[1,[2,5), [5,8)]

  character:[0,[1,5),[5,10)]

  k2:[1,[2,5), [5,8)]

  notation:[0,[1,5),[5,10)]

  k3:[1,[2,5), [5,8)]

  position1:[-1,0,n/2,n-1]

  position2:[-1,0,n/2,n-1,null] 

  delimiter:[null,OR,AND,NOT]

  【Constraints】 

  num+ character+ notation>0

- **Superstring**

  【Parameters】

  length:[ [1,5),[5,10),[10,15)]

  The ratio of strings of length 1:[0,1/2,1/3,1/4,1]

  The ratio of strings of length（2，5）:[0,1/2,1/3,1/4,1]

  num:[0,1/2,1/3,1/4,1]

  notation:[0,1/2,1/3,1/4,1]

  isk:[0,1]

   【Constraints】 

  num + notation<=1

  The ratio of strings of length 1 + The ratio of strings of length（2，5）<=1

- **Bsearch2**

  【Parameters】

  same_number:[0，[2,10)，[10，20)]

  positive:[0，[1,20)，[20，40)]

  zero:[0，[1,5)，[5，10)]

  const:[Less than every number in the array, not matching in the array, matching, greater than every number in the array, random]

  square:[0，1]

   【Constraints】

  zero+ positive > =1

  zero+ positive >= same_number

  zero <= same_number

  same_number - zero ! = 1

  const=not matching in the array  => zero+ positive > 1

- **RSA**

  【Parameters】

  p_value：[[1,100)，[100,1000)，[1000,2000)，[2000,3000)] 

  q_value：[[1,100)，[100,1000)，[1000,2000)，[2000,3000)] 

  e：[1，m1,m2,m3,m4,m5,n1,p1,p2,p3,p4,p5] 

  m：[[minus infinity，0）,0,（0，plus infinity]]

- **Shortest_path**

  【Parameters】

  scale :  [[2,10],[11,20],[20,30]]

  isDirected :  [False,True]

  type：[normal,zero,Upper triangular matrix,Lower triangular matrix]

  k：[1,1/2,1/3,1/4,1/5,0]

  method：[FW,D,BF,J]

- **Rotate**

  【Parameters】

  scale :  [[1,10],[11,20],[20,30]]

  shape：[normal,Upper triangular matrix,Lower triangular matrix,diagonal matrix]

  k：[1,1/2,1/3,1/4,1/5,0]

  angle：[90,180,270,-270,-180,-90]

- **F_oneway**

  【Parameters】

  theta :  [[0,10],[10,30],[30,50]]

  mean_a:  [[-100,0],[0,100]]

  mean_b:  [[-100,0],[0,100]]

  mean_c:  [[-100,0],[0,100]]

  len_a:  [[1,10],[11,30],[31,50]]
  
  len_b:  [[1,10],[11,30],[31,50]]
  
  len_c:  [[1,10],[11,30],[31,50]]









