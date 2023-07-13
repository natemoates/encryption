/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 3: Encryption
 * 11 November 2022
 */

/* This is the header file for the Cipher class */


#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include "Queue.h"

class Cipher{
	private:
		int* numPtr;
		int master_key[4];
		Queue queue;
	public:
		// default constructor
		Cipher();
		void setCipher(int, int[]);
		// method that returns a pointer to an int array
		int* getCipher();
		std::string encodeMessage(std::string in);
		std::string decodeMessage(std::string in);
};

#endif
