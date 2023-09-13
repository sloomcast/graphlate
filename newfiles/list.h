#ifndef LIST_H
#define LIST_H
//A singly-linked list implementation, double-ended

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL

using namespace std;

template <typename T>
class List{
    public:
    //default constructor
    List(){
        num_elements = 0;
        first = nullptr;
        last = nullptr;
    }

    //copy constructor

    //size function
    int size(){
        return num_elements;
    }

    //is empty?

    //push to front

    //pop element

    //return value at start by ref

    //return value at end by ref

    //clear list

    

    private:
    //private node type 
    struct Node{
        Node *next;
        T datum;
    };

    //start and end
    Node *first;
    Node *last;
    //size
    int num_elements;

    //copy all values


    public:
    //iterator class
    class Iterator{
        public:
        Iterator(){
            node_ptr = nullptr;
        }


        private:
        Node *node_ptr;

        //friend class
        friend class List;

        //constructor for pointer p
        Iterator(Node *p){
            node_ptr = p;
        }
    };
};

#endif
