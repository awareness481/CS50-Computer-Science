* Week 2 Documentation: http://docs.cs50.net/2017/x/psets/2/pset2.html
* edX Course: https://courses.edx.org/courses/course-v1:HarvardX+CS50+X/info
* cs50 Reference: https://reference.cs50.net


1. **Initials.C**

* Implement a program that, given a person’s name, prints a person’s initials, per the below.

> $ ./initials
> Regulus Arcturus Black
> RAB

2. **Ceasar.C**

* Implement a program that encrypts messages using Caesar’s cipher, per the below.

> $ ./caesar 13
> plaintext:  HELLO
> ciphertext: URYYB

3. **Vigenère.C**

* Implement a program that encrypts messages using Vigenère’s cipher, per the below.

> $ ./vigenere ABC
> plaintext:  HELLO
> ciphertext: HFNLP


**Notes**

* Do not use scanf to read strings. From [docs.oracle.com](https://docs.oracle.com/cd/E19683-01/816-0213/6m6ne389s/index.html) :
> A directive composed of one or more white-space characters is executed by reading input until no more valid input can be read, or up to the first byte which is not a white-space character which remains unread.
> A directive that is an ordinary character is executed as follows. The next byte is read from the input and compared with the byte that comprises the directive; if the comparison shows that they are not equivalent, the directive fails, and the differing and subsequent bytes remain unread.
