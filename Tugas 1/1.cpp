#include<stdio.h>
#include<stdlib.h>

struct node {
    int score;
    node* next;
}*head, * tail;

node* createnode(int value) 
{
    node* temp = (node*)malloc(sizeof(node));
    temp->score = value;
    temp->next = NULL;
    return temp;
}

void push(int value, node** curr_node) 
{
    node* temp = createnode(value);
    temp->next = *curr_node;
    *curr_node = temp;
}

void pushtail(int value) 
{
    node* temp = createnode(value);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}
void swap(node* node1, node* node2) {
    if (head) {
        node* hapus = head;
        while (hapus) {
            hapus = head->next;
            head->next = NULL;
            free(head);
            head = hapus;
        }
    }
    node* temp1 = node1, * temp2 = node2;
    while (temp1 && temp2) {
        if (temp1->score > temp2->score) {
            pushtail(temp2->score);
            temp2 = temp2->next;
        }
        else {
            pushtail(temp1->score);
            temp1 = temp1->next;
        }
    }
    while (temp1) {
        pushtail(temp1->score);
        temp1 = temp1->next;
    }
    while (temp2) {
        pushtail(temp2->score);
        temp2 = temp2->next;
    }
}

void print(node* curr_node) {
    while (curr_node) {
        if (curr_node->next == NULL) {
            printf("%d\n", curr_node->score);
            curr_node = curr_node->next;
        }
        else {
            printf("%d -> ", curr_node->score);
            curr_node = curr_node->next;
        }
    }
}

int main() {
    node* x = NULL;
    node* y = NULL;
    int n, m, num;
    printf("Berapa banyak elemen pada daftar pertama(terbesar ke terkecil): ");
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &num);
        push(num, &x);
    }
    print(x);
    printf("Berapa banyak elemen pada daftar pertama(terbesar ke terkecil): ");
    scanf("%d", &m);
    for (int i = 0;i < n;i++) {
        scanf("%d", &num);
        push(num, &y);
    }
    swap(y, x);
    print(head);

    return 0;
}
