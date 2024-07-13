#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node node;
struct node {
    int data;
    node* next;
};

typedef struct element element;
struct element {
    node* first;
};

element* initialisation() {
    element* element = malloc(sizeof(*element));
    node* init = malloc(sizeof(*init));

    if(element == NULL || init == NULL) {
        exit(EXIT_FAILURE);
    }
    init->data = 0;
    init->next = NULL;
    element->first = init;

    return element ;
}

void insertValue(element* head, const int data) {
    node* nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL || head == NULL) {
        exit(EXIT_FAILURE);
    }
    nouveau->data = data;
    nouveau->next = head->first;
    head->first = nouveau;
}

void deleteValue(element* head,const int data) {
    node *current = head->first,*q1 = head->first;

    while(current != NULL) {
        if(current->data == data) {
            if(current == head->first) {
                head->first = current->next;
                free(current);
                current = head->first;
            }
            else {
                q1->next = current->next;
                free(current);
                current = q1->next;
            }
        }
        else {
            q1 = current;
            current = current->next;
        }
    }
}

void printList(const element* head) {
    node* current = head->first;

    while(current != NULL) {
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteList(element* head) {
    node *current = head->first,*q = current->next;
    while(current != NULL) {
        q = current->next;
        free(current);
        current = q;
    }
    head->first = NULL;
}

int verif(const element* head) {
    if(head->first == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    element *liste = initialisation();
    printf("bienvenue dans le programme qui efface les valeurs recurrente d'une liste!\n");
    int nbr = 0,occurence = 0, verification = -1;
    printf("\n entrez le nombre d'element de la liste :  ");
    scanf("%d",&nbr);

    for(int i=0;i<nbr;i++) {
        int value = 0;
        printf("\n entrez la valeur numero %d :  ",i+1);
        scanf("%d",&value);
        insertValue(liste,value);
    }

    printf("\n les valeurs ont bien ete ajoutes a la liste\n");
    printList(liste);

    printf("entrez une valeur pour que toutes ces occurences soient supprimees\n");
    scanf("%d",&occurence);
    printf("la valeur dont toutes les occurences seront supprimee est %d \n",occurence);

    deleteValue(liste,occurence);

    printf("affichage de la liste apres la suppression \n");
    printList(liste);
    printf("suppresion de la liste...\n");
    deleteList(liste);
    verification = verif(liste);

    if(verification == 1) {
        printf("la liste a bien ete supprimee!\n");
    }
    else {
        printf("la suppression a echouee\n");
    }
    return 0;
}
