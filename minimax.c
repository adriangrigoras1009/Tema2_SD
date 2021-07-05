#include<stdio.h>

#include<stdlib.h>

#include<string.h>

typedef struct arbore {
	char **tabla;
	struct arbore *child;
	struct arbore *next;
}
arbore;
typedef struct arbore2 {
	int nr;
	char par;
	int alfa;
	int beta;
	struct arbore2 *child;
	struct arbore2 *next;
	struct arbore2 *prev;
	struct arbore2 *parent;
}
arbore2;

typedef struct arbore3 {
	int nr;
	int *vector;
	char par;
	struct arbore3 *child;
	struct arbore3 *next;
	struct arbore3 *prev;
	struct arbore3 *parent;
}
arbore3;

typedef struct Queue {
	struct node *head, *tail;
	int len;
}
Queue;
typedef struct Queue3 {
	struct node3 *head, *tail;
	int len;
}
Queue3;
typedef struct node {
	arbore2 *parinte;
	struct node *next;
}
node;
typedef struct node3 {
	arbore3 *parinte;
	struct node3 *next;
}
node3;
void initq(Queue ** q)
{
	(*q) = (Queue *) malloc(sizeof(Queue));
	(*q) -> head = NULL;
	(*q) -> tail = NULL;
	(*q) -> len = 0;
}
void initq3(Queue3 ** q)
{
	(*q) = (Queue3 *) malloc(sizeof(Queue));
	(*q) -> head = NULL;
	(*q) -> tail = NULL;
	(*q) -> len = 0;
}
void add_queue(Queue *q, arbore2 *joc)
{
	node *t;
	t = malloc(sizeof(node));
	if (q -> head == NULL) {
		t -> parinte = joc;
		t -> next = NULL;
		q -> head = t;
		q -> tail = t;
		q -> len++;
	} else {
		t -> parinte = joc;
		t -> next = NULL;
		q -> tail -> next = t;
		q -> tail = t;
		q -> len++;
	}
}
void add_queue3(Queue3 *q, arbore3 *joc)
{
	node3 *t;
	t = malloc(sizeof(node3));
	if (q -> head == NULL) {
		t -> parinte = joc;
		t -> next = NULL;
		q -> head = t;
		q -> tail = t;
		q -> len++;
	} else {
		t -> parinte = joc;
		t -> next = NULL;
		q -> tail -> next = t;
		q -> tail = t;
		q -> len++;
	}
}
arbore2 *pop_queue(Queue *q) {
	node *t;
	arbore2 *elem;
	t = q -> head;
	elem = t -> parinte;
	q -> head = t -> next;
	free(t);
	q -> len--;
	return elem;
}
arbore3 *pop_queue3(Queue3 *q) {
	node3 *t;
	arbore3 *elem;
	t = q -> head;
	elem = t -> parinte;
	q -> head = t -> next;
	free(t);
	q -> len--;
	return elem;
}
int verificare_castig(arbore *joc, int linii, int coloane, char jucator)
{
	int l, c, inventar;
	int contor2 = 0;
	for (l = 0; l < linii; l++) {
		contor2 = 0;
		for (c = 1; c < coloane; c++) {
			if (joc -> tabla[l][c] == jucator &&joc -> tabla[l][c - 1] == jucator)
				contor2++;
			else
			if (contor2 != 3)
				contor2 = 0;
			if (contor2 == 3)
				break;
		}
		if (contor2 == 3)
			break;
	}
	if (contor2 != 3) {
		contor2 = 0;
		for (l = 0; l < coloane; l++) {
			contor2 = 0;
			for (c = 1; c < linii; c++) {
				if (joc -> tabla[c][l] == jucator &&joc -> tabla[c - 1][l] == jucator)
					contor2++;
				else
				if (contor2 != 3)
					contor2 = 0;
				if (contor2 == 3)
					break;
			}
			if (contor2 == 3)
				break;
		}
	}
	if (contor2 != 3) {
		contor2 = 0;
		for (inventar = 0; inventar < coloane - 3; inventar++) {
			contor2 = 0;
			for (l = 1, c = inventar + 1; l < linii &&c < coloane; l++, c++) {
				if (joc -> tabla[l - 1][c - 1] == jucator &&joc -> tabla[l][c] == jucator)
					contor2++;
				else
				if (contor2 != 3)
					contor2 = 0;
				if (contor2 == 3)
					break;
			}
			if (contor2 == 3)
				break;
		}
		if (contor2 != 3) {
			contor2 = 0;
			for (inventar = 0; inventar < linii - 3; inventar++) {
				contor2 = 0;
				for (l = inventar + 1, c = 1; l < linii &&c < coloane; l++, c++) {
					if (joc -> tabla[l - 1][c - 1] == jucator &&joc -> tabla[l][c] == jucator)
						contor2++;
					else
					if (contor2 != 3)
						contor2 = 0;
					if (contor2 == 3)
						break;
				}
				if (contor2 == 3)
					break;
			}
			if (contor2 != 3) {
				contor2 = 0;
				for (inventar = coloane - 1; inventar > 2; inventar--) {
					contor2 = 0;
					for (c = inventar - 1, l = 1; l < linii &&c >= 0; l++, c--) {
						if (joc -> tabla[l - 1][c + 1] == jucator &&joc -> tabla[l][c] == jucator)
							contor2++;
						else
						if (contor2 != 3)
							contor2 = 0;
						if (contor2 == 3)
							break;
					}
					if (contor2 == 3)
						break;
				}
				if (contor2 != 3) {
					contor2 = 0;
					for (inventar = linii - 1; inventar > 2; inventar--) {
						contor2 = 0;
						for (c = 1, l = inventar - 1; l >= 0 &&c < coloane; l--, c++) {
							if (joc -> tabla[l + 1][c - 1] == jucator &&joc -> tabla[l][c] == jucator)
								contor2++;
							else
							if (contor2 != 3)
								contor2 = 0;
							if (contor2 == 3)
								break;
						}
						if (contor2 == 3)
							break;
					}
				}
			}
		}
	}
	if (contor2 == 3)
		return 1;
	else
		return 0;
}
void construire(arbore *joc, char jucator, int linii, int coloane, FILE *result)
{
	int a1, b1;
	joc -> child = NULL;
	static int contor = 0;
	int i, j, l, c, x, z;
	for (l = 0; l < linii; l++) {
		for (x = 0; x < contor; x++)
			fprintf(result, "\t");
		for (c = 0; c < coloane; c++) {
			fprintf(result, "%c", joc -> tabla[l][c]);
			if (c < coloane - 1)
				fprintf(result, " ");
		}
		fprintf(result, "\n");
	}
	fprintf(result, "\n");
	for (i = 0; i < coloane; i++) {
		for (j = linii - 1; j >= 0; j--) {
			if (joc -> tabla[j][i] == '-') {
				arbore *aux2 = joc -> child;
				if (joc -> child == NULL) {
					joc -> child = malloc(sizeof(arbore));
					joc -> child -> tabla = malloc(linii *sizeof(char *));
					joc -> child -> next = NULL;
					joc -> child -> child = NULL;
					for (z = 0; z < linii; z++) {
						joc -> child -> tabla[z] = malloc(coloane *sizeof(char));
					}
					for (a1 = 0; a1 < linii; a1++)
						for (b1 = 0; b1 < coloane; b1++)
							joc -> child -> tabla[a1][b1] = joc -> tabla[a1][b1];
					joc -> child -> tabla[j][i] = jucator;
					if (jucator == 'R') {
						contor++;
						if (verificare_castig(joc, linii, coloane, 'B') == 0) {
							construire(joc -> child, 'B', linii, coloane, result);
						}
						contor--;
						joc -> child -> tabla[j][i] = '-';
						break;
					}
					if (jucator == 'B') {
						contor++;
						if (verificare_castig(joc, linii, coloane, 'R') == 0) {
							construire(joc -> child, 'R', linii, coloane, result);
						}
						contor--;
						joc -> child -> tabla[j][i] = '-';
						break;
					}
				} else {
					while (aux2 -> next != NULL) {
						aux2 = aux2 -> next;
					}
					int z;
					arbore *aux = malloc(sizeof(arbore));
					aux -> next = NULL;
					aux -> child = NULL;
					aux -> tabla = malloc(linii *sizeof(char *));
					for (z = 0; z < linii; z++) {
						aux -> tabla[z] = malloc(coloane *sizeof(char));
					}
					for (a1 = 0; a1 < linii; a1++)
						for (b1 = 0; b1 < coloane; b1++)
							aux -> tabla[a1][b1] = joc -> tabla[a1][b1];
					aux -> tabla[j][i] = jucator;
					aux2 -> next = aux;
					if (jucator == 'R') {
						contor++;
						if (verificare_castig(joc, linii, coloane, 'B') == 0) {
							construire(aux2 -> next, 'B', linii, coloane, result);
						}
						contor--;
						aux2 -> next -> tabla[j][i] = '-';
						break;
					}
					if (jucator == 'B') {
						contor++;
						if (verificare_castig(joc, linii, coloane, 'R') == 0) {
							construire(aux2 -> next, 'R', linii, coloane, result);
						}
						contor--;
						aux2 -> next -> tabla[j][i] = '-';
						break;
					}
				}
			}
		}
	}
}
void free_task1(arbore *joc, int linii, int coloane)
{
	int i;
	arbore *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> child != NULL) {
			free_task1(aux, linii, coloane);
			for (i = 0; i < linii; i++)
				free(aux -> tabla[i]);
			free(aux -> tabla);
			arbore *t = (joc) -> child -> next;
			free(aux);
			((joc) -> child) = t;
			aux = ((joc) -> child);
		} else {
			for (i = 0; i < linii; i++)
				free(joc -> child -> tabla[i]);
			free(joc -> child -> tabla);
			arbore *t = (joc) -> child -> next;
			free(joc -> child);
			(joc -> child) = t;
			aux = (joc -> child);
		}
	}
}
void citire_fisier_task1(FILE *test, FILE *result)
{
	arbore *joc;
	int i, j;
	int linii, coloane;
	char jucator;
	joc = malloc(sizeof(arbore));
	fscanf(test, "%d ", &linii);
	fscanf(test, "%d ", &coloane);
	fscanf(test, "%c\n", &jucator);
	joc -> tabla = malloc(linii *sizeof(char *));
	for (i = 0; i < linii; i++) {
		joc -> tabla[i] = malloc(coloane *sizeof(char));
	}
	for (i = 0; i < linii; i++) {
		for (j = 0; j < coloane; j++) {
			fscanf(test, "%c ", &joc -> tabla[i][j]);
		}
		fscanf(test, "\n");
	}
	construire(joc, jucator, linii, coloane, result);
	free_task1(joc, linii, coloane);
	for (i = 0; i < linii; i++)
		free(joc -> tabla[i]);
	free(joc -> tabla);
	free(joc);
}
void constructie2(arbore2 ** joc, FILE *test, int lungime)
{
	Queue *q;
	char par2, space;
	*joc = malloc(sizeof(arbore2));
	(*joc) -> child = NULL;
	fscanf(test, "%c", &(*joc) -> par);
	fscanf(test, "%d%c%c", &(*joc) -> nr, &par2, &space);
	int contor = 0;
	int i, j;
	initq(&q);
	add_queue(q, *joc);
	for (i = 1; i < lungime; i++) {
		contor = 0;
		do {
			arbore2 *scos = pop_queue(q);
			scos -> child = NULL;
			int t = scos -> nr;
			for (j = 0; j < t; j++) {
				if (scos -> child == NULL) {
					scos -> child = malloc(sizeof(arbore2));
					fscanf(test, "%c", &scos -> child -> par);
					fscanf(test, "%d%c%c", &scos -> child -> nr, &par2, &space);
					scos -> child -> child = NULL;
					scos -> child -> next = NULL;
					scos -> child -> prev = NULL;
					scos -> child -> parent = scos;
					if (scos -> child -> par == '(') {
						contor = contor + 1;
						add_queue(q, scos -> child);
					}
				} else {
					arbore2 *aux = scos -> child;
					while (aux -> next != NULL)
						aux = aux -> next;
					arbore2 *adaug = malloc(sizeof(arbore2));
					fscanf(test, "%c", &adaug -> par);
					fscanf(test, "%d%c%c", &adaug -> nr, &par2, &space);
					adaug -> child = NULL;
					adaug -> parent = scos;
					adaug -> prev = aux;
					adaug -> next = NULL;
					aux -> next = adaug;
					if (aux -> next -> par == '(') {
						add_queue(q, aux -> next);
						contor = contor + 1;
					}
				}
			}
		} while (contor < q -> len);
	}
	free(q);
}
void constructie3(arbore3 ** joc, FILE *test, int nr_joc, int lungime)
{
	Queue3 *q;
	char par2, space, virgula;
	*joc = malloc(sizeof(arbore3));
	(*joc) -> child = NULL;
	(*joc) -> vector = malloc(nr_joc *sizeof(int));
	fscanf(test, "%c", &(*joc) -> par);
	fscanf(test, "%d%c%c", &(*joc) -> nr, &par2, &space);
	int contor = 0;
	int i, j, z;
	initq3(&q);
	add_queue3(q, *joc);
	for (i = 1; i < lungime; i++) {
		contor = 0;
		do {
			arbore3 *scos = pop_queue3(q);
			scos -> child = NULL;
			int t = scos -> nr;
			for (j = 0; j < t; j++) {
				if (scos -> child == NULL) {
					scos -> child = malloc(sizeof(arbore3));
					fscanf(test, "%c", &scos -> child -> par);
					if (scos -> child -> par == '(') {
						fscanf(test, "%d%c%c", &scos -> child -> nr, &par2, &space);
						scos -> child -> parent = scos;
						scos -> child -> vector = malloc(nr_joc *sizeof(int));
						scos -> child -> next = NULL;
						scos -> child -> child = NULL;
						contor = contor + 1;
						add_queue3(q, scos -> child);
					} else {
						scos -> child -> parent = scos;
						scos -> child -> next = NULL;
						scos -> child -> child = NULL;
						scos -> child -> vector = malloc(nr_joc *sizeof(int));
						for (z = 0; z < nr_joc; z++) {
							if (z < nr_joc - 1)
								fscanf(test, "%d%c", &scos -> child -> vector[z], &virgula);
							else
								fscanf(test, "%d%c%c", &scos -> child -> vector[z], &par2, &space);
						}
					}
				} else {
					arbore3 *aux = scos -> child;
					while (aux -> next != NULL)
						aux = aux -> next;
					arbore3 *adaug = malloc(sizeof(arbore3));
					fscanf(test, "%c", &adaug -> par);
					if (adaug -> par == '(') {
						fscanf(test, "%d%c%c", &adaug -> nr, &par2, &space);
						adaug -> parent = scos;
						adaug -> prev = aux;
						adaug -> next = NULL;
						adaug -> child = NULL;
						adaug -> vector = malloc(nr_joc *sizeof(int));
						aux -> next = adaug;
						if (aux -> next -> par == '(') {
							add_queue3(q, aux -> next);
							contor = contor + 1;
						}
					} else {
						adaug -> parent = scos;
						adaug -> prev = aux;
						adaug -> vector = malloc(nr_joc *sizeof(int));
						adaug -> next = NULL;
						adaug -> child = NULL;
						for (z = 0; z < nr_joc; z++) {
							if (z < nr_joc - 1)
								fscanf(test, "%d%c", &adaug -> vector[z], &virgula);
							else
								fscanf(test, "%d%c%c", &adaug -> vector[z], &par2, &space);
						}
						aux -> next = adaug;
					}
				}
			}
		} while (contor < q -> len);
	}
	free(q);
}
void minimax(arbore2 *joc, int lungime)
{
	static int contor;
	int contor2 = 0;
	int min, max;
	arbore2 *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> par == '(') {
			contor++;
			minimax(aux, lungime);
			contor--;
			if (contor2 == 0) {
				min = aux -> nr;
				max = aux -> nr;
			} else {
				if (aux -> nr > max)
					max = aux -> nr;
				if (aux -> nr < min)
					min = aux -> nr;
			}
			contor2++;
		}
		if (aux -> par == '[') {
			if (contor2 == 0) {
				min = aux -> nr;
				max = aux -> nr;
			} else {
				if (aux -> nr > max)
					max = aux -> nr;
				if (aux -> nr < min)
					min = aux -> nr;
			}
			contor2++;
		}
		aux = aux -> next;
	}
	if (contor % 2 == 0) {
		joc -> nr = max;
	} else {
		joc -> nr = min;
	}
}
void paranoic(arbore3 *joc, int lungime, int nr_joc)
{
	static int contor;
	int i;
	int contor2 = 0;
	int min[nr_joc];
	int max[nr_joc];
	arbore3 *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> par == '(') {
			contor++;
			paranoic(aux, lungime, nr_joc);
			contor--;
			if (contor2 == 0) {
				for (i = 0; i < nr_joc; i++) {
					min[i] = aux -> vector[i];
					max[i] = aux -> vector[i];
				}
			} else {
				if (aux -> vector[0] > max[0])
					for (i = 0; i < nr_joc; i++)
						max[i] = aux -> vector[i];
				if (aux -> vector[0] < min[0])
					for (i = 0; i < nr_joc; i++)
						min[i] = aux -> vector[i];
			}
			contor2++;
		}
		if (aux -> par == '[') {
			if (contor2 == 0) {
				for (i = 0; i < nr_joc; i++) {
					min[i] = aux -> vector[i];
					max[i] = aux -> vector[i];
				}
			} else {
				if (aux -> vector[0] > max[0])
					for (i = 0; i < nr_joc; i++)
						max[i] = aux -> vector[i];
				if (aux -> vector[0] < min[0])
					for (i = 0; i < nr_joc; i++)
						min[i] = aux -> vector[i];
			}
			contor2++;
		}
		aux = aux -> next;
	}
	if (contor % nr_joc != 0) {
		for (i = 0; i < nr_joc; i++)
			joc -> vector[i] = min[i];
	} else {
		for (i = 0; i < nr_joc; i++)
			joc -> vector[i] = max[i];
	}
}
void free_memory(arbore2 *aux)
{
	while (aux != NULL) {
		arbore2 *t = aux -> next;
		if (aux -> next != NULL || aux -> prev != NULL) {
			if (aux -> next != NULL &&aux -> prev != NULL) {
				aux -> prev -> next = aux -> next;
				aux -> next -> prev = aux -> prev;
			} else {
				if (aux -> prev == NULL)
					aux -> next -> prev = NULL;
				if (aux -> next == NULL)
					aux -> prev -> next = aux -> next;
			}
			arbore2 *z = aux -> child;
			free(aux);
			if (z != NULL) {
				free_memory(z);
			}
		} else {
			arbore2 *z = aux -> child;
			free(aux);
			if (z != NULL) {
				free_memory(z);
			}
		}
		aux = t;
	}
}
void alpha(arbore2 *joc)
{
	static int contor;
	int contor2 = 0;
	int min, max;
	arbore2 *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> par == '(') {
			aux -> alfa = aux -> parent -> alfa;
			aux -> beta = aux -> parent -> beta;
			contor++;
			alpha(aux);
			contor--;
			if (contor2 == 0) {
				min = aux -> nr;
				max = aux -> nr;
			} else {
				if (aux -> nr > max)
					max = aux -> nr;
				if (aux -> nr < min)
					min = aux -> nr;
			}
			contor2++;
			if (contor % 2 != 0) {
				if (aux -> nr < aux -> parent -> beta)
					aux -> parent -> beta = aux -> nr;
			} else {
				if (aux -> nr > aux -> parent -> alfa)
					aux -> parent -> alfa = aux -> nr;
			}
			if (aux -> parent -> alfa >= aux -> parent -> beta) {
				aux = aux -> next;
				free_memory(aux);
				break;
			} else {
				if (aux -> next == NULL)
					break;
				aux = aux -> next;
			}
		}
		if (aux -> par == '[') {
			aux -> alfa = aux -> parent -> alfa;
			aux -> beta = aux -> parent -> beta;
			if (contor2 == 0) {
				min = aux -> nr;
				max = aux -> nr;
			} else {
				if (aux -> nr > max)
					max = aux -> nr;
				if (aux -> nr < min)
					min = aux -> nr;
			}
			contor2++;
			if (contor % 2 != 0) {
				if (aux -> nr < aux -> parent -> beta)
					aux -> parent -> beta = aux -> nr;
			} else {
				if (aux -> nr > aux -> parent -> alfa)
					aux -> parent -> alfa = aux -> nr;
			}
			if (aux -> parent -> alfa >= aux -> parent -> beta) {
				aux = aux -> next;
				free_memory(aux);
				break;
			} else
			if (aux -> next == NULL)
				break;
			aux = aux -> next;
		}
	}
	if (contor % 2 == 0) {
		joc -> nr = max;
	}
	if (contor % 2 != 0) {
		joc -> nr = min;
	}

}
void afisare(arbore2 *joc, FILE *result)
{
	int z, j;
	static int contor;
	for (j = 0; j < contor; j++) {
		fprintf(result, "\t");
	}
	fprintf(result, "%d\n", joc -> nr);
	arbore2 *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> par == '(') {
			contor++;
			afisare(aux, result);
			contor--;
		} else {
			for (z = 0; z <= contor; z++) {
				fprintf(result, "\t");
			}
			fprintf(result, "%d\n", aux -> nr);
		}
		if (aux -> next == NULL)
			break;
		aux = aux -> next;
	}
}
void free_task2(arbore2 *joc) {
	arbore2 *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> child != NULL) {
			free_task2(aux);
			arbore2 *t = (joc) -> child -> next;
			if (t != NULL)
				t -> prev = NULL;
			free(aux);
			((joc) -> child) = t;
			aux = ((joc) -> child);
		} else {
			arbore2 *t = (joc) -> child -> next;
			if (t != NULL)
				t -> prev = NULL;
			free(aux);
			((joc) -> child) = t;
			aux = ((joc) -> child);
		}
	}
}
void afisare3(arbore3 *joc, int nr_joc, FILE *result)
{
	static int contor;
	int j, t, z;
	for (j = 0; j < contor; j++) {
		fprintf(result, "\t");
	}
	fprintf(result, "[");
	for (t = 0; t < nr_joc; t++) {
		if (t < nr_joc - 1)
			fprintf(result, "%d,", joc -> vector[t]);
		else
			fprintf(result, "%d]\n", joc -> vector[t]);
	}
	arbore3 *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> par == '(') {
			contor++;
			afisare3(aux, nr_joc, result);
			contor--;
		} else {
			for (z = 0; z <= contor; z++) {
				fprintf(result, "\t");
			}
			fprintf(result, "[");
			for (t = 0; t < nr_joc; t++) {
				if (t < nr_joc - 1)
					fprintf(result, "%d,", aux -> vector[t]);
				else
					fprintf(result, "%d]\n", aux -> vector[t]);
			}
		}
		if (aux -> next == NULL)
			break;
		aux = aux -> next;
	}
}
void free_bonus(arbore3 *joc) {
	arbore3 *aux = joc -> child;
	while (aux != NULL) {
		if (aux -> child != NULL) {
			free_bonus(aux);
			arbore3 *t = (joc) -> child -> next;
			if (t != NULL)
				t -> prev = NULL;
			free(aux -> vector);
			free(aux);
			((joc) -> child) = t;
			aux = ((joc) -> child);
		} else {

			arbore3 *t = (joc) -> child -> next;
			if (t != NULL)
				t -> prev = NULL;
			free(aux -> vector);
			free(aux);
			((joc) -> child) = t;
			aux = ((joc) -> child);
		}
	}
}
void citire_fisier_task2(FILE *test, FILE *result)
{
	arbore2 *joc;
	int inaltime;
	fscanf(test, "%d\n", &inaltime);
	constructie2(&joc, test, inaltime);
	minimax(joc, inaltime);
	afisare(joc, result);
	free_task2(joc);
	free(joc);
}
void citire_fisier_task3(FILE *test, FILE *result)
{
	arbore2 *joc;
	int inaltime;
	fscanf(test, "%d\n", &inaltime);
	constructie2(&joc, test, inaltime);
	joc -> alfa = -1000000;
	joc -> beta = 1000000;
	alpha(joc);
	afisare(joc, result);
	free_task2(joc);
	free(joc);
}
void citire_fisier_bonus(FILE *test, FILE *result)
{
	arbore3 *joc;
	int inaltime;
	int nr_joc;
	fscanf(test, "%d ", &inaltime);
	fscanf(test, "%d\n", &nr_joc);
	constructie3(&joc, test, nr_joc, inaltime);
	paranoic(joc, inaltime, nr_joc);
	afisare3(joc, nr_joc, result);
	free_bonus(joc);
	free(joc -> vector);
	free(joc);
}
int main(int argc, char ** argv)
{
	FILE *test;
	test = fopen(argv[argc - 2], "r");
	FILE *result = fopen(argv[argc - 1], "w+");
	if (strcmp(argv[1], "-c1") == 0) {
		citire_fisier_task1(test, result);
		fclose(test);
		fclose(result);
	}
	if (strcmp(argv[1], "-c2") == 0) {
		citire_fisier_task2(test, result);
		fclose(test);
		fclose(result);
	}
	if (strcmp(argv[1], "-c3") == 0) {
		citire_fisier_task3(test, result);
		fclose(test);
		fclose(result);
	}
	if (strcmp(argv[1], "-b") == 0) {
		citire_fisier_bonus(test, result);
		fclose(test);
		fclose(result);
	}
}