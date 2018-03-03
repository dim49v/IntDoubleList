#include "IntDoubleList.h"
#include "Header.h"
using namespace std;
IntDoubleList::IntDoubleList() : count_(0), head_(0), tail_(0){}
IntDoubleList::IntDoubleList(const IntDoubleList& list){
	Node* t = list.head_;
	for (int i = 0; i < list.count_; i++){
		this->insertTail(new Node(t->item_));
		t = t->next_;
	}
}
IntDoubleList::~IntDoubleList()
{
	Node* temp;
	while (head_ != 0){
		temp = head_->next_;
		delete head_;
		head_ = temp;
	}
}

void IntDoubleList::insertHead(Node* x)
{
	x->next_ = head_;
	if (head_ != 0)
		head_->prev_ = x;
	else
		tail_ = x;
	head_ = x;
	count_++;
}
void IntDoubleList::insertTail(Node* x){
	x->prev_ = tail_;
	if (tail_ != 0)
		tail_->next_ = x;
	else
		head_ = x;
	tail_ = x;
	count_++;
}
void IntDoubleList::insertAfter(Node* x, Node* newx){
	newx->next_ = x->next_;
	newx->prev_ = x;
	x->next_ = newx;
	if (newx->next_ == 0){
		this->tail_ = newx;
	}
}
void IntDoubleList::insertBefore(Node* x, Node* newx){
	newx->prev_ = x->prev_;
	newx->next_ = x;
	x->prev_ = newx;
	if (newx->prev_ == 0){
		this->head_ = newx;
	}
}
void IntDoubleList::deleteNode(Node* x){
	if (x->prev_ != 0)
		x->prev_->next_ = x->next_;
	else
		head_ = x->next_;
	if (x->next_ != 0)
		x->next_->prev_ = x->prev_;
}
IntDoubleList::Node* IntDoubleList::searchNodeFromHead(int item) const{
	Node* x = head_;
	while ((x != 0) && (x->item_ != item)){
		x = x->next_;
	}
	return x;
}
IntDoubleList::Node* IntDoubleList::searchNodeFromTail(int item) const{
	Node* x = tail_;
	while ((x != 0) && (x->item_ != item)){
		x = x->prev_;
	}
	return x;
}
IntDoubleList::Node* IntDoubleList::replaceNode(Node* x, int item){
	x->item_ = item;
	return x;
}

int IntDoubleList::headItem() const{
	return head_->item_;
}
int& IntDoubleList::headItem(){
	return head_->item_;
}
int IntDoubleList::tailItem() const{
	return tail_->item_;
}
int& IntDoubleList::tailItem(){
	return tail_->item_;
}

void IntDoubleList::insertHead(int item){
	insertHead(new Node(item));
}
void IntDoubleList::insertTail(int item){
	insertTail(new Node(item));
}
void IntDoubleList::insertHead(const IntDoubleList& list){
	Node* temp = list.tail_;
	for (int i = 0; i < list.count_; i++){
		insertHead(new Node(temp->item_));
		temp = temp->prev_;
	}
}
void IntDoubleList::insertTail(const IntDoubleList& list){
	Node* temp = list.head_;
	for (int i = 0; i < list.count_; i++){
		insertTail(new Node(temp->item_));
		temp = temp->next_;
	}
}
bool IntDoubleList::insertAfterFromHead(int itemOld, int itemNew){
	Node* x = searchNodeFromHead(itemOld);
	if (x != 0){
		insertAfter(x, new Node(itemNew));
		return 1;
	}
	return 0;
}
bool IntDoubleList::insertBeforeFromHead(int itemOld, int itemNew){
	Node* x = searchNodeFromHead(itemOld);
	if (x != 0){
		insertBefore(x, new Node(itemNew));
		return 1;
	}
	return 0;
}
bool IntDoubleList::insertAfterFromTail(int itemOld, int itemNew){
	Node* x = searchNodeFromTail(itemOld);
	if (x != 0){
		insertAfter(x, new Node(itemNew));
		return 1;
	}
	return 0;
}
bool IntDoubleList::insertBeforeFromTail(int itemOld, int itemNew){
	Node* x = searchNodeFromTail(itemOld);
	if (x != 0){
		insertBefore(x, new Node(itemNew));
		return 1;
	}
	return 0;
}
bool IntDoubleList::insertAfterAll(int itemOld, int itemNew){
	bool flag = false;
	Node* x = tail_;
	while (x != 0){
		x = searchNodeFromTail(itemOld);
		if (x != 0){
			insertAfter(x, new Node(itemNew));
			flag = true;
		}
	}
	return flag;
}
bool IntDoubleList::insertBeforeAll(int itemOld, int itemNew){
	bool flag = false;
	Node* x = head_;
	while (x != 0){
		x = searchNodeFromHead(itemOld);
		if (x != 0){
			insertBefore(x, new Node(itemNew));
			flag = true;
		}
	}
	return flag;
}
bool IntDoubleList::deleteHead(){
	if (head_ != 0){
		deleteNode(head_);
		return 1;
	}
	return 0;
}
bool IntDoubleList::deleteTail(){
	if (tail_ != 0){
		deleteNode(tail_);
		return 1;
	}
	return 0;
}
bool IntDoubleList::deleteItemFromHead(const int item){
	Node* x = searchNodeFromHead(item);
	if (x != 0){
		deleteNode(x);
		return 1;
	}
	return 0;
}
bool IntDoubleList::deleteItemFromTail(const int item){
	Node* x = searchNodeFromTail(item);
	if (x != 0){
		deleteNode(x);
		return 1;
	}
	return 0;
}
bool IntDoubleList::deleteItemAll(const int item){
	bool flag = false;
	Node* x = head_;
	while (x != 0){
		x = searchNodeFromHead(item);
		if (x != 0){
			deleteNode(x);
			flag = true;
		}
	}
	return flag;
}
bool IntDoubleList::searchItem(int item) const{
	Node* x = searchNodeFromHead(item);
	return (x != 0);
}
bool IntDoubleList::replaceItemFromHead(int itemOld, int itemNew){
	Node* x = searchNodeFromHead(itemOld);
	if (x != 0){
		replaceNode(x, itemNew);
		return 1;
	}
	return 0;
}
bool IntDoubleList::replaceItemFromTail(int itemOld, int itemNew){
	Node* x = searchNodeFromTail(itemOld);
	if (x != 0){
		replaceNode(x, itemNew);
		return 1;
	}
	return 0;
}
bool IntDoubleList::replaceItemAll(int itemOld, int itemNew){
	bool flag = false;
	Node* x = head_;
	while (x != 0){
		x = searchNodeFromHead(itemOld);
		if (x != 0){
			replaceNode(x, itemNew);
			flag = true;
		}
	}
	return flag;
}
bool IntDoubleList::out(int index){
	Node* x = head_;
	for (int i = 0; i < index && x != 0; i++)x = x->next_;
	if (x != 0)cout << x->item_;
	return (x != 0);
}
void IntDoubleList::outAll() const{
	Node* x = head_;
	while (x != 0){
		cout << x->item_ << " ";
		x = x->next_;
	}
	cout << endl;
}