#ifndef ECE275LIB_CONTAINERS_LIST_H
#define ECE275LIB_CONTAINERS_LIST_H
#include <cstdlib>
#include <iostream>
namespace ECE275Lib::containers {
    template <typename T>
    class Node {
    public:
        Node() {
            next = nullptr;
        }
        
        T data;
        Node<T>* next;
    };

    template <typename T>
    class List {
        public:
            List() {
                head = nullptr;
            }

            List(unsigned int number) {
                head = nullptr;
                for (int i = 0; i < number; i++) {
                    this->push_back(i);
                }
                
            }
            //data modulator functions
            //adds an element to the end of the list
            void push_back(T in) {
                Node<T>* newNode = new Node<T>();
                newNode->data = in;

                //set the new node as the head of the list if there is no node set.
                if (head == nullptr) {
                    head = newNode;
                }
                //traverse the list until the end and add the node there.
                else {
                    temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }

            //removes the i'th node in a list.
            void remove(unsigned int place) {remove(place, place);}
            //removes an element from the list in the range sent in from the user.
            void remove(unsigned int start, unsigned int end) {
                temp = head;
                Node<T>* temp1, * temp2; //*temp3;

                //get to the starting node
                if (start == 0){
                    temp1 = head;
                }
                else {
                    for (unsigned int i = 0; i < start - 1; i++) {
                        temp = temp->next;
                    }
                }
                temp1 = temp;
                //DEBUG STATEMENT: std::cout << "Element of node before start: " << temp1->data << std::endl;
                
                //to get the ending node.
                for (unsigned int i = 0; i < (end - start); i++) {
                    temp = temp->next;
                }
                temp2 = temp->next;
                //DEBUG STATEMENTstd::cout << "Element of end: " << temp2->data << std::endl;

                //set the next tail of our temp as the node next in the list that will not get deleted.
                temp1->next = temp2->next;
                                
                //deleting the nodes in the list
                //FIX ME: THERE IS A MEMORY LEAK HERE.
            }

            //inserts a list into the list at the index sent in.
            void insert(unsigned int place, List<T>& other) {
                Node<T>* otherHead = other.front();
                Node<T>* otherEnd = other.back();


                if (place == 0) {
                    otherEnd->next = head;
                    head = otherHead;
                }
                if (place == this->size()) {
                    temp = this->back();
                    temp->next = otherHead;
                    otherEnd->next = nullptr;
                }
                else {
                    temp = head;
                    for (int i = 0; i < place - 1; i++) {
                        temp = temp->next;
                    }

                    //sets a pointer of the final element of the second list to the next pointer in the original list.
                    otherEnd->next = temp->next;

                    //sets the first element of the new list as the next element of the original list.
                    temp->next = otherHead;
                }
            }
            
            //inserts an element into  the list at the index sent in.
            void insert(unsigned int place, T d) {
                //initializing the new node.
                Node<T>* newNode = new Node<T>();
                newNode->data = d;

                temp = head;
                if (place == 0) {
                    newNode->next = head;
                    head = newNode;
                }
                else {
                    for (int i = 0; i < place - 1; i++) {
                        temp = temp->next;
                    }
                }

                if (temp->next == nullptr) {
                    //newNode->next = temp;
                    temp->next = newNode;
                    newNode->next = nullptr;
                }
                else {
                    //setting the pointer to the next node in the new node.
                    newNode->next = temp->next;

                    //setting the pointer to the new node from the original list.
                    temp->next = newNode;
                }
            }
            
            //assigns the i'th node with the data type t.
            void assign(unsigned int place, T d) {

                temp = head;
                for (int i = 0; i < place; i++) {
                    temp = temp->next;
                }

                temp->data = d;
            }

            //getter functions
            //getter functions
            //getter functions

            //Returns the first element of the list.
            Node<T>* front() {

                return head;
            }
            
            //provides access to the last node in the 
            Node<T>* back() {
                temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                return temp;
            }

            //returns the size of the list
            unsigned int size() {
                int i = 1;
                temp = head;
                //traverse the list until the end and increment a counter
                while (temp->next != nullptr) {
                    temp = temp->next;
                    i++;
                }
                return i;
            }
            
            //provides access to the i'th node in the list.
            T at(unsigned int place) {
                temp = head;
                unsigned int i = 0;
                while (i < place) {
                    temp = temp->next;
                    i++;
                }
                return temp->data;
            }
        private:
            Node<T>* head;
            Node<T>* temp;
    };
}
#endif
