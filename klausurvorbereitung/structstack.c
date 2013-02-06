#include <stdio.h>
#include <stdlib.h>

typedef struct stackele* spt;
struct stackele {
	int val;
	spt next;
	spt prev;
};

spt push(spt cur, int value) {
	spt new = (spt) malloc (sizeof(spt)*1);
	new->val=value;	
	cur->next=new;
	new->prev=cur;
	cur=new;
	return cur;
}

spt pop(spt cur) {
	if(cur->prev != NULL) {
		spt temp=cur->prev;
		free (cur);
		cur=temp;
	} else {
		printf("Ist nicht drinkowski, Babydoll...");
	}	
	return cur;
}

void top(spt cur) {
	printf("%d\n", cur->val);
}

void free_stack(spt cur) {
	while (cur->prev != NULL) {
		cur= cur->prev;
		free(cur->next);
	}
	free(cur);
	printf("Stack wurde aus dem Speicher gelöscht.");
}

int main(void){
	spt cur=(spt) malloc(sizeof(spt)*1);
	cur=push(cur, 100);
	top(cur);
	cur=push(cur, 200);
	top(cur);
	cur=pop(cur);
	top(cur);	
}
