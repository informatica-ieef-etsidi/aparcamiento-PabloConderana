#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

	char opcion;
	char matricula1[8], matricula2[8], matricula_comparar[8];
	int plaza1 = 0, plaza2 = 0, aux, c1, c2;


	system("color FC");
	
	printf("BIENVENIDO AL PARKING\n\n\n");

	while (1) {

		printf("Seleccione una opcion:\nR - Reservar una plaza\nA - Abandonar su plaza\nE - Ver estado del aparcamiento\nS - Salir del programa\n");
		scanf("%c", &opcion);
		getchar();

		switch (opcion) {
		case 'R':
		case 'r':
			if (plaza1 == 1 && plaza2 == 1) {
				printf("No quedan huecos libres en el aparcamiento.\n");
			}
			if (plaza1 == 0 || plaza2 == 0) {
				printf("Introduzca su numero de matricula: ");
				gets(matricula_comparar);

				c1 = strcmp(matricula1, matricula_comparar);
				c2 = strcmp(matricula2, matricula_comparar);
				
				if (c1 == 0 || c2 == 0) {
					if (c1 == 0) {
						printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 1.\n");
					}
					if (c2 == 0) {
						printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 2.\n");
					}
				}
				else {
					if (plaza1 == 0) {
						printf("Usted ha reservado la plaza 1.\n");
						plaza1 = 1;
						strcpy(matricula1, matricula_comparar);
					}
					else if (plaza2 == 0) {
						printf("Usted ha reservado la plaza 2.\n");
						plaza2 = 1;
						strcpy(matricula2, matricula_comparar);
					}
				}
			}
			break;
		case 'A':
		case 'a':
			printf("Introduzca la matricula del vehiculo con el que ha reservado la plaza: ");
			gets(matricula_comparar);

			c1 = strcmp(matricula1, matricula_comparar);
			c2 = strcmp(matricula2, matricula_comparar);

			if (c1 == 0 || c2 == 0) {
				if (c1 == 0) {
					printf("Ha abandonado la plaza 1.\n");
					plaza1 = 0;
					strcpy(matricula1, " ");
				}
				if (c2 == 0) {
					printf("Ha abandonado la plaza 2.\n");
					plaza2 = 0;
					strcpy(matricula2, " ");
				}
			}
			else {
				printf("No hay ninguna plaza reservada por un vehiculo con la matricula %s.\n", matricula_comparar);
			}
			break;
		case 'E':
		case 'e':
			printf("Plaza 1 - ");
			if (plaza1 == 1) {
				printf("Ocupada - %s\n", matricula1);
			}
			if (plaza1 == 0) {
				printf("Libre\n");
			}
			printf("Plaza 2 - ");
			if (plaza2 == 1) {
				printf("Ocupada - %s\n", matricula2);
			}
			if (plaza2 == 0) {
				printf("Libre\n");
			}
			break;
		case 'S':
		case 's':
			break;
		default:
			printf("OPCION INCORRECTA\n");
		}

		if (opcion == 'S' || opcion == 's'){
			break;
		}

		system("pause");
		system("cls");
		printf("BIENVENIDO AL PARKING\n\n\n");
	}
	system("pause");
}