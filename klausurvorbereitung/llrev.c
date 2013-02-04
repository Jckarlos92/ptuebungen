/* Hier eine linked list samt Umkehrmethode */
# include <stdio.h>
# include <stdlib.h>

typedef struct listElem * listElemPT;
struct listElem {
    int val;
    listElemPT next;
};

struct listElem* append(struct listElem *le, int v) {
    le->next = (listElemPT) malloc(sizeof(struct listElem));
    le->next->val = v;
    le->next->next = NULL;

    return le->next;
}

struct listElem* reverse(struct listElem *b) {
    listElemPT cur,prev,next;

    prev = b;
    cur = b->next;
    prev->next = NULL;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

int main (int argc, char** argv) {
    struct listElem *begin = (listElemPT)malloc(sizeof(struct listElem));
    struct listElem *wp;
    begin->next = NULL;
    begin->val = 0;

    int i = 1;
    wp = begin;
    for (;i<10;++i) {
        wp = append(wp, i);
    }

    printf("Test Traversal:\n");
    wp = begin;
    while (wp) {
        printf("%d ", wp->val);
        wp = wp->next;
    }
    printf("\n");
    
    printf("Reversing now...");
    printf("done!\n");
    wp = reverse(begin);
    printf("Test Traversal:\n");
    while (wp) {
        printf("%d ", wp->val);
        wp = wp->next;
    }
    printf("\n");
    return 0;
}
