#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteHead(Node** head) {
   if(head == NULL) {
    return;
   }
   Node* temp = *head;
   *head = temp->next;
   if(*head != NULL) {
    (*head)->prev = NULL;
   }
}

void deleteEnd(Node** head) {
   if(head == NULL) {
    return;
   }
   Node* temp = *head;
   if(temp->next == NULL) {
    *head = NULL;
    return;
   }
   while(temp->next != NULL) {
    temp = temp->next;
   }
   temp->prev->next = NULL;
}

void printListHead(Node* head) {
Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printListEnd(Node* head) {
if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int n, data, choice;
    Node* head = NULL;
    do
    {
        printf("\n---------------MENU---------------\n");
        printf("0. Thoat\n");
        printf("1. Them phan tu vao dau danh sach\n");
        printf("2. Them phan tu vao cuoi danh sach\n");
        printf("3. Chen phan tu vao vi tri cu the\n");
        printf("4. Xoa phan tu dau danh sach\n");
        printf("5. Xoa phan tu cuoi danh sach\n");
        printf("6. Xoa phan tu theo gia tri\n");
        printf("7. Duyet danh sach tu dau den cuoi\n");
        printf("8. Duyet danh sach tu cuoi den dau\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                exit(0);
            case 1:
                printf("nhap so luong phan tu: ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insertHead(&head, data);
                }
                break;
            case 2:
                printf("nhap so luong phan tu: ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insertEnd(&head, data);
                }
                break;
            case 4:
                printf("Xoa phan tu dau danh sach\n");
                deleteHead(&head);
                break;
            case 5:
                printf("Xoa phan tu cuoi danh sach\n");
                deleteEnd(&head);
                break;
            case 7:
                printf("Duyet danh sach tu dau den cuoi\n");
                printListHead(head);
                break;
            case 8:
                printf("Duyet danh sach tu cuoi den dau\n");
                printListEnd(head);
                break;
            default:
                break;
        }
    } while (1==1);
    
    return 0;
}