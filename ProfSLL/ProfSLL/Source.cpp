//----------------
//----------
//-------note that I provided you with many versions of copy construcotr for this class---
// Singly Linked List Implementation by Dr. Saleh M. Alnaeli
#include <iostream>
using namespace std;
//------------

template <class E> class SLinkedList; // CPS265 Students: Attention: this is to declare the SLinkedList so that compiler has no problem using it in Node class as a friend
									  // it is like a prototype 

template <class E>
class SNode {					// singly linked list node
								// provide SLinkedList access
public:
	const E& getElem() const { return elem; };
	SNode<E>* getNext() const { return next; };
private:
	E elem;					// linked list element value
	SNode<E>* next;				// next item in the list
	friend class SLinkedList<E>;
};

template <class E>
class SLinkedList {				// a singly linked list
public:
	SLinkedList();				// empty list constructor
	SLinkedList(SLinkedList<E>&); // copy costructor
	~SLinkedList();				// destructor
	SLinkedList<E>& SLinkedList<E>::operator=(SLinkedList<E>&); // assignment operator
	bool empty() const;				// is list empty?
	const E& front() const;			// return front element
	void addFront(const E& e);			// add to front of list
	void SLinkedList<E>::addBack(const E& e);
	void removeFront();				// remove front item list
	SNode<E>*  getHead() const { return head; };			// return head address
	SNode<E>*  getTail() const { return tail; };
private:
	SNode<E>* head;				// head of the list
	SNode<E>* tail;				// tail of the list
};

template <class E>
SLinkedList<E>::SLinkedList()				// constructor
	: head(NULL), tail(NULL) { }

template <class E>
bool SLinkedList<E>::empty()const			// is list empty?
{
	return head == NULL;
}

template <class E>
const E& SLinkedList<E>::front() const		// return front element
{
	return head->elem;
}

template <class E>
SLinkedList<E>::~SLinkedList()			// destructor
{
	while (!empty()) removeFront();
}
template <class E>
void SLinkedList<E>::addFront(const E& e) {		// add to front of list

	SNode<E>* v = new SNode<E>;				// create new node
	v->elem = e;					// store data
	v->next = head;					// head now follows v
	head = v;
	if (tail == NULL)
		tail = v;// v is now the head
}

template <class E>
void SLinkedList<E>::addBack(const E& e) {		// add to back of list
	SNode<E> * newNode = new SNode<E>;
	newNode->elem = e;
	newNode->next = NULL;
	if (tail == NULL)
	{
		newNode->next = tail;
		tail = newNode;
		head = newNode;
		//return;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
		//tail->next = NULL;
	}
}

template <class E>
void SLinkedList<E>::removeFront() {			// remove front item
	SNode<E>* old = head;				// save current head
	head = old->next;					// skip over old head
	delete old;						// delete the old head
}

// copy constructor 1
//template <class E>
//SLinkedList<E>::SLinkedList(const SLinkedList<E>& obj) : head(NULL), tail(NULL)
//
//{
//	if (obj.head == NULL){
//		head = tail = NULL;
//	}
//	else {
//		SNode<E>* temp = new SNode<E>;
//		head = temp;
//		head->elem = obj.head->elem;
//		tail = head;
//		tail->next = NULL;
//
//		for (SNode<E>* curr = obj.head->getNext();
//			curr != NULL; curr = curr->getNext())
//		{
//			temp = new SNode<E>;
//			tail->next = temp;
//			tail = tail->getNext();
//			tail->elem = curr->getElem();
//			tail->next = NULL;
//		}//end for
//	}//end if
//} // end copy constructor
//---------------
//copy constructor 2
//template <class E>
//SLinkedList<E>::SLinkedList(const SLinkedList<E>& obj) : head(NULL), tail(NULL)
//
//{
//	if (obj.head == NULL){
//		head = tail = NULL;
//	}
//	else {
//		//SNode<E>* temp = new SNode<E>;
//		//head = temp;
//		//head->elem = obj.head->elem;
//		//tail = head;
//		//tail->next = NULL;
//
//		for (SNode<E>* curr = obj.head;
//			curr != NULL; curr = curr->getNext())
//		{			
//			addBack( curr->getElem());
//			
//		}//end for
//	}//end if
//} // end copy constructor 2
//copy constructor 3:
//template <class E>
//SLinkedList<E>::SLinkedList( SLinkedList<E>& obj) : head(NULL), tail(NULL)
//
//{
//	
//	if (obj.head == NULL){
//		head = tail = NULL;
//	}
//	else {
//
//
//		for (SNode<E>* curr = obj.head;
//			curr != NULL; curr = curr->getNext())
//		{
//			addBack(curr->getElem());
//
//		}//end for
//	}//end if
//} // end copy constructor3
//----------------------
//copy constructor 4
// here I had to change the parameter from const to non-const because we can not assign a const list to non-const list
template <class E>
SLinkedList<E>::SLinkedList(SLinkedList<E>& obj) : head(NULL), tail(NULL)
{
	*this = obj;
}// end of copy structor 4
 //overloading assignment operator
template <class E>
SLinkedList<E>& SLinkedList<E>::operator=(SLinkedList<E> &rhs) // assignment operator
{
	if (this != &rhs) {
		while (head != NULL) // first, empty list
			removeFront();
		//SNode* current = rhs.first; // set ptr to first link

		for (SNode<E>* curr = rhs.head;
			curr != NULL; curr = curr->getNext())
		{
			addBack(curr->getElem());

		}//end for
	}
	return *this;
}

int main() {

	SLinkedList<int> myIntList;
	for (int i = 0; i < 10; i++) {
		myIntList.addFront(i);
	}
	SLinkedList<int> intList2;
	for (int i = 10; i < 25; i++) {
		intList2.addFront(i);
	}
	myIntList = intList2;
	//intList2 output
	cout << "intList2: ";
	for (SNode<int>* cursor = intList2.getHead(); cursor != NULL; cursor = cursor->getNext())
	{
		cout << "[" << cursor->getElem() << "]";
	}
	cout << endl;
	// myIntList output
	cout << "myIntList: ";
	for (SNode<int>* cursor = myIntList.getHead(); cursor != NULL; cursor = cursor->getNext())
	{
		cout << "[" << cursor->getElem() << "]";
	}
	cout << "\ndone" << endl;
	return 0;
}