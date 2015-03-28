/*简易队列实现(环形数组方式) 模板类只支持内部数据类型*/
#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H
template<class T>
class Queue{
public:
	Queue(int capacity=10):start(0),rear(0){
		this->capacity=capacity;
		queue=new T[capacity];
	}
	~Queue(){
		delete[] queue;
		queue=NULL;
	}
	bool isEmpty(){
		return rear==start?true:false;
	}
	bool isFull(){
		return (rear+1)%capacity==start%capacity?true:false;
	}
	void push(const T& element){
		if(isFull()) throw "the queue is full!";
		else{
			queue[rear%capacity]=element;
			rear++;
		}
	}
	T pop(){
		if(isEmpty()) throw "the queue is empty!";
		else{
			T temp=queue[start%capacity];
			start++;
			return 	temp;
		}
	}
	int getNum(){
		return (rear-start);
	}
private:
	int capacity;
	T*  queue;
	int start;
	int rear;
};
#endif
