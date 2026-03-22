#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int score[10], sum = 0, i;
	srand(time(0));
	
	for (i = 0; i < 10; i++) {
		score[i] = rand() % 101;
		sum += score[i];
	}
	printf("%d", sum / i);
}