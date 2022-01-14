# Threaded Prime Compairason

The code just counts the number of prime numbers up to n using an implementation of the Miller Rabin algorithm.
### Dependencies
1) gcc (or any other c++ compiler)

2) cmake

3) make

4) [sodium libary](https://github.com/jedisct1/libsodium)

`sudo apt install make cmake build-essential libsodium-dev -y`
### Compiling
```
$ mkdir build
$ cd build
$ cmake ../
$ make 
```
### Running
Run the executable in the `bin` folderand specify up to what term you wanna calculate

`./primeT.o number` or `./primeN.o number`