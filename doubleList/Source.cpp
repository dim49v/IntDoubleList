#include "IntDoubleList.h"
#include "Header.h"
using namespace std;

int main(){
	//IntDoubleList list;
	//int size = 10;
	//for (int i = 0; i < size; i++){
	//	list.insertHead(i);
	//	//list.insertHead(size - i);
	//}
	//IntDoubleList list2(list);
	//list2.outAll();
	//list2.insertHead(list);
	//list2.deleteItemFromHead(3);
	//list2.outAll();
	//list.headItem = 4;
	//list.outAll();
	//list.deleteHead();
	//list.outAll();
	//list.deleteTail();
	//list.outAll();
	//list.replaceItemAll(2,9);
	//list.outAll();
	//list.replaceItemFromHead(2, 9);
	//list.outAll();

	IntDoubleList list;           // Создание пустого списка
	list.insertHead(2);          // Добавление элементов
	list.insertHead(3);
	list.insertHead(1);
	list.outAll();                    // Печать элементов

	if (list.searchItem(1))
		cout << "1 find" << endl;
	else
		cout << "1 not find" << endl;
	if (list.searchItem(8))
		cout << "8 find" << endl;
	else
		cout << "8 not find" << endl;
	IntDoubleList  list1(list);  // Копирование списка
	list1.insertHead(4);                // Добавление элемента
	list1.insertHead(5);                // Добавление элемента
	list1.deleteHead();                 // Удаление головного
	list1.outAll();
	list1.insertHead(6);
	//list1.deleteHead();
	list1.outAll();

	system("pause");
}