#include <iostream>
#include "singly_ll.h"


int main() {

    //Creation of nodes KHEM

    //Creating a node stored in the stack
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    //Allocate memory in the head
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;

    //Storing a value inside the node
    head->data = 'K';
    second->data = 'H';
    third->data = 'E';
    fourth->data = 'M';


    //Linking the nodes:
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout << "Testing of Traversal: \n";
    ListTraversal(head);


    std::cout << "Testing of sllinsertHead: \n";
    sllinsertHead('M', &head);
    ListTraversal(head);

    std::cout << "Testing of sllGeneralInsert: \n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);


    std::cout << "Testing of sllinsertEnd: \n";
    sllinsertEnd('U', &head);
    ListTraversal(head);

    std::cout << "Testing of deleting the node: \n";
    slldeleteNode('U', &head);
    ListTraversal(head);
    slldeleteNode('M', &head);
    ListTraversal(head);
    slldeleteNode('X', &head);
    ListTraversal(head);

    std::cout << "Testing of deleting all nodes: \n";
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}