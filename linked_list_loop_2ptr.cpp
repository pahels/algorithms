#include <stdio.h>
#include <stdlib.h>

class Node{
    public:
        int data;
        struct Node* next;
};

bool isLoop(struct Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;

        if (fast == slow){
            return true;
        }
    }
    return false;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    if (isLoop(head)) {
        printf("Loop detected.\n");
    } else {
        printf("No loop detected.\n");
    }

    head->next->next->next->next->next = head->next;

    if (isLoop(head)) {
        printf("Loop detected.\n");
    } else {
        printf("No loop detected.\n");
    }

    head->next->next->next->next->next = NULL; // Remove loop first
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

}