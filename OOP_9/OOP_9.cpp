#include <iostream>

using namespace std;

template<typename T>
struct Node {
	T data;
	Node* next;
	Node* prev;

	Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
	size_t size;

public:
	List() : head(nullptr), tail(nullptr), size(0) {}

	List(std::initializer_list<T> init_list) : head(nullptr), tail(nullptr), size(0) {
		for (const auto val : init_list)
		{
			PushBack(val);
		}
	}

	~List()
	{
		Clear();
	}

	List(const List& other) : head(nullptr), tail(nullptr), size(0) {
		Node<T>* temp = other.head;
		while (temp != nullptr)
		{
			PushBack(temp->data);
			temp = temp->next;
		}
	}

	T& operator[](size_t index) {
		if (index < 0 || index >= size)
		{
			cout << "Out of range" << endl;
			return head->data;
		}

		Node<T>* current = head;
		for (size_t i = 0; i < index; i++) {
			current = current->next;
		}
		return current->data;
	}

	void PushBack(T val) {
		Node<T>* newNode = new Node<T>(val);

		if (IsEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		size++;
	}

	void PushForward(T val) {
		Node<T>* newNode = new Node<T>(val);

		if (IsEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	bool IsEmpty() {
		return head == nullptr;
	}

	void Clear() {
		Node<T>* current = head;

		while (current != nullptr)
		{
			Node<T>* temp = current;
			current = current->next;
			delete temp;
		}

		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	size_t Size() const {
		return size;
	}

	void DeleteByValue(T val) {
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data == val) {
				if (current == head) {
					head = current->next;
					if (head != nullptr)
						head->prev = nullptr;
				}
				else if (current == tail) {
					tail = current->prev;
					tail->next = nullptr;
				}
				else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}
				delete current;
				size--;
				return;
			}
			current = current->next;
		}
	}

	void ShowAll() const {
		Node<T>* current = head;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}

		cout << endl;
	}

	void ShowAllReverse() {
		Node<T>* current = tail;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}

	T Max() const {
		if (size == 0) {
			cout << "Out of range" << endl;
			return -1;
		}

		T maxVal = head->data;
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data > maxVal) {
				maxVal = current->data;
			}
			current = current->next;
		}
		return maxVal;
	}

	T Min() const {
		if (size == 0) {
			cout << "Out of range" << endl;
			return -1;
		}

		T minVal = head->data;
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data < minVal) {
				minVal = current->data;
			}
			current = current->next;
		}
		return minVal;
	}

	void RemoveDuplicates() {
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* runner = current->next;
			while (runner != nullptr) {
				if (current->data == runner->data) {
					runner->prev->next = runner->next;
					if (runner->next != nullptr)
						runner->next->prev = runner->prev;
					Node<T>* temp = runner;
					runner = runner->next;
					delete temp;
					size--;
				}
				else {
					runner = runner->next;
				}
			}
			current = current->next;
		}
	}
};

int main() {
	// Створення списку з використанням конструктора з ініціалізатором
	List<int> list1 = { 1, 2, 3, 2, 4, 5, 6 };

	// Виведення списку та його зворотнього варіанту
	cout << "Original List: ";
	list1.ShowAll();
	cout << "Reversed List: ";
	list1.ShowAllReverse();

	// Додавання нового елемента в кінець списку
	list1.PushBack(7);
	cout << "After pushing back: ";
	list1.ShowAll();

	// Додавання нового елемента на початок списку
	list1.PushForward(0);
	cout << "After pushing forward: ";
	list1.ShowAll();

	// Видалення елемента за значенням
	list1.DeleteByValue(2);
	cout << "After deleting value 2: ";
	list1.ShowAll();

	// Видалення дублікатів
	list1.RemoveDuplicates();
	cout << "After removing duplicates: ";
	list1.ShowAll();

	// Пошук максимального та мінімального значень у списку
	cout << "Max: " << list1.Max() << endl;
	cout << "Min: " << list1.Min() << endl;

	return 0;
}
