#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void*** arr;
} vp;

int start_array(void**** arr, int n) {
	*arr = malloc(n * sizeof(void**));
	if (*arr == NULL) {
		return 1;
	}
	for (int a = 0; a < n; a++) {
		(*arr)[a] = malloc(n * sizeof(void*));
		if ((*arr)[a] == NULL) {
			return 1;
		}
		for (int b = 0; b < n; b++) {
			(*arr)[a][b] = malloc(n * sizeof(void*));
			if ((*arr)[a][b] == NULL) {
				return 1;
			}
		}
	}
	return 0;
}

int main(void) {
	vp p = {NULL};
	int n = 10;
	if (start_array(&p.arr, n) == 1) {
		return 1;
	}
	p.arr[0][0] = malloc(100);
	if (fgets((char*)p.arr[0][0], 100, stdin) == NULL) {
		return 1;
	}
	printf("%s\n", (char*)p.arr[0][0]);
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			free(p.arr[a][b]);
		}
		free(p.arr[a]);
	}
	free(p.arr);
	return 0;
}

