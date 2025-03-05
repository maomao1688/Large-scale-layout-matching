#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct POS {
    int x, y;
    struct POS* next;
};

struct result{
    int x;
    struct result* nest;
};

void readtxt(const char* filename, struct POS** head) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open the file: %s\n", filename);
        return;
    }

    struct POS* current = NULL;
    int x, y;

    while (fscanf(file, "%d %d", &x, &y) == 2) {
        struct POS* new_pos = (struct POS*)malloc(sizeof(struct POS));
        if (new_pos == NULL) {
            printf("Memory allocation error.\n");
            fclose(file);
            return;
        }

        new_pos->x = x;
        new_pos->y = y;
        new_pos->next = NULL;

        if (*head == NULL) {
            *head = new_pos;
            current = new_pos;
        } else {
            current->next = new_pos;
            current = new_pos;
        }
    }

    fclose(file);
}

void prinAndFreeList(struct POS* head) {
    struct POS* temp = head;
    while (temp != NULL) {
        printf("x: %d, y: %d\n", temp->x, temp->y);
        struct POS* prev = temp;
        temp = temp->next;
        free(prev);
    }
}

int main() {
    struct POS* in1_head = NULL;
    struct POS* in2_head = NULL;
    struct POS* in3_head = NULL;
    struct POS* tp_head = NULL;

    readtxt("in1.txt", &in1_head);

    readtxt("in2.txt", &in2_head);

    readtxt("in3.txt", &in3_head);

    readtxt("tp.txt", &tp_head);

    int 







    printf("Data from in1.txt:\n");
    prinAndFreeList(in1_head);

    printf("\nData from in2.txt:\n");
    prinAndFreeList(in2_head);

    printf("\nData from in3.txt:\n");
    prinAndFreeList(in3_head);

    return 0;
}
