#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	void*** arr;
} vp;

static int start_array(void**** arr, size_t n) {
	*arr = malloc(sizeof(void**) * n);
	if (*arr == NULL) {
		return 1;
	}
	for (int a = 0; a < (int)n; a++) {
		(*arr)[a] = malloc(sizeof(void*) * n);
		if ((*arr)[a] == NULL) {
			return 1;
		}
		for (int b = 0; b < (int)n; b++) {
			(*arr)[a][b] = NULL;
		}
	}
	return 0;
}

static int free_array(void**** arr, size_t n) {
	for (int a = 0; a < (int)n; a++) {
		for (int b = 0; b < (int)n; b++) {
			free((*arr)[a][b]);
		}
		free((*arr)[a]);
	}
	free(*arr);
        return 0;
}

int main(void) {
	vp p = {NULL};
	size_t n = 10;
	if (start_array(&p.arr, n) == 1) {
		return 1;
	}
	p.arr[0][0] = malloc(100);
	if (fgets((char*)p.arr[0][0], 100, stdin) == NULL) {
		free_array(&p.arr, n);
		return 1;
	}
	if (strlen((char*)p.arr[0][0]) == 0) {
        free_array(&p.arr, n);
		return 1;
	}
	printf("%s\n", (char*)p.arr[0][0]);
	free_array(&p.arr, n);
	return 0;
}

