#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListaStudentow {
    struct ListaStudentow* nastepnyElement;
    int wartosc;
    char imie[20];
    char nazwisko[20];
};

void dodaj(struct ListaStudentow** lista, int wartosc, char imie[], char nazwisko[]) {
    struct ListaStudentow * nowyElement =
            (struct ListaStudentow*)malloc(sizeof(struct ListaStudentow));
    nowyElement->wartosc = wartosc;
    for(int i=0; i< strlen(imie); i++) {
        nowyElement->imie[i] = imie[i];
    }
    for(int i=0; i< strlen(nazwisko); i++) {
        nowyElement->nazwisko[i] = nazwisko[i];
    }
    if(*lista == 0) {
        nowyElement->nastepnyElement = 0;
    } else {
        nowyElement->nastepnyElement = *lista;
    }

    *lista = nowyElement;
}

void pobierzZLewej(struct ListaStudentow** lista) {
    if(*lista == 0) {
        printf("Lista pusta ...\n");
    } else {
        int wartoscDoZwrotu = (*lista)->wartosc;
        printf("Numer indexu: %d\nImie: %s\nNazwisko: %s\n", wartoscDoZwrotu, (*lista)->imie, (*lista)->nazwisko);
    }
}

void pobierz(struct ListaStudentow** lista, int szukana) {
    if(*lista == 0) {
        printf("Lista pusta ...\n");
    } else {
        struct ListaStudentow* tmp = *lista;
        int wartoscDoZwrotu = 0;
        while(wartoscDoZwrotu == szukana) {
            *lista = tmp->nastepnyElement;
            wartoscDoZwrotu = (*lista)->wartosc;
        }

        printf("Numer indexu: %d\nImie: %s\nNazwisko: %s\n", wartoscDoZwrotu, (*lista)->imie, (*lista)->nazwisko);
    }
}

int main(int argc, char *argv[]) {
    struct ListaStudentow * lista = 0;
    int c,id;
    char im[20], nz[20];
    while(1) {
        printf("Co chcesz zrobic:\n1 - Dodac studenta\n2 - Wyswietlic dane ostatniego studenta\n0 - zakonczyc program\n");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Podaj numer indeksu studenta: ");
                scanf("%d", &id);
                printf("Podaj imie studenta: ");
                scanf("%s", &im);
                printf("Podaj nazwisko studenta: ");
                scanf("%s", &nz);
                dodaj(&lista, id, im, nz);
                break;
            case 2:
                pobierzZLewej(&lista);
                break;
            case 3:
                pobierz(&lista, 2);
                break;
            case 0:
                return 0;
            default:
                printf("BLAD\n");
                break;
        }
    }
}