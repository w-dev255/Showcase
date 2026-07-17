#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void ***arr;
} vp;

int main(void) {
	vp p = {NULL};
	int n = 10;
	p.arr = malloc(n * sizeof(void**));
	if (p.arr == NULL) {
		return 1;
	}
	for (int a = 0; a < n; a++) {
		p.arr[a] = malloc(n * sizeof(void*));
		if (p.arr[a] == NULL) {
			return 1;
		}
		for (int b = 0; b < n; b++) {
			p.arr[a][b] = NULL;
		}
	}
	p.arr[0][0] = malloc(100);
	if (p.arr[0][0] == NULL) {
		return 1;
	}
	if (fgets((char*)p.arr[0][0], 100, stdin) == NULL) {
		return 1;
	}
	printf("%s\n", (char*)p.arr[0][0]);
	return 0;
}
