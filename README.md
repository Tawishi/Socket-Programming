# Socket-Programming [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
(on a linux machine)<br>
C++/C code for sending encrypted message from Client to Server and decryting it at the server.
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
 ./client message
 ```
  ### Output
![image](https://github.com/Tawishi/Socket-Programming/blob/Caesar-ciper/Images/nsc2.jpg)<br>
![image](https://github.com/Tawishi/Socket-Programming/blob/Caesar-ciper/Images/nsc3.jpg)
<b>Note : </b><i>For string input with more than one word enclose input within ""</i>
