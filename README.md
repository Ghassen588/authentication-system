# authentication-system

A lightweight and secure authentication system developed in C++. This project provides basic user registration and login functionality using hashed passwords stored in a local file.

📌 Overview
This system demonstrates fundamental authentication mechanisms such as:

User registration with secure password hashing

Username uniqueness validation

Login authentication with hashed password verification

User data is persisted in a local file located at data/users.txt.

🛡️ Features
Secure Registration
Users can register with a unique username and password. Passwords are hashed before being stored, providing basic data protection.

Login Authentication
The system validates the entered credentials against stored user data by comparing hashed passwords.

Duplicate Username Prevention
A validation mechanism ensures that each username is unique. Attempts to register with an existing username are blocked to maintain data integrity and avoid authentication conflicts.

What is Authentication?
Authentication is a process to authenticate a user, that is, to verify that someone is who they say they are.
It also keeps out suspicious or malicious users since their identities will not be verifiable.
Most authentication mechanisms are based on verifying a user’s credentials before they get access to the system. These credentials may be their username and password, security questions or a one-time pin sent to their mobile phones.
Credential-based authentication works by comparing user-provided credentials to a database record. When there is a perfect match between the two, users can access the account.

💡 What's Hashing?
Hashing is a process that transforms input data of arbitrary size into a fixed-size string of characters . It converts a password into an unreadable string. This transformation is performed using a mathematical algorithm known as a hash function. It has these proprieties:
Deterministic: The same input always produces the same output.
Fixed Output Size: Regardless of the input size, the output hash has a consistent length.
Efficient: Hash computation is fast and resource-light.
Collision-Resistant: It is computationally infeasible to find two different inputs that produce the same hash.
Avalanche Effect: A small change in input drastically changes the output hash
Example:
username: Alice, password: 1234
→password123 → a94a8fe5ccb19ba61c4c... (not reversible)
Hashing is not only used in password protection and authentication systems but also in blockchain technologies and data integrity verification.
⚠️In our project passwords are hashed before being saved.

What is Salting?
A salt is a unique, randomly generated string that is added to each password as part of the hashing process. As the salt is unique for every user, an attacker has to crack hashes one at a time using the respective salt rather than calculating a hash once and comparing it against every stored hash.

We used hashing and salting to enhance the security of the Authentication system!

📂 Data Handling
All user information is stored in "data/users.txt"

🐛 Issue Resolution
Problem: Duplicate Username Conflict
Issue: Previously, when we registered with the same username twice , we faced a problem .The password of the second account won't be accepted because the program will look for the first occurence of the username in users.txt and it will find that the hashed passwords do not match.
Solution: So, we added a function that will not allow you to use a username that's already used, eliminating ambiguity and ensuring reliable authentication behavior.
