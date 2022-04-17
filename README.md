# Balanced-Strings
This program will determine whether an input string is accepted for any language that belongs to the set A. The parser is structured around the recursive descent method.


![Screenshot (9)](https://user-images.githubusercontent.com/67528141/163653141-a70258d1-c694-4253-b665-ffa4647b9f16.png)


The following is an example with c = '(' and s = ')'. 


![Screenshot (10)](https://user-images.githubusercontent.com/67528141/163720957-30ee5820-e25f-4b9c-826f-f37e64e13525.png)


The first command line argument contains your chosen values for c and s, written as 'cs'.

The second command line argument is your input string x, written as 'x'.

If the given string is accepted, a parse tree will be generated. The data value of the tree vertices are either one of the terminals (c or s), or \<exp\> if the node denotes an expression. The parse tree is printed using an implementation of pre-order traversal, which will explain the order in which each node is printed onto the screen.
