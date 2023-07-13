/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 3: Encryption
 * 11 November 2022
 */

/* This class provides the functionality for a variation of a Caesar Cipher.
 * A Cipher object has a Queue object which is used to create a repeating key
 * that is used for the encoding and decoding of strings. A Cipher object by 
 * default has a repeating key of 1, 2, 3, 4. This may be updated using
 * setCipher and may be a key of any positive or negative integers, and
 * a key up to a size of 100 elements. This class also has a method getCipher
 * that allows a pointer to an array holding the repeating key to be returned.
 * A Cipher object uses the member functions encodeMessage and decodeMessage
 * to encode a string using the key and decode a string using the key, 
 * respectfully.
 */


#include <iostream>
#include <string>
#include "Cipher.h"

using namespace std;

// constructs a Cipher object and sets numPtr to an array of size 4
// including the elements 1, 2, 3, and 4.
Cipher::Cipher(){
        for(int i = 1; i < 5; i++){
                master_key[i-1] = i;
		queue.enqueue(master_key[i-1]);
        }
	numPtr = master_key;
}

// clears any pre-existing repeating key values, sets the repeating key
// by enqueuing all values in key[], and sets numPtr to key.
void Cipher::setCipher(int arraySize, int key[]){
        queue.clear();
        for(int i = 0; i < arraySize; i++){
                queue.enqueue(key[i]);
        }
	numPtr = key;
}

// returns a pointer to an array representing the repeating key
int* Cipher::getCipher(){
        return numPtr;
}

// contains encoding functionality
string Cipher::encodeMessage(string in){
	string encoded = "";
	
	// filters out numbers, special characters, and spaces
	for(int i = 0; i < in.size(); i++){
		if(isalpha(in[i])){
			if(isupper(in[i])){
				encoded += tolower(in[i]);
			}
			else{
				encoded += in[i];
			}
		}
	}
	
	// declares variables needed for encoding functionality
	int counter = 0;
	int tempIndex = 0;
        int temp[queue.getSize()];

	// iterates through each char of encoded and increases it by the corresponding key value
        while(counter < encoded.size()){
		if(!queue.isEmpty()){
       			int value;
        	        queue.dequeue(value);
			temp[tempIndex] = value;
			// executes if the current value in the key is negative
			if(static_cast<int>(encoded[counter]) - 97 + (value%26) < 0){
				encoded[counter] = static_cast<char>(((26+(static_cast<int>(encoded[counter])-97)+(value%26))%26)+97);
			}
			// executues if the current value in the key is non-negative
			else{
				encoded[counter] = static_cast<char>(((static_cast<int>(encoded[counter])-97+(value%26))%26)+97);
			}
			// increments counter and tempIndex
			counter++;
			tempIndex++;
		}
		else{
			// clears the queue and re-enqueues the key based on temp[]
			// resetting the queue to the original repeating key
			queue.clear();
			for(int n : temp){
				queue.enqueue(n);
			}
			// resets tempIndex to zero to avoid attempted access to
			// an element outside the bounds of the temp array
			tempIndex = 0;
		}
        }
	// resets the queue after encoding
	queue.clear();
	for(int n : temp){
       		 queue.enqueue(n);
        }
	return encoded;
}

// contains decoding functionality
string Cipher::decodeMessage(string in){
	// declares variables needed for decoding functionality
	string decoded = in;
	int counter = 0;
	int tempIndex = 0;
        int temp[queue.getSize()];
	// iterates through each char of decoded and decreases it by the corresponding key value
        while(counter < decoded.size()){
                if(!queue.isEmpty()){
                        int value;
                        queue.dequeue(value);
                        temp[tempIndex] = value;
                        decoded[counter] = static_cast<char>((((static_cast<int>(decoded[counter])-97)+(26-(value%26)))%26)+97);
                        counter++;
			// increments counter and tempIndex
			tempIndex++;
                }
                else{
			// clears the queue and re-enqueues the key based on temp[]
                        // resetting the queue to the original repeating key
			queue.clear();
                        for(int n : temp){
                        	queue.enqueue(n);
                        }
			// resets tempIndex to zero to avoid attempted access to
                        // an element outside the bounds of the temp array
			tempIndex = 0;
                }
        }
        return decoded;
}
