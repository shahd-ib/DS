#include <iostream>
#include<cassert>
using namespace std;

class Queue1 {
private:
	int size{};
	int front{ 0 };
	int rear{ 0 };
	int added_elements{};
	int* array{};

	int next(int pos) {
		++pos;
		if (pos == size)
			pos == 0;
		return pos;
		//return (pos+1)%size;
	}
public:
	Queue1(int size) :
		size(size) {
		array = new int[size];
	}
	~Queue1() {
		delete[] array;
	}
	int isEmpty() {
		return added_elements == 0;
	}
	bool isFull() {
		return added_elements == size;
	}
	void enqueu(int value) {
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		added_elements++;
	}
	int dequeue() {
		assert(!isEmpty());
		int value = array[front];
		front = next(front);
		--added_elements;
		return value;
	}
	void display() {
		cout << "front " << front << " -rear " << rear << "\t";
		if (isFull())
			cout << "full";
		else if (isEmpty()) {
			cout << "empty\n\n";
			return;
		}
		cout << "\n";

		for (int cur = front, step = 0;step < added_elements;++step, cur = next(cur))
			cout << array[cur] << " ";
		cout << "\n\n";
	}
};
class Dequeue {
private:
	int size{};
	int front{ 0 };
	int rear  { 0 };
	int added_elements{};
	int* array{};
public:
	Dequeue(int size) :
		size(size) {
		array = new int[size];
	}
	~Dequeue() {
		delete[] array;
	}
	bool isFull() {
		return added_elements == size;
	}
	int isEmpty() {
		return added_elements = 0;
	}
	int next(int pos) {
		++pos;
		if (pos == size)
			pos = 0;
		return pos;
	}
	int prev(int pos) {
		pos--;
		if (pos == -1)
			pos = size-1;
		return pos;
	}
	void enqueue_rear(int value) {
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		added_elements++;
	}
	void enqueue_front(int value) {
		assert(!isFull());
		array[front] = value;
		front=prev(front);
		added_elements++;
	}
	int dequeue_front() {
		assert(!isEmpty());
		int value = array[front];
		front = next(front);
		--added_elements;
		return value;
	}
	int dequeue_rear() {
		assert(!isEmpty());
		int value = array[rear];
		rear = prev(rear);
		--added_elements;
		return value;
	}
	void display() {
		cout << "front " << front << " -rear " << rear << "\t";
		if (isFull())
			cout << "full";
		else if (isEmpty()) {
			cout << "empty\n\n";
			return;
		}
		cout << "\n";

		for (int cur = front, step = 0;step < added_elements;++step, cur = next(cur))
			cout << array[cur] << " ";
		cout << "\n\n";
	}
};
class Stack {
private:
	Queue1 q;
	int added_elements{};
public:
	void insert_front(int value) {
		int size = added_elements;
		q.enqueu(value);
		while (size--)
			q.enqueu(q.dequeue());
		++added_elements;
	}
public:
	Stack(int size) :
		q(size) {};
	void push(int value) { insert_front(value); }
	int pop() { --added_elements;return q.dequeue(); }
	int isFull() { return q.isFull(); }

};
int main()
{

}
