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

int wyszukajZListy(struct ListaStudentow** lista, int liczbaPoszukiwana) {
    if(*lista == 0) {
        printf("Lista pusta...\n");
        return -1;
    } else {
        struct ListaStudentow* worm = *lista;

        while(worm != 0) {
            if(worm->wartosc == liczbaPoszukiwana) {
                printf("Numer indexu: %d\nImie: %s\nNazwisko: %s\n", worm->wartosc, worm->imie, worm->nazwisko);
                return 1;
            }
            worm = worm->nastepnyElement;
        }
        printf("Brak szukanego studenta\n");
        return 0;

    }
}

int usun(struct ListaStudentow ** lista, int wartosc) {
    struct ListaStudentow *previous, *current;

    if (*lista == NULL) {
        return -1;
    }

    if ((*lista)->wartosc == wartosc) {
        struct ListaStudentow* tmp = *lista;
        *lista = tmp->nastepnyElement;
        free(tmp);
        return 1;
    }

    previous = *lista;
    current = (*lista)->nastepnyElement;
    while (current) {
        if (current->wartosc == wartosc) {
            previous->nastepnyElement = current->nastepnyElement;
            free(current);
            return wartosc;
        }

        previous = current;
        current  = current->nastepnyElement;
    }
    return -1;
}


int main(int argc, char *argv[]) {
    struct ListaStudentow * lista = 0;
    int c,id,ids;
    char im[20], nz[20];
    dodaj(&lista, 1, "aa", "aa");
    dodaj(&lista, 2, "bb", "bb");
    dodaj(&lista, 3, "cc", "cc");
    while(1) {
        printf("Co chcesz zrobic:"
               "\n1 - Dodac studenta\n"
               "2 - Wyswietlic dane ostatniego studenta\n"
               "3 - Wyszukac studenta po indeksie\n"
               "4 - Usunac studenta o danym indeksie\n"
               "0 - zakonczyc program\n");
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
                printf("Podaj numer indeksu studenta ktorego poszukujesz: ");
                scanf("%d", &ids);
                wyszukajZListy(&lista, ids);
                break;
            case 4:
                printf("Studenta o jakim indeksie chcesz usunac: ");
                scanf("%d", &ids);
                usun(&lista, ids);
                break;
            case 0:
                return 0;
            default:
                printf("BLAD\n");
                break;
        }
    }
}