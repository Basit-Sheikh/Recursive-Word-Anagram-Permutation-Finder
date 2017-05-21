# Recursive Word Anagram/Permutation Finder
This program reads in a word, and by rearranging the letters and comparing them to all the words in a dictionary, comes up with all  possible word combinations. This program is written using none of C++'s iteration constructs (do, while, for, and goto). Everything, including reading/writing file IO, is done recursively.

This program is definitely not the most efficient in terms of run-time (in fact, in some cases you may even have to increase the max stack space in your IDE settings!), however it does showcase a very strong understanding of recursion and how the recursive call stack functions, which in my opinion is a very important concept.

# IMPORTANT - IF YOUR PROGRAM CRASHES DUE TO STACKOVERFLOW, READ THIS:

Like I mentioned above, this program was not meant to be efficient. Because of the heavy amount of recursive calls on the call stack, the stack may reach max capacity which results in a stack overflow and the program crashing. To fix this, you will need to increase your stack reserve in the project settings:

# Windows OS: 

Visual C++ has a default stack size of 1MB, Select PROJECT / Properties. In the Property Pages dialog, in the left panel,
select Configuration Properties / Linker / System. In the right panel, select Stack Reserve Size, and in the drop down list to its right, type in a new stack size (10000000 is approximately 10MB - increase it further if the problem persists). Click OK.

# Mac OSX:

In Xcode you'll have to add -Wl,-stack_size,10000000 to the Other Linker Flags field. Click on the Project Name, Select Build Settings at the top then scroll below to find the Linker subsection.

# Linux:

In Linux, run the command ulimit -s 65536 before compiling your program.




