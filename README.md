# authentication-system
C++ Authentication System project 
1-cd authentication-system
2-mkdir build
3-cd build
4-cmake ..
5-make
6-./AuthentificationSystem 
the users data will be registered in data/users.txt
*problem X: when we registered with the same username twice , we faced a problem .
the password of the second account won't be accepted because the program will look for the first occurence of the username in users.txt and it will find that she hashed passwords do not match.
So, we added a function that will not allow you to use a username that's already used
