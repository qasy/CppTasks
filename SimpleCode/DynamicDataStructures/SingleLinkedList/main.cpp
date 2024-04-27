// * Односвязный или однонаправленный список *
// При сравнении с динамическим массивом:
// + Быстрое добавление и удаление элементов (изменение количества элементов).
// - Медленный доступ к данным.
// На основе уроков с канала SimpleCode
// 1) https://www.youtube.com/watch?v=C9FK1pHLnhI&list=PLQOaTSbfxUtAIipl4136nwb4ISyFk8oI4&index=1
//
//
//
//

#include <iostream>

template <typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T value);
    size_t getSize() const
    {
        return this->size;
    }

    T& operator[](size_t const index)
    {
        Node* current  = this->head;
        size_t counter = 0;

        while (current)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->pNext;
            ++counter;
        }
        // @TODO wa also need to declare some return at this moment
        // return current->data;
    }

private:
    class Node
    {
    public:
        Node* pNext;
        T data;

        // Необходимо как-то инициализировать нулем пришедший объект, поэтому вызываем конструктор по умолчанию
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data  = data;
            this->pNext = pNext;
        }
    };

    size_t size;
    Node* head;
};

template <typename T>
List<T>::List()
{
    this->size = 0;
    this->head = nullptr;
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
void List<T>::push_back(T value)
{
    if (head == nullptr)
    {
        head = new Node(value);
    }
    else
    {
        Node* current = this->head;
        while (current->pNext)
        {
            current = current->pNext;
        }
        current->pNext = new Node(value);
    }
    ++size;
}

int main()
{
    List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    std::cout << lst[4] << std::endl;
    return 0;
}