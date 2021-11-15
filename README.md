## COMER, an enhancement approach of CT which supports metamorphic relation matching

As shown in the flow chart, COMER is divided into four stages. The first stage is to model and determine the metamorphic relations, the second stage is to generate abstract test cases, the third stage is to generate concrete test cases, and the last stage is to judge whether there are bugs in the software.

![image-20211115105631858](https://github.com/syjya/Comer/blob/master/flow chart.JPG)

We mainly explored 31 software subjects. For each of these software subjects, we provide a folder containing  all the code. In addition to the codes of the above four stages, we also provide experimental results, please refer to section Data.



#### Model and determine the metamorphic relations

Functional descriptions, inputs, outputs, and metamorphic relations of all subjects are listed in **metamorphic relation.pdf**.  

The abstract models of subjects are shown in **abstract models.md**. For each subject, we list its parameters and their possible values, as well as constraints if any exist.



#### Abstract test case generation

This includes **ART_Cons.jar**, **ART_Cons_MR.jar**, and **Baseline.jar**, corresponding to CT, COMER, and TRI_MCT respectively.Input parameters include generating the abstract test case store path, dimension, and file name (numeric only) .For example，run the command "java  -jar ART_Cons.jar  /ART_Cons  2  0"，then a TXT file named 0 is generated under the path "/ART_Cons" to hold an abstract set of test cases that meet 2-dimensional coverage. In the generated TXT file, each line represents a test case.



#### Concrete test case generation

- **Scipy**

We mainly explored 3 software subjects about scipy，includes "F_oneway"、"Rotate" and "Shortest_path".In this phase, each of them provides a script that inputs an abstract set of test cases, outputs a concrete set of test cases (both input and output), and the results of matching the metamorphic relation.

Take F_oneway as an example. The script **m_f_oneway.py** has three variables, data_path, base_test_path and result_path, representing the abstract test case path, the concrete test case path and the result path respectively. Before running the program, we need to input the abstract test case set, that is, to ensure that the correct abstract test case set is saved in data_path. Then run the program, the concrete test case set will be automatically generated and saved in the base_test_path, and the matching metamorphic relation results will be automatically saved in the result_path.

- **Others**

In addition to the three subjects associated with Scipy, there are 28 software subjects. In this phase, each of them provides **model_CT.cpp**,**model_COMER.cpp**, and **model_Random.cpp** for converting abstract test cases into concrete test cases, corresponding to CT, COMER(TRI_MCT), and Random, respectively.

The input parameters of model_CT.cpp and model_COMER.cpp are the same, including the input of the abstract test case set TXT file and the output of the concrete test case directory path.For example，run the command "model_CT.exe  INPUT.txt  OUTPUT"，then a group of TXT files is generated in the OUTPUT directory. Each TXT file represents a concrete test case. The number of TXT files is equal to the size of the abstract test case set, that is, the number of INPUT.txt lines.

Unlike the two above, the model_Random.cpp parameters are the number of test cases and the output of the concrete test case directory path.For example，run the command "model_Random.exe  100  OUTPUT"，then a group of TXT files is generated in the OUTPUT directory. Each TXT file represents a concrete test case. The number of TXT files is 100.

In addition, the **source code** of the software is provided. **Variants code** is also provided if the software is the correct version.For these 28 software, there is a directory named version under concrete directory. Directory 0 under version directory stores the source code of the software, directory 1 stores the first variant code, and so on.



#### Judge whether there are bugs in the software

- **Scipy**

This part of code is included in the script of Concrete Test Case Generation stage.

- **Others**

In addition to the three subjects associated with Scipy, there are 28 software subjects. In this phase, each of them provides a script named **judgemr.cpp**. It can search and count the matchings of the metamorphic relations between generated test cases.The script has two input parameters, the concrete test case set directory and the path to save the results.For example，run the command "judgemr.exe  ./testcese  output.txt". Then, a TXT file named output will be generated in the current directory, which stores the results of matching the metamorphic relations of the concrete test case set (./testcase). Each line represents a pair of test cases matching a metamorphic relations. For example, the first line "2 3 0 1" indicates that test case 2 and test case 3 match the 0 metamorphic relations, and their output rules satisfy the output rules of the metamorphic relation. Here, the last parameter 1 means that the output rule of the test case pair satisfies the output rule of the metamorphic relations, and 0 means that the output rule does not satisfy, that is, there is a bug in the code.



#### Data

It also provides the results of our emprical studies of COMER, including **results.xlsx**、**time_abstract.xlsx**、**time_concrete.xlsx**、**featuresOfMR.xlsx** and **ComerVSOptimal.xlsx**, and is explained at **data.md**.

It also includes the descriptions of  five previously unknown bugs,that is **novelBugs.md**.





