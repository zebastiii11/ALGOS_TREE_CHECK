#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {    // Wie viele Dinge und Liste der Dinge übergeben

    Node *root;

    root = read_tree_from_file("../test.txt");

    // Falls Datei nicht gelesen werden konnte
    if (root == NULL) {
        printf("Baum konnte nicht erstellt werden.\n");
        return 1;
    }
    print_tree(root);


    // root ist die Wurzel des fertigen Baums

    free_tree(root);

    return 0;
}