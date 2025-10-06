
#include <stdio.h>

int main() {
	int numeri[3];
	int max, i;

	for (i = 0; i < 3; i++) {
        printf("Inserisci il numero %d intero: ", i + 1);
		scanf("%d", &numeri[i]);
	}

	max = numeri[0];
	for (i = 1; i < 3; i++) {
		if (numeri[i] > max) {
			max = numeri[i];
		}
	}

	printf("Il maggiore è: %d\n", max);
	return 0;
}
