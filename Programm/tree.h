//
// Created by Sebastian Matuszyk on 15.04.26.
//

#ifndef PROGRAMM_TREE_H
#define PROGRAMM_TREE_H

typedef struct Node {
    int number;
    struct Node *right;
    struct Node *left;
} Node;

Node *create_node(int key);     // neuer Knoten
Node *insert_node(Node *root, int key);     // Wurzel einfügen
Node *read_tree_from_file(const char *filename);
void free_tree(Node *root);

#endif //PROGRAMM_TREE_H