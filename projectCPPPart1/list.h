ifndef __LIST_H
#define __LIST_H


template <class T>
class Node
{
    T* theData;
    Node* next;

    public:
        Node(T* theData, T* next = nullptr)
        ~Node();
        T* getData() { return theData; }
        Node* getNext() { return next; }
        void setNext(Node* next) { this->next = next; }
}

template <class T>
class List
{
    public:
        void add(Node<T> info);

    private:
        Node<T>* head, *tail;
}

template <class T>
void List<T>::add(Node<T> info)
{
  if(head == NULL) //if our list is currently empty
  {
    head = new Node<T>();
    head->setData(info);
    tail = head;
  }
  else //if not empty add to the end and move the tail
  {
    Node* temp = new node_type;
    temp->setData(info);
    temp->setNextNull();
    tail->setNext(temp);
    tail = tail->getNext();
  }
}

#endif // __LIST_H