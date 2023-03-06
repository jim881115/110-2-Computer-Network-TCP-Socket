# The On Line Test of TCP socket
## Requirement
The major requirement of the on-line test is to implement a program to receive and send message from/to teacher’s program through TCP socket. The data structure of message and some constant values are list as following: <br/>
```C
struct Msgbuf
{
    long mtype;
    char context[20];
};
```
**The message exchange rules are list as following.**
* Initial: The teacher’s program will create a TCP socket. The server port is 9999.
* Step 1: Your program should connect with TCP server. The mtype is 101 and context1 is your student ID.
* Step 3: Your program should send a message to the server. The mtype is 300, the context is the XOR result of the key with the last 8 digital numbers of your student ID.
* Step 4: Your program will receive the packet from the server. When the mtype is 203, you are pass. Otherwise,

## Implement Requirement:
Your C/C++ programs should be compiled by gnu C/C++ compiler, and can be running on UNIX/Linux based machine. If your programs cannot be complied by gnu C/C++ compiler, or cannot not be running on UNIX/Linux based virtual machine and real machine, your programs will be treat as garbage. The IP of teacher is 134.208.2.60, the service port is 9999. Suppose that your program can pass the on-line test, some of the connection information will be recorded in teacher’s computer.

