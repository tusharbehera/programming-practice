#include <stdio.h>

static inline sqr(int i)
{
	return i * i;
}

int solve_problem_1(int r1, int r2)
{
	int i,j;
	int num_squares = 0;
	int d1, d2, d3, d4;

	int min_dist;
	int max_dist;

	min_dist = sqr(r1);
	max_dist = sqr(r2);

	for (i = -1 * r2; i < r2; i++) {
		for (j = -1 * r2; j < r2; j++) {
			d1 = sqr(i) + sqr(j);
			d2 = sqr(i + 1) + sqr(j);
			d3 = sqr(i) + sqr(j + 1);
			d4 = sqr(i + 1) + sqr(j + 1);
			if (d1 >= min_dist && d2 >= min_dist && d3 >= min_dist && d4 >= min_dist) {
				if (d1 <= max_dist && d2 <= max_dist && d3 <= max_dist && d4 <= max_dist) {
					num_squares++;
				}
			}
		}
	}

	return num_squares;
}

int solve_problem_2(int r1, int r2)
{
	int i,j;
	int num_squares = 0;
	int d1, d2, d3, d4;

	int min_dist;
	int max_dist;

	min_dist = sqr(r1);
	max_dist = sqr(r2);

	for (i = 0; i < r2; i++) {
		for (j = 0; j < r2; j++) {
			d1 = sqr(i) + sqr(j);
			d2 = sqr(i + 1) + sqr(j + 1);
			if (d1 >= min_dist && d2 <= max_dist)
					num_squares++;
		}
	}

	return 4 * num_squares;
}

int solve_problem_3(int r1, int r2)
{
	int i,j;
	int num_squares = 0;
	int d1, d2, d3, d4;

	int min_dist;
	int max_dist;

	int lower_bound = r1 * 7 / 10;

	min_dist = sqr(r1);
	max_dist = sqr(r2);

	for (i = 0; i < r2; i++) {
		for (j = 0; j < r2; j++) {
			if (i < lower_bound && j < lower_bound)
				continue;
			d1 = sqr(i) + sqr(j);
			d2 = sqr(i + 1) + sqr(j + 1);
			if (d1 >= min_dist && d2 <= max_dist)
					num_squares++;
		}
	}

	return 4 * num_squares;
}


int main(void)
{
	int num_test, n;
	int r1, r2;
	int num_squares;

	scanf("%d", &num_test);

	printf("Num test = %d\n", num_test);

	for (n = 1; n <= num_test; n++) {
		scanf("%d", &r1);
		scanf("%d", &r2);
		num_squares = solve_problem_3(r1, r2);
		printf("Number-of-squares(%2d, %2d) = %d\n",
				r1, r2, num_squares);
	}

	return 0;
}
