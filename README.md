# arrangements.cpp
Assignment 7
Arrangements: Panelist and Dinner Guest Shuffle

EC327 Summer 2019

1 Introduction
1.1 Assignment Goals
1.2 Group Size
1.3 Due Date
1.4 Assignment Value
1.5 Late policy
1.6 Submission Link
2 Problem Definition
2.1 Panelist Shuffle
2.2 Dinner Guest Shuffle
3 The assignment: arrangements class
3.1 The Arrangements Class
3.2 The panel_shuffles method
3.3 The dinner_shuffles method
3.4 The panel_count method
3.5 The dinner_count method
3.6 Error handling
3.7 Program name
3.8 Libraries allowed
3.9 No brackets
3.10 Downloads
4 Grading Scheme
5 The alternate assignment
5.1 Downloads
1 Introduction
1.1 Assignment Goals
The assignment goals are to help you learn about

recursion
avoiding 
O
(
2
N
)
 complexity for Fibonnaci-like calculations
1.2 Group Size
The maximum group size is 3 students.

1.3 Due Date
This assignment is due 2019-06-19 at 11:59pm (just before midnight).

1.4 Assignment Value
This assignment is worth 15 points.

The alternate assignment (easier) is worth 10 points.

1.5 Late policy
Late assignments will be accepted until the beginning of the lecture immediately following the due date.

If the natural grade on the assignment is 
g
, the number of hours late is 
h
, and the number of hours between the assignment due time and the next class is 
H
, the new grade will be

(h > H) ? 0 : g * (1- h/(2*H))
If the same assignment is submitted ontime and late, the grade for that component will be the maximum of the ontime submission grade and the scaled late submission grade.

1.6 Submission Link
You can submit here: arrangements submit link

2 Problem Definition
2.1 Panelist Shuffle
A number of panelists are seated at a long table. The moderator of the panel asks them to all stand, and sit back down either one seat to the left, one seat to the right, or in the same chair.

All panelists must have a chair, and the panelists on the ends only have two options, not three.

Your task is to determine all possible ways that the panelists can do this “panelist shuffle”, and separately to efficiently compute how many arrangements there are for a particular size of table.

2.2 Dinner Guest Shuffle
This second problem is similar, but now the table is circular. The host of the dinner party asks all the guests to stand, and sit back down either one seat to the left, one seat to the right, or in the same chair.

All dinner guests must have a chair once everyone is seated. In this problem, all dinner guests have three options.

Your task is to determine all possible ways that the dinner guests can do this “dinner guest shuffle”, and separately to efficiently compute how many arrangements there are for a particular size of table.

3 The assignment: arrangements class
Write a program arrangements.cpp with a class arrangements which has several methods as shown below:


class Arrangements {
  public:
    Arrangements();
    Arrangements(string thenames);
    vector<string> panel_shuffles(int n);
    vector<string> dinner_shuffles(int n);
    double panel_count(int n);
    double dinner_count(int n);
};
You may add other methods and data structures to the class as necessary to solve the problem.

3.1 The Arrangements Class
Each Arrangement object uses a fixed set of names for the dinner guests. The guests are labelled with individual characters in a string. So, for example, the string

abc12
represents the initial seating arrangement and maximum size of table (5). The guests names are a, b,c, 1, and 2. a is sitting at the end of the table next to b, and so forth.

In the standard constructor, the names shall be a-zA-Z and the maximum size of table is 52.

In the one-argument constructor, the names are passed in as a string in the format just described, and the maximum size of table is set to the length of the name string.

3.2 The panel_shuffles method
The panel_shuffles method should return all possible arrangements of n panelists as a vector of strings. The names used should be the first n names as designated in the constructor.

The order of the panelist arrangements is not specified.

Here is a simple example. If the panelists are 12345, then the result of panel_shuffles(3) will be

123
213
132
In this case, 2 has three options, and both 1 and 3 have no further choices once 2 has chosen a seat.

3.3 The dinner_shuffles method
The dinner_shuffles method should return all possible arrangements of n dinner guests as a vector of strings. The names used should be the first n names as designated in the constructor.

The ends of the string represent the adjacent end chairs of the circular table.

The order of the dinner guest arrangements is not specified.

Here is a simple example. If the dinner guests are abcde, then the result of dinner_shuffles(3) will be

abc
acb
bac
bca
cab
cba
3.4 The panel_count method
Write a method that will calculate the number of ways the panelists can be arranged if there are n of them. This function should efficiently calculate the count of arrangements for values of n up to 100 using the mathematical formulas for large Fibonacci numbers.

The actual formula is related to the Fibonacci number sequence.

3.5 The dinner_count method
Write a method that will calculate the number of ways the dinner guests can be arranged if there are n of them. This function should efficiently calculate the count of arrangements for values of n up to 100 using the mathematical formulas for large Fibonacci numbers.

The actual formula is related to the Fibonacci number sequence.

3.6 Error handling
If a method is called with a value for the number of panelist/guests which exceeds the number of names, an exception should be thrown. The exception should be the number which caused the problem. For example:

Arrangements v("123");
v.panel_count(5);
should throw the exception 5.

3.7 Program name
The template program and the main to be used for testing is provided in arrangements_original.cpp

3.8 Libraries allowed
You must include the following libraries

<algorithm>
<array>
<cmath>
<cstdint>
<iomanip>
<iostream>
<string>
<vector>
"timer.h"
For the moment, no other includes are permitted.

3.9 No brackets
Brackets (i.e. []) are not permitted. Use the access and modifier methods instead.

3.10 Downloads
arrangements_answers.txt this is the output of main() when run with no arguments
arrangements_original.cpp this is the template file
timer.h you will need this in your directory to compile
arrangements_checker.py this is the checker.
4 Grading Scheme
Out of 100 total points, the grade is determined as follows:

10 points for passing the specifications of panel_count
10 points for passing the specifications of dinner_count
15 points for passing the specifications of panel_shuffles
15 points for passing the specifications of dinner_shuffles
10 points for error handling
30 points for program speed (your program must pass the specifications to get credit for this)
5 points for astyle (% file unchanged by astyle)
5 points for cpplint, -1 deduction for each problem
5 The alternate assignment
Write a program arrangements_alt.cpp which implements the Arrangements class and the following methods:

the standard constructor Arrangements()
the panel_shuffles method
the panel_count method
Out of 100 total points, the grade is determined as follows:

20 points for passing the specifications of panel_count
40 points for passing the specifications of panel_shuffles
30 points for program speed (your program must pass the specifications to get credit for this)
5 points for astyle (% file unchanged by astyle)
5 points for cpplint, -1 deduction for each problem
5.1 Downloads
arrangements_alt_answers.txt this is the output of main() when run with no arguments
arrangements_alt_original.cpp this is the template file
timer.h you will need this in your directory to compile
arrangements_alt_checker.py this is the checker.
