/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 3: Encryption
 * 11 November 2022
 */

/* This is the header file for the Queue class */

#ifndef QUEUE_H
#define QUEUE_H

class Queue{
	private:
		struct QueueNode{
			int value;
			QueueNode *next;
			QueueNode(int value1, QueueNode *next1 = nullptr){
				value = value1;
				next = next1;
			}
		};
		// tracks the front and rear of the queue
		QueueNode *front;
		QueueNode *rear;
		// tracks size of the queue
		int queueSize = 0;
	public:
		// constructor and destructor
		Queue();
		~Queue();

		// member functions
		void enqueue(int);
		void dequeue(int &);
		int getSize();
		bool isEmpty() const;
		bool isFull() const;
		void clear();
	};

#endif
