#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void ****arr;
} vp;

int main(void) {
	vp p = {NULL};
	int n = 10;
	p.arr = malloc(n * sizeof(void***));
	if (p.arr == NULL) {
		return 1;
	}
	for (int a = 0; a < n; a++) {
		p.arr[a] = malloc(n * sizeof(void**));
		if (p.arr[a] == NULL) {
			return 1;
		}
		for (int b = 0; b < n; b++) {
			p.arr[a][b] = malloc(n * sizeof(void*));
			if (p.arr[a][b] == NULL) {
				return 1;
			}
			for (int c = 0; c < n; c++) {
				p.arr[a][b][c] = malloc(n * sizeof(void*));
				if (p.arr[a][b][c] == NULL) {
					return 1;
				}
			}
		}
	}
	free(p.arr[0][0][0]);
	p.arr[0][0][0] = malloc(100);
	if (fgets((char*)p.arr[0][0][0], 100, stdin) == NULL) {
		return 1;
	}
	printf("%s\n", (char*)p.arr[0][0][0]);
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < n; c++) {
				free(p.arr[a][b][c]);
			}
			free(p.arr[a][b]);
		}
		free(p.arr[a]);
	}
	free(p.arr);
	return 0;
}
