#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int count, char *files[]) {    // Wie viele Dinge und Liste der Dinge übergeben

    Node *root;

    // Prüfen ob Dateiname übergeben wurde
    if (count != 2) {   // müssen zwei sein
        printf("Verwendung: %s filename\n", files[0]);
        return 1;
    }

    // Baum erstellen
    root = read_tree_from_file(files[1]);

    // Falls Datei nicht gelesen werden konnte
    if (root == NULL) {
        printf("Baum konnte nicht erstellt werden.\n");
        return 1;
    }


    // root ist die Wurzel des fertigen Baums

    free_tree(root);

    return 0;
}