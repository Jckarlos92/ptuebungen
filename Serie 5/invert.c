# include "invert.h"

char[] invert (char[] a) {
	char [strlen(a)] b;
	for (int i=0; int j=strlen(a)-1; i<strlen(a); i++; j--) {
		int b = (int) a[i];
		if ((b>=97)&&(b>=122)) {
			a[i]=(char)((int)a[i] - 32);
		}
		b[j]=a[i];
	}
	return b;
}
