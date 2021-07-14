//
// Created by ARI on 14-Jul-21.
//
#ifndef PROJECTCPPPART1_MY_TEMPLATE_H
#define PROJECTCPPPART1_MY_TEMPLATE_H
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
template <class T> class Node
{
public:
    T data; //the object information
    Node* next; //pointer to the next node element


    void setData(T data){
        this->data = data;
    }

    void setNextNull(){
        next = NULL;
    }

    void setNext(Node* next){
        this->next = next;
    }

    Node* getNext(){
        return next;
    }
};

template <class T> class CustomLinkedList
{
public:
    Node<T> *head, *tail;
    CustomLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    ~CustomLinkedList()
    {
        cout << "In ~customLinkedList" << endl;
    }

    //Method adds info to the end of the list
    void add(T info)
    {
        if(head == NULL) //if our list is currently empty
        {
            head = new Node<T>; //Create new node of type T
            head->setData(info);
            tail = head;
        }
        else //if not empty add to the end and move the tail
        {
            Node<T>* temp = new Node<T>;
            temp->setData(info);
            temp->setNextNull();
            tail->setNext(temp);
            tail = tail->getNext();
        }
    }
    void printList(Node<T>* n)
    {
        while (n != NULL) {
            cout << n->data << " ";
            n = n->next;
        }
    }
};
#endif //PROJECTCPPPART1_MY_TEMPLATE_H
