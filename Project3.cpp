/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 3: Encryption
 * 11 November 2022
 */

/* This is the driver file for the Queue and Cipher classes. This file tests
 * each class's constructor and member function functionality.
 */ 

#include <iostream>
#include "Queue.h"
#include "Cipher.h"
using namespace std;

int main(){
	// constructs a Queue object
	Queue queue1;

	cout<<"Enqueuing 5 items..."<<endl;

	// enqueue 5 items
	for(int k = 1; k <= 5; k++){
		queue1.enqueue(k);
	}
	
	// print size of queue1
	cout<<queue1.getSize()<<endl;

	// dequeue and retrieve all items in the queue
	cout<<"The values in the queue were:"<<endl;
	while(!queue1.isEmpty()){
		int value;
		queue1.dequeue(value);
		cout<<value<<" ";
	}
	cout<<endl;
	
	cout<<"After dequeuing all elements, the size of the Queue1 is: ";
	cout<<queue1.getSize()<<endl;
	
	Queue queue2;
	
	// tests queue2's maximum capacity
	cout<<"Testing maximum Queue capacity..."<<endl;
	for(int k = 1; k <= 101; k++){
                queue2.enqueue(k);
        }

	cout<<"Before dequeuing all elements, the size of the Queue2 is: ";
        cout<<queue2.getSize()<<endl;
	
	cout<<"The values in the queue were:"<<endl;
        while(!queue2.isEmpty()){
                int value;
                queue2.dequeue(value);
                cout<<value<<" ";
        }
        cout<<endl;

	cout<<"After dequeuing all elements, the size of the Queue2 is: ";
        cout<<queue2.getSize()<<endl;
	
	// constucts a Cipher object
	Cipher cipher1;
	
	// outputs each value in a default Cipher repeating key
	cout<<"These are each of the numbers in the key: "<<endl;
	for(int i = 0; i < 4; i++){
		cout<<*(cipher1.getCipher() + i)<<endl;
	}

	// outputs the memory address of the array representing the value's in
	// cipher1's Queue object
	cout<<"This is the memory address of the array that stores the key in Cipher: ";
	cout<<cipher1.getCipher()<<endl;

	// encodes a string and prints the returned encoded string
	string temp1 = cipher1.encodeMessage("Secret Message!");
	cout<<temp1<<endl;

	Cipher cipher2;

	// tests setCipher method and encoding with a key that holds negative values
	cout<<"Testing negative shift handling..."<<endl;
	int array1[] = {-3, -1, -7, 4, -2, -5};
	cipher2.setCipher(6, array1);

	cout<<"These are each of the numbers in the key: "<<endl;
        for(int i = 0; i < 6; i++){
                cout<<*(cipher2.getCipher() + i)<<endl;
        }

	cout<<"This is the memory address of the array that stores the Key in Cipher: ";
        cout<<cipher2.getCipher()<<endl;
        string temp2 = cipher2.encodeMessage("All I Want For Christmas is You");
        cout<<temp2<<endl;

	Cipher cipher3;

	// tests encoding with a key that holds values larger than the size of a
	// 26 character alphabet
        cout<<"Testing large shift handling..."<<endl;
        int array2[] = {-56, 100, -70, 46, -27, 59};
        cipher3.setCipher(6, array2);

        cout<<"These are each of the numbers in the key: "<<endl;
        for(int i = 0; i < 6; i++){
                cout<<*(cipher3.getCipher() + i)<<endl;
        }

        cout<<"This is the memory address of the array that stores the Key in Cipher: ";
        cout<<cipher3.getCipher()<<endl;
        string temp3 = cipher3.encodeMessage("Ciphers");
        cout<<temp3<<endl;

	// tests decodeMessage on each Cipher object's returned encoded string
	cout<<"Cipher 1: "<<cipher1.decodeMessage(temp1)<<endl;
	cout<<"Cipher 2: "<<cipher2.decodeMessage(temp2)<<endl;
	cout<<"Cipher 3: "<<cipher3.decodeMessage(temp3)<<endl;



	return 0;
}
