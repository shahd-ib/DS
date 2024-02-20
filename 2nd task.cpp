#include <iostream>
using namespace std;



struct Node {
	int data{};
	Node* next{};
	Node(int data) : data(data) {}
};

class LinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int lenght = 0;
public:
	Node* constructLL(vector<int>& arr) {
		Node* head = arr[0];
		Node* tail = arr[size-1];
		
		// Write your code here
	}
	void print() {
		for (Node* temp = head;temp;temp = temp->next) {
			cout << temp->data << " ";
		}
		cout << "\n";
	}
	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
	void insert_end(int value) {
		Node* item = new Node(value);
		tail = head;
		if (head==NULL)
			head = tail = item;
		else {
			while (tail->next != nullptr) {
				tail = tail->next;
			}
			tail->next = item;
			tail = item;
			item->next = NULL;
		}
		lenght++;
	}
	void insert_front(int value) {
		Node* new_node = new Node(value);
		if (head == NULL) {
			head = new_node;
			new_node->next = NULL;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
		lenght++;
	}
	void delete_front() {
		if (head == NULL) {
			cout << "Linked_list is empty";
		}
		else {
			Node* temp = head;
			head = temp->next;
			delete(temp);
		}
		lenght--;
	}
	Node* get_nth(int n) {
		int pos = 0;
		if (n < lenght) {
			for (Node* temp = head;temp;temp = temp->next) {
				if (pos == n) {
					cout << temp->data;
					return temp;
				}
				pos++;
			}
		}
	}
	
	void delete_node_with_key(int value)
	{
		Node* current = head;
		Node* previous = head;
		//the key value is the first node
		if (current->data == value) {
			head = current->next;
			free(current);//delete the node from the memory
			return;// like break(åíÞÝ ÚäÏ åäÇ ãÔ åíßãá)
		}
		while (current->data != value) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
	void swap_pairs() {
		for (Node* current = head; current && current->next;current = current->next->next) {
			swap(current->data, current->next->data);
		}
	}

	void reverse() {

	}
	void deletenode(int value) {
		Node* current, * previous;
		//if the node i wana delete is the first node
		current = head;
		previous = head;
		if (current->data == value) {
			head = current->next;
			free(current);//delete the node from the memory
			return;// like break(åíÞÝ ÚäÏ åäÇ ãÔ åíßãá)
		}
		while (current->data != value) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
	void delete_even_positions() {
		int pos = 1;		
		for (Node* current = head, *previous = head;current;previous = current,current = current->next) {
			if(pos%2==0)
				previous->next = current->next;
			pos++;
		}		
	}
	void insert_sorted(int value){}
	bool is_same(const LinkedList& other){}
};
class Linked_list_without_head {
private:
	Node* head{};
public:
	void print(){
		for (Node* temp = head;temp;temp = temp->next) {
			cout << temp->data << " ";
		}
		cout << "\n";
	}
	void add_element(int value) {
		Node* new_node = new Node(value);
		if (head == nullptr) {
			head = new_node;
			new_node->next = NULL;
		}
		else {
			Node* temp_head = head;
			while (temp_head->next != nullptr) {
				temp_head = temp_head->next;
			}
			temp_head->next = new_node;
		}
	}
	Node*get_tail(){
		Node* temp_head = head;
		int tail = 0;
		while (temp_head->next != NULL) {
			temp_head = temp_head->next;
		}
		cout << temp_head->data;
		return temp_head;
	}
};


int main()
{
	LinkedList list;
	list.insert_front(5);
	list.insert_front(4);
	list.insert_front(3);
	list.insert_front(2);
	list.insert_front(1);
	//list.reverse();
	list.swap_pairs();
	list.print();
	return 0;
}
