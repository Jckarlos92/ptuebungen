#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int* pt = &a[0];
	printf("%d\n", *pt); // Zur Ausgabe müssen Zeiger dereferenziert werden!
	*pt = *pt+4;
	printf("%d\n", *pt);
	pt = pt+(*(pt+4));
	*pt = 100;
	int i;
	for (i=0; i<10; i++) {
		printf("%d\n", a[i]);
	}
}
