# Socket-Programming
(on a linux machine)
  * [main](##main) branch
  * [Caesar-cipher](##Caesar-cipher) branch

## main
The main branch has C code for sending message from Server to Client.
### Running programs
1. Compile
  ```
  gcc tcp_client.c -o client
  gcc tcp_server.c -o server
  ```
2. Run<br>
  First run the server and then the client in seperate terminal windows
  ```
  ./server
  ```
  ```
  ./client
  ```
### Output
![image](https://github.com/Tawishi/Socket-Programming/blob/Caesar-ciper/Images/nsc1.jpg)
## Caesar-cipher
The Caesar-ciper branch has C++/C code for sending encrypted message from Client to Server and decryting it at the server.
1. Compile
  ```
  g++ tcp_client.cpp -o client
  g++ tcp_server.cpp -o server
  ```
2. Run<br>
  First run the server and then the client in seperate terminal windows
  ```
  ./server
  ```
  ```
  ./client
  ```
  ### Output
![image](https://github.com/Tawishi/Socket-Programming/blob/Caesar-ciper/Images/nsc2.jpg)
