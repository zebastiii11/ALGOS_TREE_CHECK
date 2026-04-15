//
// Created by Sebastian Matuszyk on 15.04.26.
//

#ifndef PROGRAMM_TREE_H
#define PROGRAMM_TREE_H

// Knoten Aufbau
typedef struct Node {
    int number;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_new_node(int number);     // neuer Knoten
Node *insert_value(Node *root, int number);     // Data einfügen
Node *read_tree_from_file(const char *filename);
void free_tree(Node *root);
void print_tree(Node *root);

#endif //PROGRAMM_TREE_H