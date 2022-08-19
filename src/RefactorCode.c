#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5

int **cria_slot(int **slot) {

	slot = malloc(sizeof(int *) * LINHAS);

	for (int line = 0; line < LINHAS; line++) {
		slot[line] = malloc(sizeof(int) * COLUNAS);
	}

	for (int line = 0; line < LINHAS; line++) {
		printf("Insira os valores da linha %d:\n", (line + 1));
		for (int col = 0; col < COLUNAS; col++) {
			scanf("%d", &slot[line][col]);
		}
	}
	return (slot);
}

int verificaPremio(int line, int **slot, int premio[LINHAS][COLUNAS]) {
	int count_prize = 0;

	for (int col = 0; col < COLUNAS; col++) {
		if (slot[line][col] == premio[line][col])
			count_prize++;
	}
	return count_prize;
}

void cleanSlot(int **slot) {
	int line = 0;
	while (line < LINHAS)
		free(slot[line++]);
	free(slot);
}

int main(void) {

	int premio[LINHAS][COLUNAS] = {{1, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}};

	int **slot = 0;
	int lines = 0;

	slot = cria_slot(slot);

	while (lines < LINHAS) {

		if (verificaPremio(lines, slot, premio) == COLUNAS)
			break;

		if (++lines == LINHAS) {
			cleanSlot(slot);
			slot = cria_slot(slot);
			lines = 0;
		}
	}
	
	cleanSlot(slot);
	printf("Gahnou!\n");
	return (0);
}