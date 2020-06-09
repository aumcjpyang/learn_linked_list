#include <iostream>

using namespace std;

class Node
{
public :
	int element;
	Node* next_node;
};

class List
{
public:
	List()
	{
		first_node = NULL;
		size = 0;
	}
	~List()
	{
		Node* dn = first_node;
		Node* ndn = first_node->next_node;
		while (ndn != nullptr)
		{
			cout << "now deleting " << dn << "," << dn->element << endl << "next node at " << dn->next_node << endl;
			delete dn;
			dn = ndn;
			ndn = dn->next_node;
		}
		cout << "now deleting " << dn << "," << dn->element << endl;
		delete dn;
	}
	Node* get_first()
	{
		return first_node;
	}
	bool isempty() const
	{
		return (size == 0);
	}
	void push_front(int _element)
	{
		Node* new_p = new Node;			//建立一個新節點
		new_p->element = _element;		//把新內容丟到新節點
		new_p->next_node = first_node;	//把新節點的'下一個節點'設為原本的第一個節點
		first_node = new_p;				//將指向第一節點的指標指向新節點
		size++;
	}
	void insert_at(int index, int _element)
	{
		if (index == 0)
			push_front(_element);
		else
		{
			Node* front_node = first_node;
			for (int i = 1; i < index; i++)
				front_node = front_node->next_node;
			push(front_node, _element);
		}
	}
	void printOut() const
	{
		Node* p = first_node;
		while (p != NULL)
		{
			cout << p->element << " -> ";
			p = p->next_node;
		}
		cout << "End List" << endl << "size = " << size << endl;
	}
	int get_size()
	{
		return size;
	}
protected:
	Node* first_node;
	int size;
	void push(Node* front_node,int _element)
	{
		Node* new_p = new Node;
		new_p->element = _element;
		new_p->next_node = front_node->next_node;
		front_node->next_node = new_p;
		size++;
	}
};

int main()
{
	List myList;
	myList.push_front(23);
	myList.push_front(24);
	myList.push_front(25);
	myList.push_front(27);
	myList.push_front(2);
	myList.push_front(32);
	myList.printOut();
	myList.insert_at(4, 89);
	myList.printOut();

	return 0;
}