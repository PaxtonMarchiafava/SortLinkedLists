#include <iostream>

using namespace std;

class LinkedList { // create a singly linked list
public:
    int data;
    LinkedList* next;

    LinkedList (int x) {
        data = x;
        next = NULL;
    }
};

/* Add new_data to the front of the linked list */
void push(LinkedList** head_ref, int new_data) {
    LinkedList* new_node = new LinkedList(new_data); // add to heap, not stack. This way our data stays in scope when function returns
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* Print all values from list to terminal */
void printList(LinkedList* node) {
    if (node == NULL) {
        cout << "List is empty" << endl;
    }

    while (node != NULL) {
            cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* Free linked list from memory*/
/* Most of the memory used in this program is created on
the heap, rather than the stack, so we should free it 
when we are done with it. */
void FreeList (LinkedList* node) {
    while (node != NULL) { // iderate through list
        if (node->next != NULL) {
            LinkedList* balls = node;
            node = node->next;
            delete balls;
        } else {
            delete node;
            break;
        }
    }
    
}

/*Bubble sort ascending*/
void bubble(LinkedList* beans) {
    bool sorted = false;
    LinkedList* jelq = beans;
    LinkedList* jelq2 = jelq->next;
    
    while (sorted == false) {
        sorted = true; // re-init flag

        jelq = beans; // reset heads to start
        jelq2 = beans->next;

        while (jelq2 != NULL) {
            if (jelq->data > jelq2->data) { // swap elements
                int temp = jelq->data;
                jelq->data = jelq2->data;
                jelq2->data = temp;
                sorted = false;
            }

            jelq = jelq2; // advance heads
            jelq2 = jelq2->next;
        }
    }
}

/* Pushes an element to the correct location in a sorted linked list */
void PushToSorted (LinkedList** head_ref, int new_data) {

    LinkedList* c = *head_ref;
    LinkedList* d;
    LinkedList* new_node = new LinkedList(new_data); // new node

    if (new_data <= c->data) { // if new data belongs at start
        *head_ref = new_node;
        new_node->next = c;
        return;
    }

    while (c->next->data < new_data) { // move c until in proper location
        c = c->next;
        if (c->next == NULL) { // if item belongs at back end of list, place in different way
            c->next = new_node;
            return;
        }
    }
    
    d = c->next;
    c->next = new_node;
    new_node->next = d;
}

/* Runs insertion sort */
void insertion(LinkedList** nums) {

    LinkedList* c = *nums;
    LinkedList* new_node = NULL;

    push(&new_node, c->data);
    c = c->next;
    push(&new_node, c->data);
    c = c->next;
    bubble(new_node); // just swaps the 2 elements if they are not in order. too lazy to rewrite the code

    while (c != NULL) {
        PushToSorted(&new_node, c->data);
        c = c->next;
    }
    
    (*nums) = new_node;
}

int main() {

    LinkedList* head = NULL;

    push(&head, 0); // add data to list
    push(&head, -40);
    push(&head, 40);
    push(&head, 23);
    push(&head, 67);
    push(&head, 2);
    push(&head, 100);

  
    printList(head);

    insertion(&head); // do the sorting

    printList(head);
    
    FreeList(head);
    return 0;
}
