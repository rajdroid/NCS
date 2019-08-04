# NEW C STRING (NCS)

![String](string_structure.png)

While working with C strings in my professional projects. I came across an optimization, that by keeping the length of a string in the metadata we can improve some of the commonly used string operations.

In this project, I am exploring all these operations which we can optimize. Some of the operations, which I can think of right now are listed below.

+ strlen
+ strcmp
+ strcpy*
+ strcat*
+ strstr*
+ strreverse*

One more nice thing about this approach is that you can use all general functions which require C string, like printf.

Note: APIs containing * are still need to be investigated for possible optimizations.