## Library installation
    To use the NCS in your project just do `git clone` and clone the source code from the Github. After that, follow below steps:
    1. Move to NCS source code.
        `cd NCS`
    2. Make the library.
        `make`
    3. Use `library.h` in your source code to get all the declarations and point to `lib` folder during your application compilation. For example:
        `gcc -o test_app test_app.c -Llib -lncs`

## Tests setup
    There is also test suite available which you should run before using actual library in your project. Steps to run test suite are given below:
    1. Install `libcheck` test framework for your operating system. In my case I used following command on Arch Linux:
        `sudo pacman -S check`
    2. After that just run:
        `make test`
