CSCI 103 Programming Assignment 4, A Mazeing BFS

Name: Karime Maamari

Email Address: maamari@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

:
=============================== Prelab ==================================

1. What data structure will you use to remember which cells have
already been added to the queue or not?

: A 2D boolean array will be used to remember which cells have already been 
added to the queue or not

2. At what step of the BFS algorithm do you have to mark a cell as visited?

: After it is added to the queue, the cell will be marked as visited

=============================== Review ==================================

1. Describe your "mymaze.txt" test file. It should have multiple paths
of different distances. When you ran your program on it, did your program 
behave as expected?

: My mymaze.txt test file was a 4 by 5 rectangle with the start in the upper 
left and the finish in the upper right. I allowed for two paths of travel: 
one directly across the top, and one that circumvented the edges/bottom. As 
expected, the program chose the shorter of the two paths.

