# authentication-system

A lightweight and secure authentication system developed in C++. This project provides basic user registration and login functionality using hashed passwords stored in a local file.
<br>
📌 Overview
This system demonstrates fundamental authentication mechanisms such as:
<ul>
  <li>User registration with secure password hashing</li>
  <li>Username uniqueness validation</li>
  <li>Login authentication with hashed password verification</li>
  <li>User data is persisted in a local file located at data/users.txt.</li>
</ul>
<br>
🛡️ Features:
<ol>
  <li><b>Secure Registration</b><br>
Users can register with a unique username and password. Passwords are hashed before being stored, providing basic data protection.</li>
  <li><b>Login Authentication</b><br>
The system validates the entered credentials against stored user data by comparing hashed passwords.</li>
  <li><b>Duplicate Username Prevention</b><br>
A validation mechanism ensures that each username is unique. Attempts to register with an existing username are blocked to maintain data integrity and avoid authentication conflicts.</li>
</ol>
<br>
<br>
<h3>What is Authentication?</h3><br>
Authentication is a process to authenticate a user, that is, to verify that someone is who they say they are.
It also keeps out suspicious or malicious users since their identities will not be verifiable.
Most authentication mechanisms are based on verifying a user’s credentials before they get access to the system. These credentials may be their username and password, security questions or a one-time pin sent to their mobile phones.
Credential-based authentication works by comparing user-provided credentials to a database record. When there is a perfect match between the two, users can access the account.
<br>
<h3>💡 What's Hashing?</h3>
<b>Hashing</b> is a process that transforms input data of arbitrary size into a fixed-size string of characters . It converts a password into an unreadable string. This transformation is performed using a mathematical algorithm known as a <b>hash function</b>. It has these proprieties:
<ul>
  <li>Deterministic: The same input always produces the same output.</li>
  <li>Fixed Output Size: Regardless of the input size, the output hash has a consistent length.</li>
  <li>Collision-Resistant: It is computationally infeasible to find two different inputs that produce the same hash.</li>
  <li>Avalanche Effect: A small change in input drastically changes the output hash</li>
</ul>

Example:
username: Alice, password: 1234
→password123 → a94a8fe5ccb19ba61c4c... (not reversible)
<b>Hashing is not only used in password protection and authentication systems but also in blockchain technologies and data integrity verification.</b>
⚠️In our project passwords are hashed before being saved.

<h3>What is Salting?</h3>
A salt is a <b>unique</b>, randomly generated string that is added to each password as part of the hashing process. As the salt is unique for every user, an attacker has to crack hashes one at a time using the respective salt rather than calculating a hash once and comparing it against every stored hash.

We used hashing and salting to enhance the security of the Authentication system!

<h3>📂 Data Handling</h3>
All user information is stored in "data/users.txt"

<h3>🐛 Issue Resolution</h3><br>
<b>Problem:</b> Duplicate Username Conflict <br>
<b>Issue:</b> Previously, when we registered with the same username twice , we faced a problem .The password of the second account won't be accepted because the program will look for the first occurence of the username in users.txt and it will find that the hashed passwords do not match.<br>
<b>Solution:</b> So, we added a function that will not allow you to use a username that's already used, eliminating ambiguity and ensuring reliable authentication behavior.
