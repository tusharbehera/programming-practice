#include <stdio.h>
#include <string.h>

#define MAX_ROW		50
#define MAX_ELEM	650

int main(int argc, char *argv[])
{
	int num_row;
	int values[MAX_ELEM];
	int cols[MAX_ROW];
	int sum_cols[MAX_ROW];
	int sum_max = 0;
	int i, j, n, elem_in_row, max_elem_in_row, is_double_max_row;
	int is_top_half;
	int start_row_count, first_elem_col_num;
	
	if (argc < 2) {
		printf("Syntax: ./%s <num_row>\n", argv[0]);
		printf("Using default num_row as 5\n");
		num_row = 5;
	} else {
		num_row = atoi(argv[1]);
	}

	printf("Number of rows = %d\n", num_row);
	
	for (i = 0; i < MAX_ELEM; i++)
		values[i] = i + 1;

	for (i = 0; i < MAX_ROW; i++) {
		cols[i] = 0;
		sum_cols[i] = 0;
	}

	max_elem_in_row = (num_row-1)/2;
	is_double_max_row = (num_row - 1) % 2;
	start_row_count = max_elem_in_row - 1;
	elem_in_row = 1;
	first_elem_col_num = max_elem_in_row;
	n = 0;
	is_top_half = 1;

	for (i = 0; i < num_row; i++) {
		for (j = 0; j < elem_in_row; j++)
			cols[n++] = first_elem_col_num + 2 * j;

		if (!first_elem_col_num) {
			if (is_double_max_row) {
				is_double_max_row = 0;
			} else {
				is_top_half = 0;
				first_elem_col_num++;
				elem_in_row--;
			}
		} else {
			if (is_top_half) {
				first_elem_col_num--;
				elem_in_row++;
			} else {
				first_elem_col_num++;
				elem_in_row--;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%3d %2d\n", values[i], cols[i]);			
	}

	for (i = 0; i < n; i++) {
		sum_cols[cols[i]] += values[i];
		if (sum_max < sum_cols[cols[i]])
			sum_max = sum_cols[cols[i]];		
	}

	printf("Maximum sum = %d\n", sum_max);

	return 0;
}
