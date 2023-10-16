/*
Given two sorted linked lists, merge them so that the resulting linked list is also sorted. 


Maintain both a head and a tail pointer for the merged linked list. 
Start by comparing the first nodes of the two linked lists and select the smaller one as the head of the merged list. 
For subsequent nodes in both lists, pick the smaller current node and link it to the tail of the merged list. 
Move the current pointer of that list one step forward.

Continue this process as long as there are remaining elements in both lists.
 If there are elements left in only one of the lists, link the remaining list to the tail of the merged list. 
 Initially, the merged linked list is set to NULL.

To initiate the process, compare the values of the first two nodes and designate the node with the smaller value as the head of the merged linked list. 
In the ongoing example, this could be the node with the value 4 from head1. 
As it is the first and only node in the merged list, it also becomes the tail. Then, move head1 one step forward
*/

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* mergeLists(Node* head1, Node* head2) {
    Node* mergedHead = nullptr;
    Node* mergedTail = nullptr;

    while (head1 || head2) {
        Node* smallerNode = (head2 == nullptr || (head1 != nullptr && head1->data < head2->data)) ? head1 : head2;

        if (!mergedHead) {
            mergedHead = smallerNode;
            mergedTail = smallerNode;
        } else {
            mergedTail->next = smallerNode;
            mergedTail = smallerNode;
        }

        if (smallerNode == head1) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }

    return mergedHead;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head1 = new Node(2);
    head1->next = new Node(5);
    head1->next->next = new Node(7);

    Node* head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    Node* mergedList = mergeLists(head1, head2);
    std::cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}


/*
output

Merged Linked List: 2 3 4 5 6 7 

*/