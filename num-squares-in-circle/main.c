#include <stdio.h>

static inline sqr(int i)
{
	return i * i;
}

int main(int argc, char *argv[])
{
	int r1;
	int r2;

	int i,j;
	int num_squares = 0;
	int d1, d2, d3, d4;

	int min_dist;
	int max_dist;

	if (argc < 3) {
		printf("Syntax: %s <small-circle-radius> <big-cirle-radius>\n", argv[0]);
		r1 = 1;
		r2 = 3;
	} else {
		r1 = atoi(argv[1]);
		r2 = atoi(argv[2]);
	}

	min_dist = sqr(r1);
	max_dist = sqr(r2);

	printf("Finding number of unit squares between circles of radius %d and %d\n", r1, r2);

	for (i = -1 * r2; i < r2; i++) {
		for (j = -1 * r2; j < r2; j++) {
			d1 = sqr(i) + sqr(j);
			d2 = sqr(i + 1) + sqr(j);
			d3 = sqr(i) + sqr(j + 1);
			d4 = sqr(i + 1) + sqr(j + 1);
			if (d1 >= min_dist && d2 >= min_dist && d3 >= min_dist && d4 >= min_dist) {
				if (d1 <= max_dist && d2 <= max_dist && d3 <= max_dist && d4 <= max_dist) {
					num_squares++;
					printf("Unit square at (%d, %d) <-> (%d, %d)\n", i, j, i + 1, j + 1);
				}
			}
		}
	}

	printf("Number of squares = %d\n", num_squares);

	return 0;
}
