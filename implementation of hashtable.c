#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);   
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index];   
    hashTable[index] = newNode;         
    printf("%d inserted successfully.\n", key);
}

void search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found in hash table (bucket %d).\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in hash table.\n", key);
}

void delete(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } 
            else {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d deleted from hash table.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not present in hash table.\n", key);
}

void display() {
    printf("\n--- Current Hash Table ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("--------------------------\n");
}

int main() {
    int choice, key;

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    while (1) {
        printf("\n====== HASH TABLE MENU ======\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
