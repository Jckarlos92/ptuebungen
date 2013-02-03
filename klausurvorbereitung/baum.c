#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* pt;
struct node {
	int val;
	pt left;
	pt right;
};

pt init (int value) {
	pt top = (pt) malloc(sizeof(pt)*1);
	top->val = value;
	return top;
}

int add_node (pt top, int value) {
	do {
		if (value <= top->val) {
			if (top->left != NULL) {
				top = top->left;
			 } else {
				top->left = (pt) malloc(sizeof(pt)*1);
				top->left->val = value;
				return 0;
			}
		} else {
			if (top->right != NULL) {
				top = top->right;
			} else {
				top->right = (pt) malloc(sizeof(pt)*1);
				top->right->val = value;
				return 0;
			}
		}
	} while (value);
}

int baum_out(pt top) {
	if (top->left != NULL)
		baum_out(top->left);
	printf("%d\n", top->val);
	if (top->right != NULL)
		baum_out(top->right);
	return 0;
}

int main (void) {
	int input;
	printf("Gib einen Wert ein, mit dem der Baum initialisiert werden soll!\n");
	scanf("%d", &input);
	pt top = init(input);	
	do {
		printf("Gib einen Wert ein, der dem Baum hinzugefügt werden soll!\n");
		scanf("%d", &input);
		add_node(top, input);
		printf("Weitermachen? 0=nein/1=ja\n");
		scanf("%d", &input);
	} while (input == 1);
	printf("\n");
	baum_out(top);
}
