#include <iostream>

class Queue
{
private:

    int* arr;  
    int size; //размер
    int length; 
    int tail;   
    int head;       

public:

    Queue(int input_size) 
    {
        head = 0;
        tail = 0;
        length = 0;
 
        size = input_size;
        
        arr = new int[size];
 
        for (int i = 0; i < size; ++i) //изначально заполним нулями
            arr[i] = 0;
    }

    void push(int value) // добавление в очередь
    {
        if (length == 0)
        {
            arr[tail] = value;
            tail++;
            length++;
            return;
        }
        
        if (length == size)
        {
            arr[head] = value;
            tail = head;
            head = (head + 1) % size;
            return;
        }
        
        arr[tail] = value;
		tail = (tail + 1) % size;
        length++;
        
    }

    void pop() // извлекаем элемент из очереди
    {
        if (length == 0)
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
 
        std::cout << arr[head] << std::endl;
 
        if (length == 1)
        {
            arr[head] = 0;
            arr[tail] = 0;
            length--;
            return;
        }
 
        arr[head] = 0;
        length--;
        head = (head + 1) % size;
    }
    
    void displayElements()
    {
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
		std::cout << std::endl;
    }
    
    ~Queue() 
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(3);
    
    q.push(1);
    q.push(2);
	q.push(3);
	q.push(4);
    
    q.displayElements();
	
	q.pop();
	q.pop();
	q.pop();
	q.pop();
    
    return 0;
}