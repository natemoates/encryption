# Nathaniel Oates
# CPSC 1070: 010
# Project 3: Encryption
# 11 November 2022

# This command compiles Queue.cpp and Cipher.cpp into object code
# Then this command compiles Project3.cpp and both object code files
# into Project3.out in C++11 and prints out any errors
compile:
	g++ Queue.cpp -c
	g++ Cipher.cpp -c
	g++ Project3.cpp Queue.o Cipher.o -o Project3.out -std=c++11 -Wall

# This command runs Project3.out
run:
	./Project3.out

# This command removes all .out files in the directory
clean:
	rm *.out
