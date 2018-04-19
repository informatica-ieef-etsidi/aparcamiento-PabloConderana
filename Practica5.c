#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPLAZAS 10
#define LONGITUD 20

struct plaza {
	int estado;
	char matricula[8];
	char tipo;
};
struct usuario {
	char username[LONGITUD];
	char password[LONGITUD];
};

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[8]);
int existeUsuario(struct usuario usuarioValido, char username[LONGITUD], char password[LONGITUD]);

void main() {

	struct plaza aparcamiento[NPLAZAS];
	struct usuario miUsuario = { "admin", "1234" };
	char nombreusuario[LONGITUD], contrasenausuario[LONGITUD];
	char opcion, tipo_vehiculo;
	char matricula_comparar[8];
	int aux, c, ocupamiento, i, j;
	int matriculavalida = 0, usuariovalido = 0;

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

	printf("Para poder acceder a las funciones del parking debe iniciar sesion.\n\n");

	while (1) {

		printf("Introduzca el nombre de usuario: ");
		gets(nombreusuario);
		fflush(stdin);
		printf("Introduzca la contrase%ca: ", 164);
		gets(contrasenausuario);
		fflush(stdin);

		usuariovalido = existeUsuario(miUsuario, nombreusuario, contrasenausuario);

		if (usuariovalido == 1) {
			printf("Usted ha iniciado sesion correctamente.\n\n");
			system("pause");
			system("cls");
			break;
		}
		if (usuariovalido == 0) {
			printf("El usuario o la contrase%ca introducidos son incorrectos.\n\n", 164);
		}

		usuariovalido = 0;
		system("pause");
		system("cls");
		printf("BIENVENIDO AL PARKING\n\n\n");
		printf("Para poder acceder a las funciones del parking debe iniciar sesion.\n\n");
	}

	printf("BIENVENIDO AL PARKING\n\n\n");

	while (1) {

		opcion = menu();

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

						while (1) {
							gets(matricula_comparar);
							fflush(stdin);

							matriculavalida = esMatriculaValida(matricula_comparar);

							if (matriculavalida == 1) {
								break;
							}
							if (matriculavalida == 0) {
								printf("MATRICULA NO VALIDA\n\nIntroduzca una matricula valida: ");
							}
						}

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
						
						while (1) {
							gets(matricula_comparar);
							fflush(stdin);

							matriculavalida = esMatriculaValida(matricula_comparar);

							if (matriculavalida == 1) {
								break;
							}
							if (matriculavalida == 0) {
								printf("MATRICULA NO VALIDA\n\nIntroduzca una matricula valida: ");
							}
						}

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
			
			while (1) {
				gets(matricula_comparar);
				fflush(stdin);

				matriculavalida = esMatriculaValida(matricula_comparar);

				if (matriculavalida == 1) {
					break;
				}
				if (matriculavalida == 0) {
					printf("MATRICULA NO VALIDA\n\nIntroduzca una matricula valida: ");
				}
			}

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
				printf("Plaza %d - ", i + 1);
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
			
			while (1) {
				gets(matricula_comparar);
				fflush(stdin);

				matriculavalida = esMatriculaValida(matricula_comparar);

				if (matriculavalida == 1) {
					break;
				}
				if (matriculavalida == 0) {
					printf("MATRICULA NO VALIDA\n\nIntroduzca una matricula valida: ");
				}
			}

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

		matriculavalida = 0;
		system("pause");
		system("cls");
		printf("BIENVENIDO AL PARKING\n\n\n");
	}
	//system("pause");
}

char menu() {

	char opcion;

	printf("Seleccione una opcion:\nR - Reservar una plaza\nA - Abandonar su plaza\nE - Ver estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
	scanf("%c", &opcion);
	getchar();

	return opcion;
}
int esDigitoValido(char caracter) {

	int i;
	
	switch (caracter) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4': 
	case '5':
	case '6':
	case '7': 
	case '8':
	case '9':
		i = 1;
		break;
	default:
		i = 0;
		break;
	}

	return i;
}
int esLetraValida(char caracter) {

	int i, asci;

	asci = caracter;
	if (asci >= 65 && asci <= 90 || asci >= 97 && asci <= 122) {
		i = 1;
	}
	else {
		i = 0;
	}

	return i;
}
int esMatriculaValida(char matricula[8]) {

	int i, j;

	for (i = 0, j = 1; i < 8; i++) {
		if (i <= 3) {
			j = esDigitoValido(matricula[i]);
		}
		if (i >= 4 && i <= 6) {
			j = esLetraValida(matricula[i]);
		}
		if (j == 0) {
			break;
		}
	}

	return j;
}
int existeUsuario(struct usuario usuarioValido, char username[LONGITUD], char password[LONGITUD]) {

	int i;

	if ((strcmp(username, usuarioValido.username)) == 0 && (strcmp(password, usuarioValido.password)) == 0) {
		i = 1;
	}
	else {
		i = 0;
	}

	return i;
}