/**
 * CSO1 HW8 Circularly Linked List Implementation
 *
 * Your Computing ID: wsm7rw
 */

//TODO: Remember to add include statement here. 
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

cll_node *cll_head(cll_node *list){
    cll_node *ptr = list;
    if (ptr) {
        do {
            if (ptr->is_head) 
                return ptr; // return node if it is the head node
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    return NULL; // empty list OR list set up wrong
}

cll_node *cll_tail(cll_node *list) {
    cll_node *ptr = list;
    if (ptr) {
        do {
            if (ptr->is_head) 
                return ptr->prev; // return previous node (tail) if we are at the head node
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    return NULL; // empty list OR list set up wrong
}


unsigned long cll_length(cll_node *list) {
    cll_node *ptr = list;
    int count = 0;
    if (ptr) {
        do {
            count+=1; 
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    return count;
}

cll_node *cll_find(cll_node *list, int value) {
    cll_node *ptr = list;
    if (ptr) {
        do {
            if (ptr->value == value) // check if we have found our value
                return ptr;
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    if(ptr->value == value) // check final value
        return ptr;
    return NULL; // empty list or value not in list
}


cll_node *cll_remove(cll_node *list) {
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement.
    if (list->next == list) {
        free(list);
        return NULL;
    }
    else if (list->is_head == 1) {
        list->next->is_head = 1;
        list->next->prev = list->prev;
        list->prev->next = list->next;
        cll_node *ptr = list->next;
        free(list);
        return ptr;
    }

    else if (list) {
        cll_node *ptr = list->next;
        list->prev->next = list->next;
        list->next->prev = list->prev;
        free(list);
        return ptr;
    }
    else {
        return NULL;
    }
    
}


cll_node *cll_insert(int value, cll_node *list, int before) {  
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement.
    cll_node *node = malloc(sizeof(cll_node));
    node->value = value;
    node->is_head = 0;
    node->prev = node;
    node->next = node;

    if (list == NULL) {
        node->is_head = 1;
        return node;
    }
    
    if (before == 0 && list != NULL) {
        node->next = list->next;
        list->next = node;
        node->prev = list;
        return node;
    }
    if (before !=0 && list != NULL) {
        node->next = list;
        node->prev = list->prev;
        list->prev->next = node;
        list->prev = node;

        if (list->is_head == 1) {
            list->is_head = 0;
            node->is_head = 1;
        }
        return node;
    }

}


/**
 * Displays the contents of the list separated by commas and surrounded by
 * brackets, with the pointed-to node highlighted with asterisks.
 *
 * Reference solution provided with assignment description
 */
void cll_show(cll_node *list) {
    // Find the head of the linked list
    cll_node *head = cll_head(list);
    cll_node *ptr = head;
    // Print opening [
    putchar('[');
    // Loop through list printing values
    if (ptr) {
        do {
            if (!ptr->is_head) 
                printf(", "); // include a comma if not the first element
            if (ptr == list) 
                putchar('*'); // include * surrounding parameter element
            printf("%d", ptr->value);
            if (ptr == list) 
                putchar('*');
            ptr = ptr->next; // next pointer
        } while (ptr != head);
    }
    // Print closing ]
    puts("]");
}


int main(int argc, const char *argv[]) {

    // Example debugging code.  You should write other
    // tests, including testing corner cases.
    cll_node *x = NULL;
    putchar('A'); cll_show(x);
    x = cll_insert(25, x, 1);
    putchar('B'); cll_show(x);
    x = cll_insert(1, x, 0);
    putchar('C'); cll_show(x);
    x = cll_insert(98, x, 1);
    putchar('D'); cll_show(x);
    x = cll_insert(0, x, 1);
    putchar('E'); cll_show(x);
    x = cll_insert(-8, cll_tail(x), 0);
    putchar('F'); cll_show(x);
    cll_node *y = cll_head(x);
    putchar('G'); cll_show(y);
    printf("Length: %lu (or %lu)\n", cll_length(y), cll_length(x));
    x = cll_remove(x);
    putchar('H'); cll_show(x);
    putchar('I'); cll_show(y);
    x = cll_remove(cll_find(y, 98));
    putchar('J'); cll_show(x);
    putchar('K'); cll_show(y);

    return 0;
}
