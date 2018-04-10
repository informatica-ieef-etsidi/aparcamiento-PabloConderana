#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPLAZAS 10

struct plaza {
	int estado;
	char matricula[8];
	char tipo;
};

void main() {

	struct plaza aparcamiento[NPLAZAS];
	char opcion, tipo_vehiculo;
	char matricula_comparar[8];
	int aux, c, ocupamiento, i, j;

	for (i = 0; i < NPLAZAS; i++) {
		aparcamiento[i].estado = 0;
		strcpy(aparcamiento[i].matricula, " ");
		if (i < 5) {
			aparcamiento[i].tipo = 'C';
		}
		else {
			aparcamiento[i].tipo = 'M';
		}
	}

	system("color FC");

	printf("BIENVENIDO AL PARKING\n\n\n");

	while (1) {

		printf("Seleccione una opcion:\nR - Reservar una plaza\nA - Abandonar su plaza\nE - Ver estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
		scanf("%c", &opcion);
		getchar();

		switch (opcion) {
		case 'R':
		case 'r':
			printf("Elija el tipo de plaza que desea reservar:\nC - Coche\nM - Moto\n");
			scanf("%c", &tipo_vehiculo);
			getchar();

			switch (tipo_vehiculo) {
			case 'C':
			case 'c':
				for (i = 0, ocupamiento = 0; i < 5; i++) {
					if (aparcamiento[i].estado == 1) {
						ocupamiento++;
					}
					if (aparcamiento[i].estado == 0) {
						printf("Introduzca su numero de matricula: ");
						gets(matricula_comparar);
						fflush(stdin);

						for (j = 0, c = 0; j < 5; j++) {
							aux = strcmp(matricula_comparar, aparcamiento[j].matricula);
							if (aux == 0) {
								printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza %d.\n", j + 1);
								c = 1;
								break;
							}
						}
						if (c == 1) {
							break;
						}
						if (c == 0) {
							printf("Usted ha reservado la plaza %d.\n", i + 1);
							aparcamiento[i].estado = 1;
							strcpy(aparcamiento[i].matricula, matricula_comparar);
						}
						break;
					}
				}
				if (ocupamiento == 5) {
					printf("No quedan huecos libres para coches en el aparcamiento.\n");
				}		
				break;
			case 'M':
			case 'm':
				for (i = 5, ocupamiento = 0; i < NPLAZAS; i++) {
					if (aparcamiento[i].estado == 1) {
						ocupamiento++;
					}
					if (aparcamiento[i].estado == 0) {
						printf("Introduzca su numero de matricula: ");
						gets(matricula_comparar);
						fflush(stdin);

						for (j = 5, c = 0; j < NPLAZAS; j++) {
							aux = strcmp(matricula_comparar, aparcamiento[j].matricula);
							if (aux == 0) {
								printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza %d.\n", j + 1);
								c = 1;
								break;
							}
						}
						if (c == 1) {
							break;
						}
						else if (c == 0) {
							printf("Usted ha reservado la plaza %d.\n", i + 1);
							aparcamiento[i].estado = 1;
							strcpy(aparcamiento[i].matricula, matricula_comparar);
						}
						break;
					}
				}
				if (ocupamiento == 5) {
					printf("No quedan huecos libres para coches en el aparcamiento.\n");
				}
				break;
			default:
				printf("OPCION INCORRECTA\n");
			}
			break;
		case 'A':
		case 'a':
			printf("Introduzca el tipo de vehiculo con el que ha reservado la plaza:\nC - Coche\nM - Moto\n");
			scanf("%c", &opcion);
			getchar();
			printf("Introduzca la matricula del vehiculo con el que ha reservado la plaza: ");
			gets(matricula_comparar);
			fflush(stdin);

			switch (opcion) {
			case 'C':
			case 'c':
				for (i = 0, c = 0; i < 5; i++) {
					aux = strcmp(matricula_comparar, aparcamiento[i].matricula);
					if (aux == 0) {
						printf("Ha abandonado la plaza %d.\n", i + 1);
						aparcamiento[i].estado = 0;
						strcpy(aparcamiento[i].matricula, " ");
						c = 1;
						break;
					}
				}
				if (c == 0) {
					printf("No hay ninguna plaza reservada por un vehiculo con la matricula %s.\n", matricula_comparar);
				}
				break;
			case 'M':
			case 'm':
				for (i = 5, c = 0; i < NPLAZAS; i++) {
					aux = strcmp(matricula_comparar, aparcamiento[i].matricula);
					if (aux == 0) {
						printf("Ha abandonado la plaza %d.\n", i + 1);
						aparcamiento[i].estado = 0;
						strcpy(aparcamiento[i].matricula, " ");
						c = 1;
						break;
					}
				}
				if (c == 0) {
					printf("No hay ninguna plaza reservada por un vehiculo con la matricula %s.\n", matricula_comparar);
				}
				break;
			default:
				printf("OPCION INCORRECTA\n");
				break;
			}
			break;
		case 'E':
		case 'e':
			for (i = 0; i < NPLAZAS; i++) {
				printf("Plaza %d - ", i +1);
				if (aparcamiento[i].tipo == 'C') {
					printf("Coche - ");
				}
				if (aparcamiento[i].tipo == 'M') {
					printf("Moto - ");
				}
				if (aparcamiento[i].estado == 1) {
					printf("Ocupada - %s\n", aparcamiento[i].matricula);
				}
				if (aparcamiento[i].estado == 0) {
					printf("Libre\n");
				}
			}
			break;
		case 'B':
		case 'b':
			printf("Introduzca el tipo de vehiculo con el que ha reservado la plaza:\nC - Coche\nM - Moto\n");
			scanf("%c", &opcion);
			getchar();
			printf("Introduzca la matricula del vehiculo que desea buscar: ");
			gets(matricula_comparar);
			fflush(stdin);

			switch (opcion) {
			case 'C':
			case'c':
				for (i = 0, c = 0; i < 5; i++) {
					aux = strcmp(aparcamiento[i].matricula, matricula_comparar);
					if (aux == 0) {
						printf("El vehiculo que busca se encuentra estacionado en la plaza %d.\n", i + 1);
						c = 1;
						break;
					}
				}
				if (c == 0) {
					printf("El vehiculo con la matricula %s no se encuentra estacionado en este parking.\n", matricula_comparar);
				}
				break;
			case 'M':
			case 'm':
				for (i = 5, c = 0; i < NPLAZAS; i++) {
					aux = strcmp(aparcamiento[i].matricula, matricula_comparar);
					if (aux == 0) {
						printf("El vehiculo que busca se encuentra estacionado en la plaza %d.\n", i + 1);
						c = 1;
						break;
					}
				}
				if (c == 0) {
					printf("El vehiculo con la matricula %s no se encuentra estacionado en este parking.\n", matricula_comparar);
				}
				break;
			}
			break;
		case 'S':
		case 's':
			break;
		default:
			printf("OPCION INCORRECTA\n");
		}

		if (opcion == 'S' || opcion == 's') {
			break;
		}

		system("pause");
		system("cls");
		printf("BIENVENIDO AL PARKING\n\n\n");
	}
	//system("pause");
}