#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {    // Wie viele Dinge und Liste der Dinge übergeben

    Node *root;

    root = read_tree_from_file("../test.txt");
    int isAVLTree = 1;
    int isFirstNumber = 1;
    int minValue = 0;
    int maxValue = 0;
    int sum = 0;
    int count = 0;

    // Falls Datei nicht gelesen werden konnte
    if (root == NULL) {
        printf("Baum konnte nicht erstellt werden.\n");
        return 1;
    }
    print_tree(root,&isAVLTree,&isFirstNumber, &minValue, &maxValue, &sum, &count);



    // root ist die Wurzel des fertigen Baums

    free_tree(root);

    if(isAVLTree){
        printf("AVL: yes \n");
    }else{
        printf("AVL: no \n");
    }
    printf("min: %d, max: %d, avg: %.1f",minValue, maxValue, (float)sum/count);

    return 0;
}
