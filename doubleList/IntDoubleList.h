#pragma once
class IntDoubleList
{
private:
	struct Node
	{
		int item_;
		Node* next_;
		Node* prev_;
		Node(int item, Node *next = 0, Node *prev = 0):
			item_(item), next_(next), prev_(prev) {}
	};
	int count_;
	Node* head_;
	Node* tail_;
	Node* head() const { return head_; }
	Node* tail() const { return tail_; }
	void insertTail(Node* x);
	void insertHead(Node* x);
	void insertAfter(Node* x, Node* newx);
	void insertBefore(Node* x, Node* newx);
	void deleteNode(Node* x);
	Node* searchNodeFromHead(int item) const;
	Node* searchNodeFromTail(int item) const;
	Node* replaceNode(Node* x, int item);
public:
	IntDoubleList();
	IntDoubleList(const IntDoubleList& list);
	int ñount() const{ return count_; }
	int headItem() const;
	int& headItem();
	int tailItem() const;
	int& tailItem();
	void insertHead(int item);
	void insertTail(int item);
	void insertHead(const IntDoubleList& list);
	void insertTail(const IntDoubleList& list);
	bool insertAfterFromHead(int itemOld, int itemNew);
	bool insertBeforeFromHead(int itemOld, int itemNew);
	bool insertAfterFromTail(int itemOld, int itemNew);
	bool insertBeforeFromTail(int itemOld, int itemNew);
	bool insertAfterAll(int itemOld, int itemNew);
	bool insertBeforeAll(int itemOld, int itemNew);
	bool deleteHead();
	bool deleteTail();
	bool deleteItemFromHead(const int item);
	bool deleteItemFromTail(const int item);
	bool deleteItemAll(const int item);
	bool searchItem(int item) const;
	bool replaceItemFromHead(int itemOld, int itemNew);
	bool replaceItemFromTail(int itemOld, int itemNew);
	bool replaceItemAll(int itemOld, int itemNew);
	bool out(int index);
	void outAll() const;
	virtual ~IntDoubleList(void);
};
