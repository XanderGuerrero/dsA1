# dsA1
Data Structures % Algorithm Development Assignment 1 - locate all MP3s in a specified directory and display information about them.

DS Assignment #1

Write a program that searches directories for MP3 files and displays information about them.

Functional Requirements

The directories to be searched will be found as the arguments on the command line.
Your program must display a usage error (display exactly "Error: Usage: dsAssignment1 <directory ...>") and exit cleanly if there is not at least one argument on the command line.
Each argument might or might not end in a backslash. Your program must work with either case.
Each argument will not contain wildcards.
Valid directory examples: g:\tmp, v:\tmp\mp3, ., \, c:, v:\tmp\mp3\
You don't have to worry about whether or not the directory exists or if there are any files in it. FindFirstFile() will take care of that.
For each MP3 file in a directory, the filename will be of the following form:
artist name (with no dashes)
a dash ('-')
song title
".mp3"
You must loop using FindFirstFile() and FindNextFile() to find all of the MP3 files in a directory, for each directory.
Every time you find an MP3 file, you must extract the artist and song title information from the filename and store them in a node of a linked list.
If you do not use a linked list for this part of the assignment, your mark will be 0 and it will not be marked.
Once done with all directories, you must display the artist and title information in a formatted fashion.
This must be done through traversal of the linked list.
If the output list contains more than 20 entries, you must display "Press any key to continue" and use _getch() to get a key before displaying the 21st, 41st, 61st, etc. entry.
Do not prompt the user unnecessarily at the end of the list.
e.g. if there are exactly 40 entries, the user should only be prompted after the 20th entry
Once completely done, you must free all allocated memory.
Bug List Requirements

You must submit buglist.txt, containing the known set of program limitations, bugs, and issues (similar to the C project or the OOP assignment #1).
The first line of the file must state "DS Assignment #1 Bug List for " and then state your full name.
The list should be specific and easy to understand.
If, as far as you know, the program has no flaws, simply state "This assignment is complete."
Other Requirements

Do not get user input except as described in these requirements.
Do not clear the screen at any time in this program.
You must do error checking where necessary.
It must not use global variables.
It must not use goto.
It must be programmed in C or C++ (your choice).
The SET Coding Standards must be adhered to.
File Requirements

Call your project dsA1.
Call the file with your main() in it dsA1.c or dsA1.cpp.
Before submitting, change the filename of dsA1.exe to dsA1.x.
Put all source files, buglist.txt, and dsA1.x into the appropriate D2L drop box when you submit your assignment.
Assumptions / Hints

The artist name will not contain a dash.
All filenames ending in .mp3 will be of the proper form as described in the requirements.
It is not required that the files actually be valid MP3 music files. The contents are irrelevant.
You really do want to do error checking.
