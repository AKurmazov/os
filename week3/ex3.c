#include <stdio.h>
#include <stdlib.h>

const int N = 5;

struct Node {
    int value;
    struct Node* successor;
};

void print_list(struct Node* node) {
    printf("Current list: ");
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->successor;
    }
    printf("\n");
}

void insert_node(struct Node* head, int index, int value) {
    struct Node* current = head;

    for (int i = 0; i < index - 1; ++i) {
        current = current->successor;
        if (current == NULL) {
            return; // Out of bounds
        }
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->successor = current->successor;
    current->successor = new_node;

}

void delete_node(struct Node* head, int index) {
    if (index < 0) {
        return;
    }
    struct Node* current = head;
    struct Node* prev = NULL;

    for (int i = 0; i < index; ++i) {
        prev = current;
        current = current->successor;
        if (current == NULL) {
            return;
        }
    }

    if (prev != NULL) {
        prev->successor = current->successor;
    } else {
        *head = *head->successor;
    }

    free(current);
}

int main() {
    struct Node* head = NULL;
    print_list(head); // Gives nothing

    head = (struct Node*) malloc(sizeof(struct Node));
    head->value = 1;
    head->successor = NULL;
    print_list(head); // Gives 1

    insert_node(head, 1, 2);
    insert_node(head, 2, 3);
    insert_node(head, 3, 4);
    insert_node(head, 2, 5);
    print_list(head); // Gives 1 2 5 3 4

    delete_node(head, 2);
    delete_node(head, 2);
    print_list(head); // Gives 1 2 4

    return 0;
}