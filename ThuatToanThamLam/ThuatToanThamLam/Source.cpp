#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int start;
	int finish;
} Activity;


int compare(const void *a, const void *b) {
	Activity *activityA = (Activity *)a;
	Activity *activityB = (Activity *)b;
	return activityA->finish - activityB->finish;
}


void printMaxActivities(Activity activities[], int n) {

	qsort(activities, n, sizeof(Activity), compare);

	printf("Cac hoat dong duoc chon:\n");

	int i = 0;
	printf("(%d, %d)\n", activities[i].start, activities[i].finish);


	for (int j = 1; j < n; j++) {
	
		if (activities[j].start >= activities[i].finish) {
			printf("(%d, %d)\n", activities[j].start, activities[j].finish);
			i = j;
		}
	}
}

int main() {
	Activity activities[] = { { 1, 3 }, { 2, 4 }, { 0, 6 }, { 5, 7 }, { 8, 9 }, { 5, 9 } };
	int n = sizeof(activities) / sizeof(activities[0]);

	printMaxActivities(activities, n);
	getchar();
	return 0;
}
