#include <iostream>
#include <cassert>
using namespace std;

class Vector {
private:
	int* arr = nullptr;
	int size = 0;

public:
	Vector(int size) :
		size(size) {
		if (size < 0)
			size = 1;
		arr = new int[size] {};
	}
	~Vector() {
		delete[] arr;
		arr = nullptr;
	}
	void set(int idx, int val) {
		assert(0 <= idx && idx < size);
		arr[idx] = val;
	}
	void print() {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void Right_Rotate() {
		int last_element = arr[size - 1];
		for (int i = size - 1;i > 0;i--)
			arr[i] = arr[i - 1];
		arr[0] = last_element;
	}
	void Left_Rotate() {
		int first_element = arr[0];
		for (int i = 0;i < size;i++)
			arr[i] = arr[i + 1];
		arr[size - 1] = first_element;
	}
	void Right_Rotation_with_steps(int times) {
		times %= size;
		while (times) {
			Right_Rotate();
		}
	}
	int pop(int index) {
		assert(index >= 0 && index < size);
		int value = arr[index];
		for (int i = index + 1;i < size;i++)
			arr[i] = arr[i + 1];
		size = size - 1;
		return value;
	}
	int find_transposition(int value) {
		for (int i = 0; i < size; ++i)
			if (arr[i] == value) {
				if (i == 0)
					return 0;
				swap(arr[i], arr[i - 1]);
				return i - 1;
			}
		return -1;
	}
};
int main() {
	Vector v(5);
	for (int i = 0; i < 5; ++i)
		v.set(i, i);
	v.print();
	v.Right_Rotate();
	v.print();
	return 0;
}