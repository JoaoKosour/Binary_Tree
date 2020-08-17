//B TREE IMPLEMENTATION BY JOAO KOSOUR, FEEL FREE TO USE AS WILL :)

#include <stdlib.h>
#include <stdio.h>

#define ERROR 0
#define SUCCESS 1   

typedef struct node {
    int id;
    struct node *left, *right;
} NODE;

typedef struct root {
    NODE *root;
    int size;
}ROOT;


/*******************************************************
*                                                      *
*                   S E A R C H                        *
*                                                      *
********************************************************/
void binary_search_call(ROOT *root, int key) {
    if(!root) return ERROR;
    return binary_search(root->root, key);
}

int binary_search(NODE *node, int key) {
    if(!node) return ERROR;

    if(node->key == key) return SUCCESS;
    else if(key > node->key)
            return binary_search(node->right, key);
    else if(key < node->key)
            return binary_search(node->left, key);
    return ERROR;
}


/*******************************************************
*                                                      *
*               I N S E R T I O N                      *
*                                                      *
********************************************************/
NODE *create_new_binary_tree_node(int key){
    NODE *new_node = calloc(1, sizeof(NODE));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; 
}

void binary_tree_insertion(ROOT *root, int key){
    if(!root){
        printf("Missing root, no node inserted");
        return NULL;
    } 

    NODE *new_node = create_new_binary_tree_node(key);

    NODE *aux = root->root;

    while(aux){
        if(aux == NULL){
            aux = new_node;
            break;
        }
        if(key == aux->key) break;
        if(key > aux->key) aux = aux->right;
        else if(key < aux->key) aux = aux->right;
    }
}
