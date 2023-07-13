/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 3: Encryption
 * 11 November 2022
 */

/* This Queue class contains the constructor, destructor, and member functions
 * of a Queue data structure. This is a dynamic Queue data structure, and is 
 * implemented using linked lists. This queue has a maximum capacity of 100
 * QueueNode structures.
 */

#include <iostream>
#include "Queue.h"
#include <cstdlib>

using namespace std;

// constructor
Queue::Queue(){
	front = nullptr;
	rear = nullptr;
}

// destructor
Queue::~Queue(){
	QueueNode * garbage = front;
	while(garbage != nullptr){
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = front;
	}
}

// inserts the value in num at the rear of the queue
void Queue::enqueue(int num){
	if(isFull()){
		cout<<"Maximum Queue capacity has been reached.\n"<<endl;
	}
	else if(isEmpty()){
		queueSize++;
		front = new QueueNode(num);
		rear = front;
	}
	else{
		queueSize++;
		rear->next = new QueueNode(num);
		rear = rear->next;
	}
}

// removes the value at the front of the queue and copies it into num
void Queue::dequeue(int &num){
	QueueNode *temp = nullptr;
	if(isEmpty()){
		cout<<"The queue is empty.\n";
	}
	else{
		queueSize--;
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

// returns the size of the Queue
int Queue::getSize(){
	return queueSize;
}

// returns true if the queue is empty and false otherwise
bool Queue::isEmpty() const{
	if(front == nullptr){
		return true;
	}
	else{
		return false;
	}
}

// returns true if the queue is full and false otherwise
bool Queue::isFull() const{
	if(queueSize >= 100){
		return true;
	}
	return false;
}

// dequeues all the elements in the queue
void Queue::clear(){
	int value; // dummy variable for dequeue
	while(!isEmpty()){
		dequeue(value);
	}
	queueSize = 0;
}
