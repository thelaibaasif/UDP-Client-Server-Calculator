# UDP Client-Server Calculator

## Description
This project demonstrates a UDP client-server model where the server acts as a calculator. The client sends two numbers and an arithmetic operation (add, subtract, multiply, divide, modulus) to the server, which calculates the result and returns it to the client. The server stays active until the client sends a stop command.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
  - [Server Side](#server-side)
  - [Client Side](#client-side)
- [Implementation Details](#implementation-details)

## Introduction
This project showcases a simple UDP client-server application implemented in C. The server functions as a calculator, performing various arithmetic operations based on the client's input. The server remains active until explicitly terminated by the client.

## Features
- Perform basic arithmetic operations (add, subtract, multiply, divide, modulus)
- Continuous server operation until client termination

## Requirements
- GCC compiler for C
- Basic knowledge of UDP networking
- Basic understanding of C programming

## Usage

### Server Side
1. Compile the server code:
    ```sh
    gcc -o udp_server udp_server.c
    ```
2. Run the server:
    ```sh
    ./udp_server
    ```

### Client Side
1. Compile the client code:
    ```sh
    gcc -o udp_client udp_client.c
    ```
2. Run the client:
    ```sh
    ./udp_client
    ```

## Implementation Details
### Server Code
The server listens for incoming client messages and performs arithmetic operations based on the client's request. The server remains active until explicitly terminated by the client.

### Client Code
The client sends two numbers and an arithmetic operation to the server, receives the result, and displays it. The client can terminate the server by sending a stop command.

### Example Usage
**Client Side:**
```sh
Enter two numbers: 2, 3
Enter operation: modulus
Output: 2
