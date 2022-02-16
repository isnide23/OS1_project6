// Ian Snyder

#include "myalloc.h"

struct block *head = NULL;  // Head of the list, empty

int main (void) {
    void *p;

    print_data();
    p = myalloc(16);
    print_data();
    p = myalloc(16);
    printf("%p\n", p);
}

void *myalloc(int size) {
    // void *heap = sbrk(1024);
    // if this is the first run
    if (head == NULL) {
        head = sbrk(1024);
        head->next = NULL;
        head->size = 1024 - PADDED_SIZE(sizeof(struct block));
        head->in_use = 0;
    }

    int padded_size = PADDED_SIZE(size);

    block *cur = head;

    while (cur != NULL) {
        if (!(cur->in_use = 1) && cur->size >= padded_size) {
            cur->in_use = 1;
            printf("Found one!\n");
        }
        cur = cur->next;
    }

    // Walk the list looking for a free node
    // let n = the free node
    // If n's data big enough for user request

    //     Mark n as used

    //     Return address of n's data

    // If we get here, there was no room
    return NULL;
        
}


void print_data(void) {
    struct block *b = head;

    if (b == NULL) {
        printf("[empty]\n");
        return;
    }

    while (b != NULL) {
        // Uncomment the following line if you want to see the pointer values
        //printf("[%p:%d,%s]", b, b->size, b->in_use? "used": "free");
        printf("[%d,%s]", b->size, b->in_use? "used": "free");
        if (b->next != NULL) {
            printf(" -> ");
        }

        b = b->next;
    }

    printf("\n");
}


