//
// Created by Sebastian Matuszyk on 15.04.26.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
// Knoten erstellen
Node *create_new_node(int number) {
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) { // Speicher reservieren nicht geklappt
        fprintf(stderr, "Speicher kann nicht reserviert werden \n");
        exit(1);    // Programm beenden komplett
    }

    new_node->number = number;  // Data im Knoten speichern
    new_node->left = NULL;  // noch kein linkes und rechtes Kind am Anfang
    new_node->right = NULL;

    return new_node;
}

// Data hinzufügen
Node *insert_value(Node *root, int number) {
    if (root == NULL) { // Falls noch kein Knoten existiert, dann einen zuerst erstellen
        return create_new_node(number);
    }

    if (number < root->number) {    // Kleinere Werte gehen nach links
        root->left = insert_value(root->left, number);  // ruft sich selbst mit dem linken Kind auf
    } else if (number > root->number) { // größere nach rechts
        root->right = insert_value(root->right, number);
    }

    // Duplikate werden ignoriert

    return root;
}

// Datei einlesen und Baum bauen
Node *read_tree_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");  // Lesemodus
    Node *root = NULL;  // Am Anfang kein Baum da
    int number; // Zahlen gespeichert

    if (file == NULL) { // Fehler beim öffnen der Datei
        fprintf(stderr, "Fehler: Datei '%s' konnte nicht geoeffnet werden.\n", filename);
        return NULL;
    }

    while (fscanf(file, "%d", &number) == 1) {  // solange number eingelesen wird, weiter
        root = insert_value(root, number);
    }

    fclose(file);
    return root;    // Wurzel zurückgeben
}

int checkHeight(Node *root){ //berechnet die Höhe der einzelnen Subtrees rekursiv
    if(root == NULL){
        return 0;
    }
    int leftTreeHeight = checkHeight(root->left);
    int rightTreeHeight = checkHeight(root->right);

    if(leftTreeHeight>rightTreeHeight){
        return 1 + leftTreeHeight;
    }else{
        return 1 + rightTreeHeight;
    }
}

int checkIfBalanced(Node* root){ // gibt den Balance Faktor zurück (Rechter Subtree - Linker Subtree)
    return(checkHeight(root->right) - checkHeight(root->left));
}

// Speicher freigeben
void free_tree(Node *root) {
    if (root == NULL) {
        return;
    }
//zuerst Teilbäume und dann Knoten, sonst geht Zeiger auf Kinder verloren
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(Node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    if(checkIfBalanced(root) > 1 || checkIfBalanced(root) < -1){
            printf("bal(%d) = %d (AVL violation!)\n",root->number,checkIfBalanced(root));
    }else{
            printf("bal(%d) = %d\n",root->number,checkIfBalanced(root));
    }
    print_tree(root->right);
}
