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
 ./client "message"
 ```
  ### Output
![image](https://user-images.githubusercontent.com/55306738/134533789-fe4a6e70-e214-4620-aa10-99d2974b6bb2.png)
<b>Note : </b><i>For string input with more than one word enclose input within ""</i>
