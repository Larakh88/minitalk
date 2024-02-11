# Minitalk

## Introduction
This project consists of creating a client-server communication program using UNIX signals. 
The communication is established between a client and a server, with the server being started first and printing its process ID (PID). 
The client will take two parameters: the server's PID and the string to send. Upon receiving the string, the server will print it.
Bitwise operations are used to efficiently transmit the data between the client and server.

## Implementation Overview
The provided implementation includes two files: **`client.c`** and **`server.c`**, which represent the client and server functionalities, respectively.

**`client.c`**
* **`main`**: Takes two parameters (server PID and string to send) and calls the **`action`** function to send the string to the server using signals.

**`server.c`**
* **`main`**: Prints the server's PID, sets up signal handlers for **`SIGUSR1`** and **`SIGUSR2`**, and enters an infinite loop to listen for signals from clients.
* **`hdl`**: Signal handler function to process received signals and reconstruct the transmitted character.

## Usage
1. To compile the project, run the **`make`** command in the terminal.
2. Start the server by running **`./server`**. The server will display its PID and wait for incoming signals.
3. To send a string to the server, run the below command with the previously displayed server PID:
   
   ```./client [server_PID] [string]```
