# C_Process_Management_and_Redirection

This GitHub repository showcases a project focused on understanding and implementing process control in C, using system calls like fork, exec, and file redirection techniques. This project consists of four tasks, each designed to enhance knowledge of process creation, execution, and output management in Unix-based systems.

## Project Overview and Key Functionalities

### Task 1 - Forking Processes (f_test):

The program f_test takes an integer N as an input and creates a child process using fork.
The child process prints odd numbers from 1 to N, while the parent process prints even numbers.
Proper synchronization ensures that the parent waits for the child process to complete.

### Task 2 - Separate Odd and Even Number Printers (odds, evens):
Two standalone C programs, odds and evens, are created.
Each program accepts an integer N and prints either odd or even numbers up to N, demonstrating separate process functionalities without the use of fork.

### Task 3 - Exec System Call (fe_test):
The fe_test program mirrors the functionality of f_test but uses the exec system call.
The program forks two child processes, with one executing the odds program and the other executing the evens program, allowing them to run concurrently.
The parent process waits for both children to complete, showcasing concurrent process management.

### Task 4 - Output Redirection to File (to_file):
The to_file program takes two command-line arguments: the name of a program to execute and a file name for output redirection.
It demonstrates the use of file descriptors, open, and dup to redirect the standard output of the exec’d program to a specified file.

### Safety Measures and Utility Function:
Implemented safety measures to prevent unintentional creation of numerous processes (a "fork bomb").
Incorporated a limit_fork function in the main program to set a maximum number of processes a user can spawn.
Used shell command ulimit -Su as an additional precaution.

To Run Task 1:
    Syntax: ./f_test <value>
    Ex:     ./f_test 1000


Task 2: 
    See odd.c and even.c


To Run Task 3:
    Syntax: ./fe_test <value>
    Ex:     ./fe_test 1000


Task 4: 
    Syntax: ./to_file <program> <file>
    Ex: ./to_file ./odd output.txt
    NOTE: if using odd.c or even.c files for task four, make sure to replace uncommented code with commented code for main function.
