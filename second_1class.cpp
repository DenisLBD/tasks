#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class Queue
{
private:

    Node* head;
    Node* tail;
    int k;
    int size; //размер очереди
    
public:
    
    Queue (int input_size)
    {
        head = nullptr;
        tail = nullptr;
        size = input_size;
        k = 0; //счетчик звеньев
    }
    
    void push (int input_data) //добавить элемент
    {
        
        if (k == size)
        {
            head->data = input_data;
			tail = head;
			head = head->next;
            tail->next = head;
            return;
        }
        
        Node* newNode = new Node; // создаем звено
        
        newNode->data = input_data;
        
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        } else
        {
			Node* tmp = head;
			while(tmp != tail)
				tmp = tmp->next;
			tmp->next = newNode;
			tail = newNode;
			if (k == size - 1)
				tail->next = head;
        }
        k++;
    }
    
    void pop () //взять элемент
    {
        if (head == nullptr)
        {
           std::cout << "No elements" << std::endl;
           return;
        }
        
        std::cout << head->data << std::endl;
        
        if (head == tail) 
        {
            head = nullptr;
            tail = nullptr;
            k--;
            return;
        }
        
        Node* tmp = head;
		tmp = tmp->next;
		delete head;
		head = tmp;

        k--;
    }
    
    void readElement() //прочитать элемент без извлечения
    {
        if (head == nullptr)
        {
           std::cout << "No elements" << std::endl;
           return;
        }
        
        std::cout << head->data << std::endl;
    }
};

int main()
{
    Queue q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.pop();
	q.pop();
	q.pop();
	q.pop();

    return 0;
}
