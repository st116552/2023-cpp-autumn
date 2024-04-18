#include <iostream>

struct Node
{
    int data;
    Node* next;
    //конструкторы(2), деструктор, оператор вывода
    Node(int data, Node* next = 0) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(0) {}
	~Node() { data = 0; next = 0; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList
{
public:
    LinkedList() : head(0) {}
	~LinkedList() { dispose(); }
    int Length();
	bool IsEmpty() { return head == 0; }
    void PushHead(int data);

    //вставляет элемент data на позицию index
    void Insert(int index, int data);
    void PushTail(int data);

    //извлекает головной элемент
    int PopHead();

    //извлекает данные из позиции index
    //и удаляет элемент из списка
    int Extract(int index);
    int PopTail();

    //получает данные из позиции index
    //без удаления из списка
    int Data(int index);
    void swap(int ia, int ib);
    void sort();
    //оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);

private:
    void dispose();

    //извлекает данные из ноды и удаляет саму ноду
    int PopData(Node* node); //!
    void InsertNode(int index, Node* node); //!
    Node* ExtractNode(int index); //!
    bool IndexValid(int index);

	void swapWithHead(int index);

    Node* head;
};

int main(int argc, char* argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.PushHead(1);
    std::cout << list << std::endl;
    list.PushTail(3);
    std::cout << list << std::endl;
    list.Insert(1, 2);
    std::cout << list << std::endl;
    list.Insert(3, 4);
    std::cout << list << std::endl << std::endl;
    std::cout << list << std::endl;
    std::cout << list.PopHead() << " ";
    std::cout << list.Extract(1) << " ";
    std::cout << list.PopTail() << " ";
    std::cout << list.Extract(0) << std::endl;
    std::cout << list << std::endl << std::endl;

    list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
    list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;
    return 0;
}

void LinkedList::PushHead(int data)
{
	head = new Node(data, head);
}

void LinkedList::Insert(int index, int data)
{
	if (index == 0)
	{
		return PushHead(data);
	}
	if (index == Length())
	{
		return PushTail(data);
	}
	if (IndexValid(index))
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(data, tmp->next);
	}
}

void LinkedList::PushTail(int data)
{
	if (IsEmpty())
	{
		return PushHead(data);
	}
	Node* tmp = head;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node(data);
}

int LinkedList::PopHead()
{
	if (head == 0)
	{
		return -1;
	}
	Node* tmp = head;
	head = head->next;
	int res = tmp->data;
	delete tmp;
	return res;
}

int LinkedList::Extract(int index)
{
	if (index == 0)
	{
		return PopHead();
	}
	if (index == Length() - 1)
	{
		return PopTail();
	}
	if (!IndexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	Node* nres = tmp->next;
	tmp->next = tmp->next->next;
	int res = nres->data;
	delete nres;
	return res;
}

int LinkedList::PopTail()
{
	if (IsEmpty())
	{
		return -1;
	}
	if (head->next == 0)
	{
		return PopHead();
	}
	Node* tmp = head;
	while (tmp->next->next != 0)
	{
		tmp = tmp->next;
	}
	int res = tmp->next->data;
	delete tmp->next;
	tmp->next = 0;
	return res;
}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != 0 && tmp->next != head)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

void LinkedList::swap(int a, int b)
{
	if (a == b)
	{
		return;
	}
	if (a > b)
	{
		return swap(b, a);
	}
	if (a == 0)
	{
		return swapWithHead(b);
	}
}

void LinkedList::dispose()
{
	while (!IsEmpty())
	{
		PopHead();
	}
}

bool LinkedList::IndexValid(int index)
{
	return (0 <= index && index < Length());
}

void LinkedList::swapWithHead(int index)
{
	Node* tmpHead = head;
	head = head->next;
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	tmpHead->next = tmp->next;
	tmp->next = tmpHead;
	if (index != 1)
	{
		tmp = head;
		for (int i = 0; i < index - 2; ++i)
		{
			tmp = tmp->next;
		}
		Node* newHead = tmp->next;
		tmp->next = tmp->next->next;
		newHead->next = head;
		head = newHead;
	}
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != 0)
	{
		stream << tmp << " ";
		tmp = tmp->next;
	}
	return stream;
}
